/* fichiers de la bibliothèque standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
/* bibliothèque standard unix */
#include <unistd.h> /* close, read, write */
#include <sys/types.h>
#include <sys/socket.h>
/* spécifique à internet */
#include <arpa/inet.h> /* inet_pton */

#include "sys_utils.h"
#define PORT_QUIZZP 6666

void usage(char *nom_prog)
{
	fprintf(stderr, "Usage: %s addr_ipv4\n"
			"client pour QUIZZP (Quizz Protocol)\n"
			"Exemple: %s 127.0.0.1 \n", nom_prog, nom_prog);
}

/** Essayer de se connecter en TCP à l'adresse IPv4 donnée en argument, au port
 * associé au Quizz Protocol.
 *
 * En cas de succès, retourne le descripteur de fichier associé à la socket
 * d'échange avec le serveur.
 * En cas d'échec, met fin au programme après avoir affiché un message d'erreur
 * sur la sortie standard des erreurs. */
int connection_au_serveur(const char *addr_ipv4);

/** Échanger avec le serveur connecté via la socket sock ainsi que spécifié par
 * le protocole Quizz Protocol, tout en menant les échanges avec l'utilisateur.
 *
 * - Imprimer sur la sortie standard la question et les propositions envoyées
 *   par le serveur
 * - Demander à l'utilisateur un entier entre 1 et le nombre de propositions
 * - Envoyer le numéro de la réponse choisie au serveur
 * - Recevoir le message final du serveur (réponse correcte ou incorrecte)
 * - Dire à l'utilisateur si sa réponse est correcte ou non
 */
void echanger_avec_serveur(int sock);
void echanger_avec_serveur_test(int sock);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		usage(argv[0]);
		return 1;
	}
	int sock = connection_au_serveur(argv[1]);
	echanger_avec_serveur(sock);
	close(sock);
	return 0;
}
/** Essayer de se connecter en TCP à l'adresse IPv4 donnée en argument, au port
 * associé au Quizz Protocol.
 *
 * En cas de succès, retourne le descripteur de fichier associé à la socket
 * d'échange avec le serveur.
 * En cas d'échec, met fin au programme après avoir affiché un message d'erreur
 * sur la sortie standard des erreurs. */
int connection_au_serveur(const char *addr_ipv4)b
{
    // Création de la socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Erreur lors de la création de la socket");
        exit(EXIT_FAILURE);
    }

    // Initialisation de l'adresse du serveur
    struct sockaddr_in sa = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT_QUIZZP) // Assurez-vous que PORT_QUIZZP est bien défini
    };

    /* Conversion de l'adresse IPv4 car une adresse IP sous forme de chaîne de caractères
       (par exemple "192.168.1.100") ne peut pas être utilisée directement dans une structure
       sockaddr_in pour établir une connexion réseau. */
    if (inet_pton(AF_INET, addr_ipv4, &sa.sin_addr) <= 0) {
        perror("Adresse IPv4 invalide");
        close(sock);
        exit(EXIT_FAILURE);
    }

    socklen_t sl = sizeof(sa);
    if (connect(sock, (struct sockaddr *) &sa, sl) < 0) {
        perror("Erreur lors de la connexion");
        close(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

void echanger_avec_serveur(int sock)
{
    /* 1 nombre de propositions */
    uint16_t nb_props;
    exact_read(sock, &nb_props, sizeof(nb_props));
    nb_props = ntohs(nb_props);
    /* 2 énoncé */
    char c;
    while (read(sock, &c, 1) > 0 && c != '\0')
        putchar(c);
    /*putchar() en C sert à afficher un seul caractère sur la sortie standard */
    putchar('\n');
    /* 3 propositions */
    for (uint16_t i = 1; i <= nb_props; ++i) {
        printf("%u. ", i);
        while (read(sock, &c, 1) > 0 && c != '\0')
            putchar(c);
        putchar('\n');
    }
    /* 4 réponse utilisateur */
    uint16_t rep_util = saisir_entre_bornes(1, nb_props) - 1;
    rep_util = htons(rep_util);
    /*uint16_t htons(uint16_t hostshort);
     htons signifie : Host TO Network Short
     Elle convertit un entier 16 bits (un short) de l'ordre des octets de la machine locale (host byte order) vers l’ordre réseau (network byte order).
     -------------------------------------->
     Pourquoi faire ça ?
     Dans les communications réseau (comme TCP/IP), les données doivent suivre un format standard appelé ordre réseau (big-endian).

     Mais :

     Ton ordinateur peut utiliser un autre ordre des octets (souvent little-endian).
     Donc pour être compris sur tous les ordinateurs, il faut convertir les données avant de les envoyer.
     ------------>ex
     uint16_t rep_util = 42;
     uint16_t net_order = htons(rep_util);
     
     Cela convertit 42 en format réseau, prêt à être envoyé sur la socket.

*/
    if (write(sock, &rep_util, sizeof(uint16_t)) < 0) {
        perror("write");
    }
    /* 5 réponse du serveur */
    uint8_t rep_serv;
    read(sock, &rep_serv, sizeof(rep_serv));
    if (rep_serv == 0)
        printf("Désolé, ce n'est pas la bonne réponse.\n");
    else
        printf("Bravo, c'est la bonne réponse !\n");
}





/*-------------------------Cours-----------------------------*/
/*une socket, c’est comme un tunnel entre deux programmes */



/*Quand tu veux te connecter à un serveur :
 L’adresse IP te dit sur quelle machine aller.
 Le port te dit à quel service tu veux parler (comme "port 80 pour un site web", ou "port 22 pour SSH").*/

/* fichiers de la bibliothèque standard */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* bibliothèque standard unix */
#include <unistd.h> /* close, read, write */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/* spécifique à internet */
#include <arpa/inet.h> /* inet_pton */
/* threads */
#include <pthread.h>

#include "sys_utils.h"
#include "question.h"

#define PORT_QUIZZP 6666
#define FICH_QUESTIONS "questionnaire.txt"

/* Pour pouvoir partager les tâches entre différents threads (en fin d'énoncé) */
struct work {
	int socket;
	struct question *q;
};

/** Créer et configure une socket d'écoute TCP sur IPv4 sur le port associé au
 * Quizz Protocol. Retourne le descripteur de fichier de la socket ainsi créée
 * en cas de succès, met fin au programme sinon. */
int init_sock_ecoute();

/** Accepter les demandes de connection entrantes sur la socket d'écoute
 * sock.
 * Retourne le descripteur de fichier de la socket d'échange créée ou -1 en cas
 * d'erreur */
int connection_au_client(int sock);

/** Recevoir l'adresse d'une variable de type struct work convenablement
 * initialisée, puis échanger avec un client en utilisant le champ socket de
 * cette structure pour la question (champ q) de cette strucure.
 * Retourne : toujours NULL. */
void *worker(void *work);

/* Mener tous les échanges avec le client connecté à la socket fd, ainsi que 
 * spécifié dans le Quizz Protocol, avec la question d'adresse q */
void echanger_avec_client(int fd, const struct question *q);
void echanger_avec_client_test(int fd, const struct question *q);

int main(void)
{
	struct banque_questions *bq = init_banque_questions(FICH_QUESTIONS);
	int sock = init_sock_ecoute();
#define MONO 1
	for (;;) {
		/* Version 1 sans threads */
		int se = connection_au_client(sock);
		if (se < 0)
			continue;
		echanger_avec_client(se, question_aleatoire(bq));
		close(se);
		/* Version 2 avec threads */
		/* TODO */
	}
	/* On n'y arrive jamais normalement. */
	close(sock);
	detruire_banque_questions(bq);
	return 0;
}

int init_sock_ecoute()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        perror_exit("socket");
    struct sockaddr_in sa = { .sin_family = AF_INET,
            .sin_port = htons(PORT_QUIZZP),
        .sin_addr = { htonl(INADDR_ANY) } };
    /* Optionnel : faire en sorte de pouvoir réutiliser l'adresse sans
     * attendre après la fin du serveur. */
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
    /* Attacher la socket */
    if (bind(sock, (struct sockaddr *) &sa, sizeof(sa)) < 0) {
        perror("bind");
        exit(2);
    }
    if (listen(sock, 128) < 0) {
        perror("listen");
        return -1;
    }
    return sock;
}

int connection_au_client(int sock)
{
    int s;
    struct sockaddr_in addr_clt;
    socklen_t taille_addr = sizeof(addr_clt);
    /* Appel système bloquant accept */
    s = accept(sock, (struct sockaddr *) &addr_clt, &taille_addr);/*Cette fonction est utilisée par un serveur pour accepter une connexion entrante sur une socket en écoute.*/
    if (s == -1) {
        perror("accept");
    } else {
        char str_addr[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr_clt.sin_addr.s_addr, str_addr, INET_ADDRSTRLEN);
        /*convertir une adresse IP binaire → chaîne lisible
         Quand tu utilises accept() sur un serveur, l'adresse du client (addr_clt.sin_addr) est en format binaire (réseau).
         Pour l’afficher proprement (ex : "192.168.1.42"), il faut la convertir avec inet_ntop() :
         */
        printf("Connection au client %s.\n"
               , str_addr);
    }
    return s;
}
/** Recevoir l'adresse d'une variable de type struct work convenablement
 * initialisée, puis échanger avec un client en utilisant le champ socket de
 * cette structure pour la question (champ q) de cette strucure.
 * Retourne : toujours NULL. */
void *worker(void *work)
{
    
    struct work *w = work;
    echanger_avec_client(w->socket, w->q);
    close(w->socket);
    free(w);
    return NULL;
    
}
/* Mener tous les échanges avec le client connecté à la socket fd, ainsi que
 * spécifié dans le Quizz Protocol, avec la question d'adresse q */
void echanger_avec_client(int fd, const struct question *q)
{

    /* 1. Écriture du nombre de propositions */
    uint16_t nb_props = htons(q->nb_props);
    if (write(fd, &nb_props, sizeof(nb_props)) < 0)
    perror_exit("write");
    /* 2. Écriture de l'énoncé */
    if (write(fd, q->enonce, strlen(q->enonce) + 1) < 0)
    perror_exit("write");
    /* 3. Écriture des propositions */
    for (uint16_t i = 0; i < q->nb_props; ++i)
    if (write(fd, q->propositions[i], strlen(q->propositions[i]) + 1) < 0)
    perror_exit("write");
    /* 4. Lecture bloquante de la réponse du client */
    uint16_t rep_clt;
    if (exact_read(fd, &rep_clt, sizeof(rep_clt)) < 0)
    perror_exit("read");
    /* 5. Envoi de la réponse du serveur */
    rep_clt = ntohs(rep_clt);
    uint8_t bonne_rep = (rep_clt == q->ind_rep);
    if (write(fd, &bonne_rep, 1) < 0)
    perror_exit("write");
    
}


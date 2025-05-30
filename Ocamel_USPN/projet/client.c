/* Yacine LARFI 12308716
Je déclare qu'il s'agit de mon propre travail.
Ce travail a été réalisé intégralement par un être humain. */

#include <unistd.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <poll.h>
#include "buffer/buffer.h"
#include "utils.h"

#define PORT_FREESCORD 4321
#define BUFFER_SIZE 1024

/** se connecter au serveur TCP d'adresse donnée en argument sous forme de
 * chaîne de caractère et au port donné en argument
 * retourne le descripteur de fichier de la socket obtenue ou -1 en cas
 * d'erreur. */
int connect_serveur_tcp(char *adresse, uint16_t port);



int main(int argc, char *argv[])
{	
	if (argc != 2) {
                fprintf(stderr, "Usage: %s <adresse_ip>\n", argv[0]);
                return EXIT_FAILURE;
        }

        char *adresse_ip = argv[1];

        int sock = connect_serveur_tcp(adresse_ip, PORT_FREESCORD);
        if (sock < 0) {
                fprintf(stderr, "Échec de connexion au serveur\n");
                return EXIT_FAILURE;
        }

        printf("Connecté au serveur %s:%d\n", adresse_ip, PORT_FREESCORD);

        
        char buff[BUFFER_SIZE];
        
        buffer *buff_sock = buff_create(sock, BUFFER_SIZE);
        if (!buff_sock) {
                fprintf(stderr, "Erreur de création du buffer\n");
                close(sock);
                return EXIT_FAILURE;
        } 

        while (1) {

                printf(">");
                fflush(stdout);

                if (buff_ready(buff_sock)) {
                        /* Une ligne est déjà disponible */
                        char ligne[BUFFER_SIZE];
                        if (buff_fgets_crlf(buff_sock, ligne, BUFFER_SIZE)) {
                                if (crlf_to_lf(ligne)) {
                                printf("Réponse : %s", ligne);
                                }
                        }
                        continue; // éviter d’attendre inutilement dans poll
                }


                struct pollfd fds[2];

                /* 1. Entrée standard */
                fds[0].fd = STDIN_FILENO;
                fds[0].events = POLLIN;

                /* 2. Socket vers le serveur */
                fds[1].fd = sock;
                fds[1].events = POLLIN;

                /* Attendre jusqu'à ce que l'un des deux soit prêt */
                int ret = poll(fds, 2, -1); /* -1 = attente infinie */
                if (ret < 0) {
                        perror("poll");
                        break;
                }

                if(fds[0].revents & POLLIN){

                        /* Lire une ligne du terminal*/
                        if (fgets(buff, BUFFER_SIZE, stdin) == NULL) {
                                break; /* fin de fichier (Ctrl+D) ou erreur */
                        }

                        
                        /* Envoyer au serveur */
                        if (lf_to_crlf(buff)) {
                                size_t len = strlen(buff);
                                if (write(sock, buff, len) != len) {
                                        perror("write");
                                        break;
                                }
                        }

                }


                if(fds[1].revents & POLLIN) {

                        char ligne[BUFFER_SIZE];

                        if (buff_fgets_crlf(buff_sock, ligne, BUFFER_SIZE)) {
                                if (crlf_to_lf(ligne)) {
                                        printf("Réponse : %s", ligne);
                                }
                        } else {
                                if (buff_eof(buff_sock)) {
                                        printf("Serveur a fermé la connexion.\n");
                                } else {
                                        perror("Erreur lecture socket");
                                }
                                break;
                        }

                }
        }

        close(sock);
        buff_free(buff_sock);
	return 0;
}



int connect_serveur_tcp(char *adresse, uint16_t port)
{	
	int sock;

        /* 1. Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
                perror("socket");
                return -1;
        }

        /*  2. Préparation de l'adresse du serveur */
        struct sockaddr_in sa ={
                .sin_family = AF_INET,
                .sin_port = htons(port),
        };        

        if (inet_pton(AF_INET, adresse, &sa.sin_addr) != 1) {
                fprintf(stderr, "Adresse IP invalide : %s\n", adresse);
                close(sock);
                return -1;
        }


        socklen_t sl = sizeof(struct sockaddr_in);

        /* 3. Connexion au serveur */
        if (connect(sock, (struct sockaddr *)&sa, sl) < 0) {
                perror("connect");
                close(sock);
                
                return -1;
        }


        return sock;

}

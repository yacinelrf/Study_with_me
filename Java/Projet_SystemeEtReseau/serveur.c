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
#include "list/list.h"
#include "user.h"

#define PORT_FREESCORD 4321
#define BUFFER_SIZE 1024

int tube[2];

struct list * clts;

pthread_mutex_t mutex_clts;

/** Gérer toutes les communications avec le client renseigné dans
 * user, qui doit être l'adresse d'une struct user */
void *handle_client(void *user);
/** Créer et configurer une socket d'écoute sur le port donné en argument
 * retourne le descripteur de cette socket, ou -1 en cas d'erreur */
int create_listening_sock(uint16_t port);

void *repeter(void *arg);


int main(int argc, char *argv[])
{

        int server_sock = create_listening_sock(PORT_FREESCORD);
        if (server_sock < 0) {
                perror("create_listening_sock");
                return 1;
        }

        if (pipe(tube) == -1) {
                perror("pipe");
                return 1;
        }

        pthread_mutex_init(&mutex_clts, NULL);

        pthread_t repeteur;
        if(pthread_create(&repeteur, NULL, repeter, NULL)!=0){
                perror("create repeteur");
                return 1;
        }

        pthread_detach(repeteur);

        clts = list_create();

        while (1) {

                struct user * clt = user_accept(server_sock);

                pthread_mutex_lock(&mutex_clts);
                clts = list_add(clts, clt);
                pthread_mutex_unlock(&mutex_clts);

                printf("Un client s'est connecté.\n");

                pthread_t pclt;
                if (pthread_create(&pclt, NULL, handle_client, clt) != 0) {
                        perror("pthread_create");
                        user_free(clt); 
                        continue;
                }

                pthread_detach(pclt);

        }

        pthread_mutex_destroy(&mutex_clts);

        return 0;
}


void *handle_client(void *clt)
{       
        struct user * client = clt;

        /* Lire et renvoyer les données */
        char buffer[BUFFER_SIZE];
        ssize_t n;
        while((n = read(client->sock, buffer, BUFFER_SIZE))>0){
                write(tube[1], buffer, n);    /* c) Echo : renvoie ce qu'on reçoit */
        }

        if (n == 0) {
                printf("Un client a fermé la connexion.\n");
        } else {
                perror("read");
        }

        /* Fermer la connexion avec ce client */
        user_free(clt);
	return NULL;

}


void *repeter(void *arg){

        char buffer[BUFFER_SIZE];
        ssize_t n;

        while(1){

                n = read(tube[0], buffer, BUFFER_SIZE);
                if (n == 0) {
                        break;
                }
                if (n < 0) {
                        perror("read repeteur");
                        break;
                }

                pthread_mutex_lock(&mutex_clts);
                for(int i=0; i<clts->length; i++){
                        struct user *clt = list_get(clts, i);
                        ssize_t ecrit = write(clt->sock, buffer, n);
                        if(ecrit<0){
                                perror("write repeter");
                        }
                }
                pthread_mutex_unlock(&mutex_clts);

        }

        return NULL;
}


int create_listening_sock(uint16_t port)
{
	int sock;

        // 1. Créer la socket (IPv4, TCP, protocole par défaut)
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
                perror("socket");
                return -1;
        }

        // 3. Préparer l'adresse de la socket
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY); /* accepter toute interface réseau */
        addr.sin_port = htons(port);

        /* Optionnel : faire en sorte de pouvoir réutiliser l'adresse sans
        * attendre après la fin du serveur. */
        int opt = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));


        /* 4. Associer l'adresse à la socket */
        if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
                perror("bind");
                close(sock);
                return -1;
        }

        /* 5. Placer la socket en mode écoute */
        if (listen(sock, 100) < 0) {
                perror("listen");
                close(sock);
                return -1;
        }
 
        return sock;
}

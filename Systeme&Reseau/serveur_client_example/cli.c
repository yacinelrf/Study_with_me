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
#define PORT_QUIZZP 6666




int main(int argc, char *argv[]){
    //crer la socket
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("socket");
        exit(1);
    }
    /*connexion au serveur*/
    struct sockaddr_in server_adress={
        .sin_family=AF_INET,
        .sin_port=htons(PORT_QUIZZP),
    };
    
    
    
    if(inet_pton(AF_INET,argv[1],&server_adress.sin_addr)<0){
        perror("ip");
        exit(1);
        }
    
    if(connect(sock,(const struct sockaddr*) &server_adress,sizeof(server_adress))<0){
        perror("connect");
        exit(1);
    }
    
    char buf[60]="hello";
    write(sock, buf, strlen(buf) + 1);
    
    
    char rep[60]={0};
    read(sock, rep, sizeof(rep) - 1);
    printf("le serveur a repondu %s\n",rep);
    return 0;
}

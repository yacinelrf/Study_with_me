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
    int sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("socket");
        exit(1);
    }
    
    //se connecter au client
    struct sockaddr_in server_adress={
        .sin_family=AF_INET, //ici c'est ',' et pas ';'
        .sin_port=htons(PORT_QUIZZP),
        .sin_addr.s_addr = htonl(INADDR_ANY)
        
    };

    socklen_t server_len = sizeof(server_adress);
    if(bind(sock, (const struct sockaddr*) &server_adress, server_len)<0){
        perror("bind");
        exit(1);
    }
    
    if(listen(sock, 128)){
        perror("listen");
        exit(1);
    }
    
    struct sockaddr_in client_adress;
    socklen_t client_len = sizeof(client_adress);
    int client_fd=accept(sock, (struct sockaddr *)&client_adress,&client_len );/*on prend l'adresse de client_len et ne fait jamais sizeof() car ca retourne un int pas un sockaddr_in*/
    if(client_fd<0){
        perror("accept");
        exit(1);
    }
    
    char buf[60]={0};
    read(client_fd,buf,sizeof(buf) - 1);
    printf("le client a dit %s\n",buf);
    
    
    char rep[4]="lol";// on declare pas les buffer sans taille --> char *buf xxxx ->>>char buf[60]
    write(client_fd,rep,strlen(rep)+1);
    
    
    
    
    return 0;
    
}

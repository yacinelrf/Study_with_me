// udp_server.c
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serv = {AF_INET, htons(12345), INADDR_ANY};
    bind(sock, (struct sockaddr*)&serv, sizeof(serv));
    char buf[100];
    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr*)&client, &len);
    printf("Reçu : %s\n", buf);
    
    sendto(sock, "OK", 2, 0, (struct sockaddr*)&client, len);
    close(sock);
}


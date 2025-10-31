
// udp_client.c
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in serv = {AF_INET, htons(12345)};
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);
    /* "Internet Presentation to Numeric" convertit une représentation
    * d'adresse IP (v4 ou v6) sous forme de chaîne de caractères (ex : "127.0.0.1") en numérique (gros-boutiste) */
    sendto(sock, "Bonjour", 7, 0, (struct sockaddr*)&serv, sizeof(serv));

    char buf[100];
    recvfrom(sock, buf, sizeof(buf), 0, NULL, NULL);
    printf("Réponse : %s\n", buf);
    close(sock);
}
//udp / tcp on utilise des gros boutiste donc on doit convertir manuellement avec htons (short )htonl (host to long)
/*ex:
 uint16_t port = 12345;
 uint16_t net_port = htons(port); // pour l'envoyer sur le réseau
*/


/*
 Serveur vs Client — qui doit connaître quoi ?
 | Rôle          | Doit connaître                                                             |
 | ------------- | -------------------------------------------------------------------------- |
 | **Client** ✅  | L’**adresse IP** et le **port** du **serveur** 🛰️ (obligatoire)           |
 | **Serveur** ✅ | **Rien à l’avance** sur le client ! Il attend une connexion ou un message. |

 */

/*
 L’adresse IP = l’adresse de la machine sur le réseau
 Elle identifie où se trouve un ordinateur (comme une adresse postale).
 Exemples :
 127.0.0.1 → localhost (ta propre machine)
 192.168.1.10 → une machine sur ton réseau local
 8.8.8.8 → Google DNS sur Internet
 
 
 
 
 
 
 Le port = la boîte aux lettres sur cette machine
 Chaque machine peut faire plusieurs choses en même temps :
 Un serveur web sur le port 80
 Un serveur SSH sur le port 22
 Une appli personnalisée sur le port 12345
 Le port identifie le bon programme à qui livrer le message.
 */

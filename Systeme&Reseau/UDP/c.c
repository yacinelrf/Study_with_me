/** Essayer de se connecter en TCP à un serveur de nom name au service service
* name et service sont des chaînes terminées par un'\0'
* name contient un nom de domaine
* service peut contenir un numéro de port en décimal ou le nom d'un service comme http */
int create_connected_sock(char *name, char *service){
    struct addrinfo *hints={0};
    struct addrinfo res;
    int stat=getaddrinfo(name,service,hints,*res);
    if((int x=getaddrinfo(name,service,hints,*res))<0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(stat));
        exit(1);

    }
    struct addrinfo *iter;
    while (iter!=NULL) {
        int sock=socket(iter->ai_family,iter->ai_socktype,iter->ai_protocol);
        if(sock<0){
            perror("socket");
            continue;/*XXXXXXXXX------>>>exit(1);*/
        }
        if(connect(sock,(struct sockaddr *) iter.ai_addr,*iter.ai_addrlen)==0){
            break;
        }
        iter=iter->ai_next;
        close(sock);
        sock=-1;
    }
    freeaddrinfo(res);
    return sock;
    
}

dprintf(sock, "GET %s HTTP/1.1\r\n", ressource);
dprintf(sock, "Host: %s\r\n\r\n", nom); /*le premier CRLF est pour le host le deuxiemme est pour la ligne vide qui met fin a la requette */



/** Lire dans le fichier de descripteur fd, jusqu'aux deux caractères "\r\n"
* compris. La lecture se fait octet par octet pour des raisons de simplicité
* Retourne un pointeur vers une chaîne dynamiquement allouée contenant la ligne
* et terminée par un'\0'; cette ligne doit être libérée par la suite avec free
* En cas d'erreur, ou si la fin du fichier a été rencontrée, retourne NULL */
char *read_until_crlf(int fd){
    char *buf=sizeof(128);
    ssize_t n;
    int tot=0;
    do{
        n=read(fd,buf+tot,1);
        tot++;
        if(tot>sizeof(buf)){
            realloc(buf,2*sizeof(buf));
        }
    }while(n>0 && buf[tot-1]!='\r' && buf[tot]!='\n');
    if(n==0){
        free(buf);
        
    }
    buf[tot+1]='\0';
}


char *read_until_crlf(int fd)
{
    size_t res_sz = 128;
    tot = 0;
    char *res = malloc(res_sz);
    ssize_t n;
    
    
    
    
    do {
        n = read(fd, res + tot, 1);
        if (n <= 0) {
            free(res);
            return NULL;
        }
        tot += n;
        if (tot == res_sz - 1) {
            res_sz *= 2;
            res = realloc(res, res_sz);
        }
    } while (tot < 2 || res[tot - 2] != '\r' || res[tot - 1] != '\n');
    /*on boucle lorsqu'on a lu moins de 2 oct ou  res[tot - 2] != '\r' ou res[tot - 1] != '\n' */
    
    res[tot] = '\0';
    return res;
}

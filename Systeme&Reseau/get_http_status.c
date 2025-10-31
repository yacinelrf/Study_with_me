/** Lire la première ligne de la réponse du serveur à une requête HTTP depuis
* le descripteur de fichier fd.
* Si le serveur signale un échec, le code et le message d'erreur correspondants
* sont écrits sur la sortie des erreurs.
* Retourne 0 en cas de succès, le code d'erreur correspondant en cas d'échec */
int get_http_status(int fd)
{
    char *line = read_until_crlf(fd);
    line[strlen(line) - 2] = '\0';
    char httpvers[16];
    char errcode[4];
    sscanf(line, "%s %s", httpvers, errcode);/*lire a partir de ligne deux chaines de caracteres separee par un espace "%s %s" la premiere la mettre dans httpvers et lautre dans errcode */
    int stat = atoi(errcode);
    if (stat != 200) {
        fprintf(stderr, "%s\n", strstr(line, errcode));
        /*
         strstr(line, errcode)--> Cherche la première occurrence de la chaîne errcode dans la chaîne line
         
         
         Exemple :

         line = "HTTP/1.1 404 Not Found"
         errcode = "404"
         strstr(line, errcode) renverra un pointeur vers la sous-chaîne "404 Not Found" dans line.
         
         
         
         fprintf(stderr, "%s\n", ...)->>>>>>Affiche la chaîne obtenue (strstr(line, errcode)) sur la sortie d’erreur standard (stderr) ++++ Ajoute un saut de ligne (\n) à la fin
         */
    } else {
        stat = 0;
    }
    return stat;
}


int getchar(void);
int putchar(int c);
int printf(const char *format, ...);
int fprintf(FILE *flux, const char *format, ...);
int dprintf(int fd, const char *format, ...);
int sprintf(char *chaîne, const char *format, ...);
int sscanf(const char *str, const char *restrict format, ...);
//toutes ces fonctions lisent jusqu'a '\0'



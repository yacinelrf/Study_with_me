
/** Demander à l'utilisateur un nom d'utilisateur et un mot de passe pour
* s'identifier au serveur ftp et les transmettre au serveur par la socket
* de commandes sock_cmd.
* Précondition : sock_cmd est une socket d'échange de commandes connectée à un
* serveur ftp.
* Les réponses du serveur sont affichée sur la sortie standard des erreurs.
* Retourne : 0 en cas de succès, -1 en cas d'erreur. */
int log_in(int sock_cmd)
{
    char buf[1024];
    printf("Nom d'utilisateur : ");
    scanf("%s", buf);
    
    
    
    dprintf(sock_cmd, "USER %s\r\n", buf);/* Comme printf, mais écrit directement dans un descripteur de fichier*/
    
    /*si on veut avec write -->
     
     sprintf(temp, "USER %s\r\n", buf);
     write(sock_cmd, temp, strlen(temp));
     
     
     car
     dprintf() envaoi directement USER yacine\r\n
     write() on doi ajouter USER a noutre scanf avec sprintf
*/
    
    if (lire_reponse_serveur(sock_cmd, buf, BUFL) != 3)
        return -1;
    printf("Mot de passe : ");
    scanf("%s", buf);
    dprintf(sock_cmd, "PASS %s\r\n"
            , buf);
    if (lire_reponse_serveur(sock_cmd, buf, BUFL) != 2)
        return -1;
    return 0;
}

/*
 remarques :
 printf = print formatted (affiche formaté sur la sortie standard)
 sprintf = string print formatted (écrit dans une chaîne de caractères)
 dprintf = descriptor print formatted (écrit dans un descripteur de fichier)
 */

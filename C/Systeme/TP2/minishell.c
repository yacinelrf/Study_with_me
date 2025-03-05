#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#define MAXLIGNE 1024
#define PROMPT "$ "


int main(void)
{
    char ligne[MAXLIGNE];
    printf(PROMPT);
    while (fgets(ligne, MAXLIGNE, stdin)) { /*stdin (entrée standard)*/
        /* remplacer \n par \0 */
        ligne[strlen(ligne) - 1] = '\0';
        switch(fork()) {
            case -1:
                perror("fork");
                return 1;
            case 0:
                execlp(ligne, ligne, NULL);
                fprintf(stderr, "Erreur : ne peut exécuter %s\n", ligne);
                        return 1;
                        
            default:
                wait(NULL);
                printf(PROMPT);
        }
    }
    printf("\n");
    return 0;
}

/*char *fgets(char *str, int size, FILE *stream);
 str : Un pointeur vers un tableau de char où sera stockée la ligne lue.
 size : La taille maximale à lire (y compris le \0 final).
 stream : Le flux à partir duquel lire (stdin, fichier, etc.).
 */


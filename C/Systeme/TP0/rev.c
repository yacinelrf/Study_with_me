#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#define LG_LIGNE_INIT 80

int main(void)
    {
        int c, i;
        char *ligne;
        int taille_courante = 0;
        int taille_max = LG_LIGNE_INIT;
        
        ligne = malloc(LG_LIGNE_INIT);
        
        if (ligne == NULL) {
            perror("malloc initial");
            return 2;
        }
        
        do {
            
            c = getchar();
            
            if (c == '\n' || c == EOF) {
                for (i = taille_courante - 1; i >= 0; --i) putchar(ligne[i]);
                if (c == '\n') putchar('\n');
                taille_courante = 0;
                continue;
            }
            
            if (taille_courante == taille_max) {
                taille_max *= 2;
                if ((ligne = realloc(ligne, taille_max)) == NULL) {
                    perror("realloc");
                    return 2;
                }
            }
            ligne[taille_courante++] = c;
        } while (c != EOF);
        fprintf(stderr, "taille_max à la fin du programme : %d\n", taille_max);
        free(ligne);
        return 0;
        
    }


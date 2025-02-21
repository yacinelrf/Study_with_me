#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) { // Parcourt les arguments à partir de argv[1]
        char *arg = argv[i];
        
        // Affiche chaque caractère de l'argument courant
        while (*arg) {
            putchar(*arg);
            arg++;
        }

        // Ajoute un espace après chaque argument sauf le dernier
        if (i < argc - 1) {
            putchar(' ');
        }
    }

    // Ajoute un saut de ligne à la fin
    putchar('\n');
    return 0;
}

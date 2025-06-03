#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"
#include <unistd.h>

#define BUFSIZE 1024

int main() {
        
    buffer *b = buff_create(STDIN_FILENO, BUFSIZE);
    if (!b) {
        perror("Erreur lors de la création du buffer");
        return EXIT_FAILURE;
    }

    char line[BUFSIZE];

    printf("Entrez du texte (Ctrl+D pour finir) :\n");

    while (buff_fgets(b, line, BUFSIZE)) {
        printf(">> %s", line); // Affiche la ligne lue
    }

    buff_free(b);
    return EXIT_SUCCESS;
}
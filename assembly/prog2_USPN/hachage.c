#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101  // Define a prime number as the hash table size
#define ENTREE "input.txt"  // Replace with the actual input file name

void insert_string(char *s, struct liste *tab[], int *collisions);
void usage_hachage(char *);
unsigned hash(char *);

int main(int argc, char **argv) {
    FILE *flot;
    char mot[30];
    int i, collisions = 0;

    struct liste *tab[N];
    for (i = 0; i < N; ++i) {
        tab[i] = nouvelle_liste();
    }

    if (argc != 2) {
        printf("Nombre d'arguments erroné. Recommencez ! \n");
        usage_hachage(argv[0]);
        return EXIT_FAILURE;
    }

    if ((flot = fopen(argv[1], "r")) != NULL) {
        while (fscanf(flot, "%s", mot) == 1) {
            // Process only alphabetic words
            int len = strlen(mot);
            while (len > 0 && !((mot[len - 1] >= 'A' && mot[len - 1] <= 'Z') || (mot[len - 1] >= 'a' && mot[len - 1] <= 'z'))) {
                mot[--len] = '\0';
            }
            if (len > 0) {
                insert_string(mot, tab, &collisions);
            }
        }
        fclose(flot);
    } else {
        printf("Erreur lors de l'ouverture du fichier %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    printf("Nombre total de collisions : %d\n", collisions);

    // Optionally, display the hash table contents
    for (i = 0; i < N; ++i) {
        printf("Index %d: ", i);
        afficher_liste(tab[i]);
    }

    return EXIT_SUCCESS;
}

void usage_hachage(char *s) {
    printf("Usage: %s <nom_du_fichier>\n", s);
    printf("Ce programme hache les mots d'un fichier et calcule les collisions.\n");
}

/** Fonction de hachage djb2 due à Dan Bernstein */
unsigned hash(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    }
    return hash % N;
}

/** Insère un mot dans la table de hachage avec chaînage séparé */
void insert_string(char *s, struct liste *tab[], int *collisions) {
    int index = hash(s);

    if (!recherche_liste(tab[index], s)) {
        tab[index] = insere_liste(tab[index], s);
    } else {
        (*collisions)++;
    }
}

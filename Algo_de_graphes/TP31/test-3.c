/**
 * \file test-3.c
 * \brief Représentation des graphes par liste de successeurs : fichier de test
 * \version 1
 * \date lundi 30 septembre 2019, 10:04:11 (UTC+0200)
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
 *
 * fonctions testées :
 * - graphe_get_multiplicite_arc
 * - graphe_get_multiplicite_arete
 * - graphe_get_degre_sortant
 * - graphe_get_degre_entrant
 * - graphe_get_degre
 *
 * utilise les fonctions de manipulation : 
 * - graphe_est_or
 * - graphe_get_n
 * - graphe_get_m
 * - graphe_get_prem_msuc
 * - graphe_ecrire_dot
 * - graphe_stable
 * - graphe_ajouter_arc
 * - graphe_detruire
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe-4.h"

int main() {
    graphe g;
    int n = 5;
    int v, w;
    char *nom_fichier = "oriente.dot";
    char cmd[100] = "dot -Tx11 ";

    graphe_stable(&g, 5, 1);
    graphe_ajouter_arc(&g, 0, 1, 0);
    graphe_ajouter_arc(&g, 0, 1, 0);
    graphe_ajouter_arc(&g, 1, 2, 0);
    graphe_ajouter_arc(&g, 1, 1, 0);
    graphe_ajouter_arc(&g, 3, 0, 0);
    graphe_ajouter_arc(&g, 0, 4, 0);
    graphe_ajouter_arc(&g, 4, 3, 0);
    graphe_ajouter_arc(&g, 4, 2, 0);
    
    puts("Matrice d'adjacence du graphe orienté");
    for (v = 0; v < n; ++v) {
	    for (w = 0; w < n; ++w)
		    printf("%d ", graphe_get_multiplicite_arc(&g, v, w));
	    puts("");
    }

    puts("Matrice d'adjacence du graphe vu comme graphe non orienté");
    for (v = 0; v < n; ++v) {
	    for (w = 0; w < n; ++w)
		    printf("%d ", graphe_get_multiplicite_arete(&g, v, w));
	    puts("");
    }

    puts("Degrés sortants");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre_sortant(&g, v));
    puts(" ");

    puts("Degrés entrants");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre_entrant(&g, v));
    puts(" ");

    puts("Degrés");
    for (v = 0; v < n; ++v)
	    printf("%d ", graphe_get_degre(&g, v));
    puts(" ");

    graphe_ecrire_dot(&g, nom_fichier, 0);
    strcat(cmd, nom_fichier);
    system(cmd);

    graphe_detruire(&g);
    return EXIT_SUCCESS;
}

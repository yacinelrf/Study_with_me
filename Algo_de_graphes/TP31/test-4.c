/**
 * \file test-4.c
 * \brief Représentation des graphes par liste de successeurs : fichier de test
 * \version 1
 * \date lundi 30 septembre 2019, 10:04:11 (UTC+0200)
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
 *
 * fonctions testées :
 * - graphe_get_multiplicite_arete
 * - graphe_get_degre
 *
 * utilise les fonctions de manipulation : 
 * - graphe_est_or
 * - graphe_get_n
 * - graphe_get_m
 * - graphe_get_prem_msuc
 * - graphe_ecrire_dot
 * - graphe_stable
 * - graphe_ajouter_arete
 * - graphe_detruire
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "graphe-4.h"

void test_acceseurs(graphe* g, int is_or);

#define M 8
#define N 5
int main() {
    graphe g;
    
	/* __ graphe non orienté */
    puts("Cas d'un graphe non orienté");
    test_acceseurs(&g, 0);

	/* __ graphe orienté */
    puts("Cas d'un graphe orienté");
    test_acceseurs(&g, 1);

	/* __ fin du programme */
    return EXIT_SUCCESS;
}

void test_acceseurs(graphe* g, int is_or) {
    int paires[M][2] ={{0, 1}, {0, 1}, {1, 2}, {2, 1}, {3, 3}, {0, 4}, {4, 3}, {4, 2}};
	int v, w, e;
    char cmd[100] = "dot -Tx11 ";
    char nom_fichier[100] = "";

	/* __ instanciation du graphe */
	graphe_stable(g, N, is_or);
	for(e =0 ; e < M ; e ++)
		if(is_or)
			graphe_ajouter_arc(g, paires[e][0], paires[e][1], is_or);
		else
			graphe_ajouter_arete(g, paires[e][0], paires[e][1], is_or);

	/* __ utilisation des accesseurs */
    printf("Matrice d'adjacence du graphe%s\n", is_or ? "" : " vu comme graphe non orienté");
    for (v = 0; v < N; ++v) {
	    for (w = 0; w < N; ++w)
		    printf("%d ", graphe_get_multiplicite_arete(g, v, w));
	    puts("");
    }

    puts("Degrés");
    for (v = 0; v < N; ++v)
	    printf("%d ", graphe_get_degre(g, v));
    puts(" ");

	/* __ affichage graphique du graphe */
	sprintf(nom_fichier, "%soriente.dot", is_or ? "" : "non_");
    graphe_ecrire_dot(g, nom_fichier, 0);
    strcat(cmd, nom_fichier);
    system(cmd);

	/* __ destruction du graphe */
    graphe_detruire(g);
}

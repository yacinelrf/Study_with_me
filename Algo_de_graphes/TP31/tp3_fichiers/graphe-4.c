/**
 * \file graphe-4.c
 * \brief Représentation des graphes par liste de successeurs
 * \version 1
 * \date lundi 4 novembre 2019
 * \authors Pierre Rousselin, Antoine Rozenknop, Sophie Toulouse
*/
#include "graphe-4.h"

#include <stdio.h>
#include <stdlib.h>

/* __________________________________ Accesseurs sur les maillons */
msuc *msuc_suivant(msuc *m)
{
	return m->suivant;
}

int msuc_sommet(msuc *m)
{
	return m->sommet;
}

double msuc_valeur(msuc *m)
{
	return m->valeur;
}


/* __________________________________ Initialisation / Destruction */

int graphe_stable(graphe *g, int n, int est_or) {
    if (g==NULL || n < 0) return -1;   /* vérif parametres */
    
    g->n = n;                     /* nombre de sommets */
    g->m = 0;                     /* nombre d'arêtes du graphe */
    g->est_or = est_or ? 1 : 0;   /* orienté si est_or != 0 */

    /* allocation du tableau de listes de successeurs */
    g->tab_sucs = (msuc **) calloc(n, sizeof(msuc *));
    if (g->tab_sucs==NULL) return -1;  /* échec allocation */

    /* calloc met déjà tous les pointeurs à NULL → listes vides */
    return 0;                     /* succès */
}


int graphe_ajouter_arc(graphe *g, int v, int w, double val) {
    if (g == NULL) return -1;  /* graphe invalide */
    if (v < 0 || v >= g->n || w < 0 || w >= g->n) return -1;  /* sommets invalides */

    /* création du nouveau maillon successeur */
    msuc *m = (msuc *) malloc(sizeof(msuc));
    if (m == NULL) return -1;  /* échec allocation */

    m->sommet = w;       /* destination de l’arc */
    m->valeur = val;     /* valeur associée à l’arc */
    m->suivant = g->tab_sucs[v]; /* inséré en tête de la liste */
    g->tab_sucs[v] = m;

    g->m += 1;  /* mise à jour du nombre d’arcs */

    return 0;   /* succès */
}
void graphe_detruire(graphe *g)
{
    if (g==NULL) return;  // Si le graphe est NULL, rien à faire

    // Parcours de chaque sommet
    for (int v = 0; v < g->n; ++v) {
        msuc *m = g->tab_sucs[v];  // Premier maillon de la liste
        // Libération de tous les maillons de la liste
        while (m) {
            msuc *tmp = m;   // Sauvegarde du maillon courant
            m = m->suivant;  // Passage au maillon suivant
            free(tmp);       // Libération du maillon courant
        }
    }

    free(g->tab_sucs);   // Libération du tableau de listes
    g->tab_sucs = NULL;  // Evite un pointeur suspendu
    g->n = 0;            // Remise à zéro du nombre de sommets
    g->m = 0;            // Remise à zéro du nombre d’arêtes/arcs
}


int graphe_ajouter_arete(graphe* g, int v, int w, double val) {
    if (g == NULL) return -1;  /* graphe invalide */
    if (v < 0 || v >= g->n || w < 0 || w >= g->n) return -1;  /* sommets invalides */

    if (graphe_ajouter_arc(g, v, w, val) < 0) return -1;   /* arc v -> w */
    if (v != w) {  /* éviter doublon si boucle */
        if (graphe_ajouter_arc(g, w, v, val) < 0) return -1;  /* arc w -> v */
        g->m--;  /* on ne compte qu’une seule arête pour le graphe non orienté */
    }

    return 0;  /* succès */
}

/* __________________________________ Ajout / Suppression d'arêtes */

/* Attention :
 * Si le graphe est orienté, utiliser les fonctions _arc
 * Si le graphe est non orienté, utiliser les fonction _arete
 */

///*int graphe_ajouter_arc(graphe *g, int v, int w, double val)
//{
//    /* TODO */
//	return -1;
//}

//int graphe_ajouter_arete(graphe* g, int v, int w, double val)
//{
//    if (!g) return -1;
//    if (v < 0 || v >= g->n || w < 0 || w >= g->n) return -1;
//
//    if (graphe_ajouter_arc(g, v, w, val) < 0) return -1;
//    if (v != w) {
//        if (graphe_ajouter_arc(g, w, v, val) < 0) return -1;
//        g->m--; // on ne compte qu’une seule arête pour le graphe non orienté
//    }
//
//    return 0;
//}

int graphe_supprimer_arc(graphe *g, int v, int w, double val)
{
    msuc *m = g->tab_sucs[v];
    msuc *prec = NULL;

    while (m != NULL) {
        if (m->sommet == w && m->valeur == val) {
            // suppression du maillon m
            if (prec == NULL) {
                // cas : premier élément
                g->tab_sucs[v] = m->suivant;
            } else {
                prec->suivant = m->suivant;
            }
            free(m);
            return 0; // succès
        }
        prec = m;
        m = m->suivant;
    }

    return -1; // arc non trouvé
}



int graphe_supprimer_arete(graphe *g, int v, int w, double val)
{
    int res1 = graphe_supprimer_arc(g, v, w, val);
    int res2 = graphe_supprimer_arc(g, w, v, val);

    // Si au moins un des deux arcs a été supprimé
    if (res1 == 0 && res2 == 0)
        return 0;
    else
        return -1;
}


/* ______________________________________ Accesseurs en lecture */
int graphe_est_or(graphe *g)
{
	return g->est_or;
}

int graphe_get_n(graphe* g)
{
	return g->n;
}

int graphe_get_m(graphe* g)
{
	return g->m;
}

msuc *graphe_get_prem_msuc(graphe *g, int v)
{
    if (g == NULL || v < 0 || v >= g->n)
        return NULL;  // graphe invalide ou sommet hors limites

    return g->tab_sucs[v];  // retourne le premier maillon de la liste
}


/* NE PAS ACCÉDER DIRECTEMENT AUX CHAMPS EN-DESSOUS DE CETTE LIGNE */

int graphe_get_multiplicite_arc(graphe* g, int v, int w)
{
    if (g==NULL || v < 0 || v >= g->n || w < 0 || w >= g->n)
        return 0;  // graphe invalide ou sommets hors limites

    int count = 0;
    msuc *m = g->tab_sucs[v];  // premier maillon de la liste des successeurs de v
    while (m!=NULL) {
        if (m->sommet == w)
            count++;           // on a trouvé un arc v -> w
        m = m->suivant;        // passer au maillon suivant
    }
    return count;
}


int graphe_get_multiplicite_arete(graphe* g, int v, int w)
{
    return graphe_get_multiplicite_arc(g,v,w);
}

int graphe_get_degre_sortant(graphe* g, int v)
{
    int count =0;
    msuc *m = g->tab_sucs[v];
    while (m!=NULL){
        count++;
        m=m->suivant;
    }
    
	return count;
}

int graphe_get_degre_entrant(graphe* g, int w)
{
    int count=0;
    for (int i=0; i<g->n; i++) {
        msuc *m = g->tab_sucs[i];
        while (m!=NULL) {
            if (m->sommet==w) count++;
            m=m->suivant;
        }
        
    }
    
    return count;
}

int graphe_get_degre(graphe *g, int v)
{
    if (g->est_or==1) {
        return graphe_get_degre_entrant(g,v)+graphe_get_degre_sortant(g,v);
    }
    return graphe_get_degre_sortant(g, v);
}

/* ______________________________________ Entrées / Sorties */

void graphe_afficher(graphe* g)
{
	int v, w;
	msuc *m;
	int n = graphe_get_n(g);
	printf("graphe %s d'ordre %d à %d aretes :\n",
		graphe_est_or(g) ? "orienté" : "non orienté",
		graphe_get_n(g), graphe_get_m(g));
	for (v = 0; v < n; ++v) {
		puts("successeurs de v : ");
		for (m = graphe_get_prem_msuc(g, v); m; m = msuc_suivant(m)) {
			w = msuc_sommet(m);
			printf("%2d, ", w);
		}
		puts("");
	}
}

int graphe_ecrire_dot(graphe *g, char *nom_fichier, int ecrire_valeurs)
{
	int u;
	int n = graphe_get_n(g);
	FILE *f = fopen(nom_fichier, "w");
	int est_or = graphe_est_or(g);
	msuc *m;
	if (!f) { perror("fopen"); return -1; }

	if (est_or)
		fputs("digraph {\n", f);
	else
		fputs("graph {\n", f);

	for (u = 0; u < n; ++u)
		fprintf(f, "\t%d;\n", u);
	fputs("\n", f);

	for (u = 0; u < n; ++u)
		for (m = graphe_get_prem_msuc(g, u); m; m = msuc_suivant(m)) {
			int v = msuc_sommet(m);
			double val = msuc_valeur(m);
			if (!est_or && v < u) /* arête déjà rencontrée */
				continue;
			fprintf(f, "\t%d -%c %d ",
					u, est_or ? '>' : '-', v);
			if (ecrire_valeurs)
				fprintf(f, " [label = %.2f]", val);
			fprintf(f, ";\n");
		}
	fputs("}\n", f);

	fclose(f);
	return 0;
}

/* ______________________________________ Autres fonctions d'initialisation */

int graphe_complet(graphe* g, int n, int est_or)
{
	int v, w;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	for (v = 0; v < graphe_get_n(g); ++v)
		if (!est_or) {
			for (w = v + 1; w < graphe_get_n(g); ++w)
				if (graphe_ajouter_arete(g, v, w, 1.) < 0) {
					graphe_detruire(g);
					return -1;
				}
		} else {
			for (w = 0; w < graphe_get_n(g); ++w)
				if (graphe_ajouter_arc(g, v, w, 1.) < 0) {
					graphe_detruire(g);
					return -1;
				}
		}
	return 0;
}

int graphe_aleatoire(graphe* g, int n, double p, int est_or)
{
	int v, w;
	if (n < 0)
		return -2;
	if (p < 0 || p > 1)
		return -3;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	if (!est_or) {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = v; w < graphe_get_n(g); ++w)
				if ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arete(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	} else {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = 0; w < graphe_get_n(g); ++w)
				if ((double) rand()/RAND_MAX < p)
					if ( graphe_ajouter_arc(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	}
	return 0;
}

int graphe_aleatoire_multi(graphe* g, int n, double p, int est_or)
{
	int v, w;
	if (n < 0)
		return -2;
	if (p < 0 || p >= 1)
		return -3;
	if (graphe_stable(g, n, est_or) < 0)
		return -1;
	if (!est_or) {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = v; w < graphe_get_n(g); ++w)
				while ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arete(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	} else {
		for (v = 0; v < graphe_get_n(g); ++v)
			for (w = 0; w < graphe_get_n(g); ++w)
				while ((double) rand()/RAND_MAX < p)
					if (graphe_ajouter_arc(g, v, w, 0.) < 0) {
						graphe_detruire(g);
						return -1;
					}
	}
	return 0;
}
/* ______________________________________ Autres fonctions de manipulation (application des parcours) */
int graphe_est_biparti(graphe* g) {
    int *clr = malloc(g->n * sizeof(int));
    if (!clr) return -1;

    for (int i = 0; i < g->n; i++) {
        clr[i] = -1; // -1 signifie non colorié
    }

    for (int start = 0; start < g->n; start++) {
        if (clr[start] == -1) {
            
            int* queue = malloc(g->n * sizeof(int));
            int front = 0, back = 0;
            queue[back++] = start;
            clr[start] = 0; // couleur du premier sommet

            while (front < back) {
                int u = queue[front++];
                
                
                msuc* p = g->tab_sucs[u];
                while (p != NULL) {
                    int v = p->sommet;
                    if (clr[v] == -1) {
                        clr[v] = 1 - clr[u]; // couleur opposée
                        queue[back++] = v;
                    } else if (clr[v] == clr[u]) {
                        free(clr);
                        free(queue);
                        return 0; // graphe non biparti
                    }
                    p = p->suivant;
                }
            }

            free(queue);
        }
    }

    free(clr);
    return 1; // graphe biparti
}

/* stat : statut de réussite ou d'échec de la fonction */
int* graphe_est_sanscircuit(graphe* g, int* stat) {
    /* TODO */
    return NULL;
}

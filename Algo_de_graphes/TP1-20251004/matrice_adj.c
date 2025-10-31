#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ORDRE_MAX 50
int mat[ORDRE_MAX][ORDRE_MAX];

void afficher_mat(int n);
void graphe_complet(int n);
int ecrire_dot(int n, const char *nom_fichier);
void graphe_stable(int n);
void graphe_cycle(int n);
void graphe_biparti_complet(int m, int p);
void graphe_alea(int n, double p);
int lire_dot(const char *nom_fichier);

int main()
{
    afficher_mat(5);
    ecrire_dot(10,"complet-10.dot");
    graphe_cycle(8);
    graphe_biparti_complet(5, 3);
    graphe_alea(5, double p)
	return 0;
}

void afficher_mat(int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j) {
			printf("%d", mat[i][j]);
			if (j == n - 1)
				printf("\n");
			else
				printf("\t");
		}
	printf("\n");
}

void graphe_complet(int n)
{
//    if  (n<0 ;)
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if(i==j){
                mat[i][j]=0;
            }else{
                mat[i][j]=1;
            }
            
        }
    }
}

void graphe_stable(int n)
{
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            mat[i][j]=0;
        }
    }
}


int ecrire_dot(int n, const char *nom_fichier)
{
    FILE *f =fopen(nom_fichier,"w");
    fprintf(f,"graph {\n");
    for (int i=1; i<=n; i++) {
        fprintf(f,"%d\n",i);
        
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            fprintf(f,"%d -- %d\n",i,j);
        }
    }
    fprintf(f,"}\n");
    
	return 0;
}

void graphe_cycle(int n)
{
    FILE *f =fopen("g-cycle.dot","w");
    fprintf(f,"graph {\n");
    for (int i=1; i<=n; i++) {
        fprintf(f,"%d\n",i);
        
    }
    for (int i=1; i<=n; i++) {
        if(i<n){
            fprintf(f,"%d -- %d\n",i,i+1);
        }else{
            fprintf(f,"%d -- %d\n",i,1);
        }
        
        
    }
    fprintf(f,"}\n");
    
}

void graphe_biparti_complet(int m, int p)
{
    FILE *f =fopen("biparti.dot","w");
    fprintf(f,"graph {\n");
    for (int i=1; i<m+p; i++) {
        fprintf(f,"%d\n",i);
    }
    for (int i=1; i<m; i++) {
        for (int j=m; j<m+p; j++) {
            fprintf(f,"%d -- %d\n",i,j);
        }
    }
    fprintf(f,"}\n");
}

void graphe_alea(int n, double p) {
    // Initialisation de la graine aléatoire
    srand(time(NULL));
    
    // Initialisation de la matrice à 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
        }
    }
    
    // Parcours des couples (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double r = (double)rand() / RAND_MAX; // nombre aléatoire entre 0 et 1
            if (r < p) {
                mat[i][j] = 1;
                mat[j][i] = 1; // graphe non orienté
            }
        }
    }
}

int lire_dot(const char *nom_fichier)
{
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL)
    return -1; // fichier introuvable

    // Initialisation de la matrice à 0
    for (int i = 0; i < ORDRE_MAX; i++)
    for (int j = 0; j < ORDRE_MAX; j++)
    mat[i][j] = 0;

    char ligne[128];
    int i, j;
    int max_sommet = -1;

    // Lecture ligne par ligne
    while (fgets(ligne, sizeof(ligne), f)) {
        // On cherche les lignes contenant une arête de la forme "i -- j;"
        if (sscanf(ligne, " %d -- %d;", &i, &j) == 2) {
            if (i >= ORDRE_MAX || j >= ORDRE_MAX) {
                fclose(f);
                return -2; // trop de sommets
            }
            mat[i][j] = 1;
            mat[j][i] = 1; // graphe non orienté
            if (i > max_sommet) max_sommet = i;
            if (j > max_sommet) max_sommet = j;
        }
    }

    fclose(f);
    return max_sommet + 1; // nombre de sommets détectés (utile pour vérifier)
}

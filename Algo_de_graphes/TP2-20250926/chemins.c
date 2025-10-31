#include "graph_mat-1.h"
#include <stdio.h>

#define ORDRE 10
#define PROBA 0.2

int main()
{
  char fichier[20];
  graph_mat * g[ORDRE];
  g[0] = gm_init(ORDRE);
  g[1] = gm_random(ORDRE, PROBA);

  printf("Matrice d'adjacence du graphe initial :\n");
  gm_disp(g[1]);
  gm_write_dot(g[1], "chemins-01.dot");
  
  for (int k=2; k<ORDRE; ++k)
    {
        
      g[k] = gm_init(ORDRE); /* à remplacer */
        int i,j;
        int l,fin,nbr_vois,x;
        *p,vois;
        while (<#condition#>){
            nbr_vois=;
            vois=tab[x]
        
            while (x<nbr_vois){
                while (l<k && fin!=j) {
                    p=p->suivant;
                }
                x++;
                p=p->suivant;
            }
            
        }

      printf("Matrice d'adjacence des chemins de longueurs %d :\n", k);
      gm_disp(g[k]);
      sprintf(fichier, "chemins-%02d.dot", k);
      gm_write_dot(g[k], fichier);
    }


  /* libération de la mémoire */
  for (int k=0; k<ORDRE; ++k)
    {
      gm_free(g[k]);
    }
  return 0;
}

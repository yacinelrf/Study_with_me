#include "graph_mat-1.h"
#include<stdio.h>
int main()
{
	graph_mat *g1 = gm_init(5);
    graph_mat *g2 = gm_init(5);
    

	gm_add_edge(g1, 0, 1);
	gm_add_edge(g1, 0, 4);
	gm_add_edge(g1, 1, 4);
	gm_add_edge(g1, 4, 1);
	gm_add_edge(g1, 2, 2);
	gm_add_edge(g1, 2, 3);
    //---------
    gm_add_edge(g2, 0, 3);
    gm_add_edge(g2, 0, 3);
    gm_add_edge(g2, 1, 4);
    gm_add_edge(g2, 4, 1);
    gm_add_edge(g2, 2, 2);
    gm_add_edge(g2, 2, 3);
    //------
    graph_mat *g=gm_sum(g1,g2);
    graph_mat *g_prod = gm_prod(g1, g2);
    printf("%d",gm_degree(g,0));
    printf("%d",gm_degree(g,1));
    printf("%d",gm_degree(g,2));
    printf("%d",gm_degree(g,3));
    printf("%d",gm_degree(g,4));
   

	gm_disp(g1);
    gm_disp(g2);
    gm_disp(g);
	gm_write_dot(g1, "test-11.dot");
    gm_write_dot(g2, "test-12.dot");
    gm_write_dot(g, "test-sum.dot");
    gm_write_dot(g, "test-prod.dot");
    printf("\n=== Matrice d’adjacence produit (g1 × g2) ===\n");
       gm_disp(g_prod);
	gm_free(g1);
    gm_free(g2);
    gm_free(g);
    gm_free(g_prod);

	return 0;
}

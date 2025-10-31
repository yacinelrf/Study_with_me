#include "graph_mat-1.h"
#include <stdlib.h>
#include <stdio.h>

struct graph_mat {
	unsigned n;
	unsigned m;
	unsigned *adj;
	/* int is_or; in future version*/
	/* double *values; in future version*/
};

graph_mat *gm_init(unsigned n)
{
    struct graph_mat *g=malloc(sizeof(struct graph_mat));
    if (g==NULL)
        return NULL;
    
    
    g->n=n;
    g->m=0;
    
    
    g->adj=calloc(g->n*g->n,sizeof(unsigned));
    if (g->adj==NULL){
        free(g);
        return NULL;
    }

  return g;
}



void gm_free(graph_mat *g)
{
    if (g==NULL)
        return;
    
   
    free(g->adj);
    free(g);
}

unsigned gm_n(const graph_mat *g)
{
    if(g){
        return g->n ;
    }
    return 0;
  
}

unsigned gm_m(const graph_mat *g)
{
    if(g) return g->m ;
    
    return 0;
}

unsigned gm_mult_edge(const graph_mat *g, unsigned v, unsigned w)
{
    if (g==NULL) return 0;
    return g->adj[v*g->n+w];
}

void gm_add_edge(graph_mat *g, unsigned v, unsigned w)
{
    if (g==NULL)return ;
    if ( g->adj[w*g->n+v]<g->n-1 &&  g->adj[v*g->n+w]<g->n-1) {
        g->adj[w*g->n+v]++;
        if (v!=w)g->adj[v*g->n+w]++;
        
    }
    g->m++;
}

void gm_rm_edge(graph_mat *g, unsigned v, unsigned w)
{
    if (g){
        if (g->adj[w*g->n+v]>0 && g->adj[v*g->n+w]>0){
            g->adj[w*g->n+v]--;
            if (v != w) g->adj[v*g->n+w]--;//le cas d'une boucle
        }
    }
    g->m--;
}
    

unsigned gm_degree(const graph_mat *g, unsigned v)
{
    unsigned count=0;
    if(g){
        for (int i=0; i<g->n; i++) {
            count+=g->adj[v*g->n+i];
        }
    }
  return count;
}

graph_mat *gm_sum(graph_mat * g1, graph_mat * g2)
{
  graph_mat * g = gm_init(gm_n(g1));
  if (gm_n(g1) != gm_n(g2)) abort();
  
    if(g){
        for (int w=0; w<gm_n(g); w++) {
            for (int v=0; v<gm_n(g); v++) {
                g->adj[v*g->n+w]=g1->adj[v*g->n+w]+g2->adj[v*g->n+w];
            }
        }

        return g;
    }
    return NULL;
}

graph_mat *gm_prod(graph_mat * g1, graph_mat * g2)
{
  graph_mat * g = gm_init(gm_n(g1));
  if (gm_n(g1) != gm_n(g2)) abort();
    int somme;

    for (int v=0; v<gm_n(g); v++) {
        
        for (int w=0; w<gm_n(g); w++) {
            somme=0;

            for (int k=0; k<gm_n(g); k++) {
                somme+= g1->adj[v*g->n+k]* g2->adj[k*g->n+w];
            }
            g->adj[v*g->n+w]=somme;
        }
        
    }
    


  return g;
}

void gm_disp(const graph_mat *g)
{
	unsigned v, w;
	printf("n = %d, m = %d\n", gm_n(g), gm_m(g));
	for (v = 0; v < gm_n(g); ++v)
		for (w = 0; w < gm_n(g); ++w) {
			printf("%3d", gm_mult_edge(g, v, w));
			if (w != gm_n(g) - 1)
				printf(" ");
			else
				printf("\n");
		}
}

int gm_write_dot(const graph_mat *g, const char *filename)
{
	/* début solution */
	FILE *f;
	unsigned v, w, k;

	f = fopen(filename, "w");
	if (f == NULL) {
		perror("fopen in gm_write_dot");
		return -1;
	}

	fprintf(f, "graph {\n");
	for (v = 0; v < gm_n(g); ++v)
		fprintf(f, "\t%d;\n", v);

	fprintf(f, "\n");

	for (v = 0; v < gm_n(g); ++v)
		for (w = v; w < gm_n(g); ++w)
			for (k = 0; k < gm_mult_edge(g, v, w); ++k)
				fprintf(f, "\t%d -- %d;\n", v, w);
	fprintf(f, "}\n");
	fclose(f);
	/* fin solution */
	return 0;
}

graph_mat *gm_random(unsigned n, double p)
{
	unsigned v, w;
	graph_mat *g = gm_init(n);
	
	if (g == NULL) {
		perror("gm_init in gm_random");
		return NULL;
	}
	for (v = 0; v < gm_n(g); ++v)
		for (w = v + 1; w < gm_n(g); ++w) {
			double u = (double) rand() / RAND_MAX;
			if (u < p)
				gm_add_edge(g, v, w);
		}
	return g;
}

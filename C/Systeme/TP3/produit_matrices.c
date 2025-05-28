#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

#ifndef N /* nombre de lignes des matrices */
#define N 10
#endif

void imprime(int matrice[N][N]);
void generation_aleatoire(int matrice[N][N]);
void *calculer_coeffs_prod_ligne(void *declalage);
int A[N][N], B[N][N], R[N][N];

int main(void)
{
	struct timespec tic, toc;
	double duree;
	int i, j, k;
    pthread_t th[N];
    int numeros_thread[N]; /* va contenir { 0, 1, ..., N - 1 } */
    
    
	srand(time(NULL));
	generation_aleatoire(A);
	generation_aleatoire(B);
	// imprime(A);
	// puts("");
	// imprime(B);
	// puts("");
	clock_gettime(CLOCK_REALTIME, &tic);

    for (i = 0; i < N; ++i) {
        numeros_thread[i] = i;/*numeros_thread[i] = i; → On stocke l’index de la ligne i dans le tableau.*/
        if (pthread_create(&th[i], NULL, calculer_coeffs_prod_ligne, &numeros_thread[i])) {
            perror("pthread_create");
            exit(0);
        }
    }

	clock_gettime(CLOCK_REALTIME, &toc);
	duree = (toc.tv_sec - tic.tv_sec);
	duree += (toc.tv_nsec - tic.tv_nsec) / 1000000000.0;
	printf("durée : %g\n", duree);
	// imprime(R);
	return 0;
}

void imprime(int matrice[N][N])
{
	int i, j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			printf("%d%c", matrice[i][j], j == N - 1 ? '\n' : '\t');
}

void generation_aleatoire(int matrice[N][N])
{
	int i, j;
	for (i = 0; i < N; ++i)
		for (j = 0; j < N; ++j)
			matrice[i][j] = rand() % 10;
}

void *calculer_coeffs_prod_ligne(void *decalage){
    int i = *((int *) decalage), j, k; /*caster decalage en un pointeur vers int */
    for (j = 0; j < N; ++j) {
        R[i][j] = 0;
        for (k = 0; k < N; ++k)
            R[i][j] += A[i][k] + B[k][j];
    }
    return NULL;
}

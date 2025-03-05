#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N_DFT 8
/* Attend l'adresse d'un entier en argument.
* Calcule la somme 0 + 1 + ... + (*n) et met le résultat dans une variable
* entière nouvellement allouée. */
void *somme(void *n);
/* Attend l'adresse d'un entier en argument.
* Calcule le produit 1 * ... * (*n) et met le résultat dans une variable
* entière nouvellement allouée. */
void *produit(void *n);
int main(int argc, char *argv[])
{
    pthread_t th1, th2;
    int n = argc < 2 ? N_DFT : atoi(argv[1]);
    void *res_somme, *res_prod;
    if (pthread_create(&th1, NULL, somme, &n)) {
        perror("pthread_create somme");
        return 1;
    }
    if (pthread_create(&th2, NULL, produit, &n)) {
        perror("pthread_create produit");
        return 1;
    }
    pthread_join(th1, &res_somme);
    pthread_join(th2, &res_prod);
    printf("n : %d, somme : %d, produit : %d\n", n,*((int *) res_somme), *((int *) res_prod));
    free(res_somme);
    free(res_prod);
    return 0;
}

void *somme(void *n){
    int i, num = *((int *) n);
    int *res = malloc(sizeof(int));
    *res = 0;
    for (i = 1; i <= num; ++i)
        *res += i;
    return res;
}


void *produit(void *n){
    int i, num = *((int *) n);
    int *res = malloc(sizeof(int));
    *res = 1;
    for (i = 1; i <= num; ++i)
        *res *= i;
    return res;
}

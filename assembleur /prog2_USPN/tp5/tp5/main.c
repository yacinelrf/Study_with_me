//#include <stdio.h>
//#include <stdlib.h>
//
//void echange_pointeur(int *p, int *q)
//{
//    /* Affichage de l'adresse de p (dans la fonction echange_pointeur) */
//    printf("adresse de p dans la fonction = %p\n", &p);
//    /* Affichage de l'adresse de p dans la fonction */
//    printf("adresse de q dans la fonction = %p\n", &q);
//    /* Affichage de l'adresse de l'entier pointé par p (dans la fonction echange_pointeur) */
//    printf("adresse de l'entier pointé par p avant réaffectation dans echange_pointeur  = %p\n", p);
//    /* Affichage de l'adresse de l'entier pointé par q (dans la fonction echange_pointeur) */
//    printf("adresse de l'entier pointé par q avant réaffectation dans echange_pointeur = %p\n", q);
//    /* Réaffectation de p */
//    p = q;
//    /* Affichage de l'adresse de p après réaffectation (dans la fonction echange_pointeur) */
//    printf("adresse de p dans la fonction après réaffectation dans echange_pointeur = %p\n", &p);
//    /* Affichage de l'adresse de l'entier pointé par p après réaffectation (dans la fonction echange_pointeur) */
//    printf("adresse de l'entier pointé par p après réaffectation dans echange_pointeur = %p\n", p);
//}
//
//int main(void)
//{
//  int *p;  /* p est un pointeur sur un entier */
//    int *q;  /* q est un pointeur sur un entier */
//    int i = 1, j = 2;
//    printf("Avant :\n");
//    /* Affichage de l'adresse de p avant échange (dans la fonction principale) */
//    printf("adresse de p dans la fonction = %p\n", &p);
//    /** À COMPLÉTER **/
//    /* Affichage de l'adresse de q avant échange (dans la fonction principale) */
//    printf("adresse de l'entier pointé par q avant réaffectation dans echange_pointeur = %p\n", q);
//    /** À COMPLÉTER **/
//    /* Affichage de l'adresse de i avant échange (dans la fonction principale) */
//    printf("l'adrese de i est :  %p\n",&i);
//    /** À COMPLÉTER **/
//    /* Affichage de l'adresse de j avant échange (dans la fonction principale) */
//    printf("l'adrese de j est :  %p\n",&j);
//    /** À COMPLÉTER **/
//
//    /* Initialisation de p et q */
//    p = &i;
//    q = &j;
//  /* Affichage de l'adresse de l'entier pointé par p avant échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("adresse de l'entier pointe par p dans la fonction = %p\n", p);
//    /* Affichage de la valeur de l'entier pointé par p avant échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("valeur de l'entier pointe par p dans la fonction = %d\n", *p);
//    /* Appel de la fonction echange_pointeur */
//    echange_pointeur(p,q);
//
//    printf("Apres  :\n");
//
//    /* Affichage de l'adresse de p  après échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("adresse de p dans la fonction = %p\n", p);
//    /* Affichage de l'adresse de l'entier pointé par p après échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("adresse de l'entier pointe par p dans la fonction = %p\n", p);
//    /* Affichage de la valeur de l'entier pointé par p après échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("valeur de l'entier pointe par p dans la fonction = %d\n", *p);
//    /* Affichage de l'adresse de l'entier pointé par q après échange (dans la fonction principale) */
//    /** À COMPLÉTER **/
//    printf("adresse de l'entier pointe par q dans la fonction = %p\n", q);
//    return EXIT_SUCCESS;
//}
//
//
//
//


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define N 20





int **transposer_mat (int **tab,int lin,int col){
    int i,j,x;
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            x=*(*(tab+i)+j);
            *(*(tab+i)+j)=*(*(tab+j)+i);
            *(*(tab+j)+i)=x;
        }
    }
    return tab;
}


//int **reduire_mat(int **tab,int lin,int col){
//    int i;
//
//    for (i=0; i<lin; i++) {
//        *(tab+i)=*(tab+1+i);
//    }
//
//
//    return tab+1;
//}
int **reduire_mat(int **tab,int lin,int col){
    int i,j;
    
    for (i=0; i<lin-1; i++) {
        for (j=0; j<col-1; j++) {
            *(*(tab+i)+j)=*(*(tab+1+i)+j+1);
        }
        
    }
    
    
    return tab;
}


int **prod(int **tab1,int **tab2,int lin,int col){
    int i,j,s=0,t;
    int **tab=NULL;
    for (t=0; t<lin; t++) {
        for (i=0; i<lin; i++) {
            for (j=0; j<col; j++) {
                s=(*(*(tab1+i)+j))*(*(*(tab2+j)+i))+s;
            }
            *(*(tab+t)+i)=s;
        }
    }
        
    
    
    return tab;
}


int main(){
    

    
    int lin,col,i,j,x;
    printf("veuillez entrer le nombre de lignes\n");
    scanf("%d",&lin);
    printf("veuillez entrer le nombre de colonnes\n");
    scanf("%d",&col);
    
    int **tab = (int **)calloc(lin, sizeof(int *));
       for (int i = 0; i < lin; i++) {
           *(tab+i) = (int *)calloc(col, sizeof(int));
       }
    int **tab1;
    
    
    
    for(i=0;i<lin;i++){
        for(j=0;j<lin;j++){
            *(*(tab+i)+j)=rand()%100;
        }
    }
    
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d|",*(*(tab+i)+j));
        }
        printf("\n");
    }
    printf("----------------------------\n");
    tab1=transposer_mat(tab, lin, col);
    
    for(i=0;i<lin;i++){
        for(j=0;j<col;j++){
            printf("%d|",*(*(tab1+j)+i));
        }
        printf("\n");
    }
    
    printf("----------------------------\n");
    tab=reduire_mat(tab, lin, col);
    
    for(i=0;i<lin-1;i++){
        for(j=0;j<col-1;j++){
            printf("%d|",*(*(tab1+i)+j));
        }
        printf("\n");
    }
    printf("----------------------------\n");
    
    tab1=prod(tab, tab1, lin, lin);
 
    for(i=0;i<lin-1;i++){
        for(j=0;j<col-1;j++){
            printf("%d|",*(*(tab1+i)+j));
        }
        printf("\n");
    }
    
    
    
    return EXIT_SUCCESS;
}

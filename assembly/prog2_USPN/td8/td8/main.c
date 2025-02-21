#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct mat_float {
  int lig; /* nombre de lignes de la matrice */
  int col; /* nombre de lignes de la matrice */
  double ** tab_coeff; /* tableau dynamique bidimensionnel des coefficients */
};

struct mat_float *creer_initialiser_matrice (int l, int c);
struct mat_float* reduire_matrice (struct mat_float *m, int l, int c);
void affichage(struct mat_float *m);
struct mat_float * remplir(struct mat_float *m);
struct mat_float * additionner_matrice(struct mat_float *m1,struct mat_float *m2);
struct mat_float * multiplier_matrice (struct mat_float *m1,struct mat_float *m2);
int determinant_matrice(struct mat_float *m,int i,int j);

int main(){
    struct mat_float *m1=creer_initialiser_matrice(5,5);
    struct mat_float *m2=creer_initialiser_matrice(5,5);
    struct mat_float *m=creer_initialiser_matrice(5, 5);
    struct mat_float *m3=(struct mat_float *)malloc(sizeof(struct mat_float));
    m3=multiplier_matrice(m1, m2);
    m=additionner_matrice(m1, m2);
    affichage(m1);
    printf("+++++++++++++++++\n");
    affichage(m2);
    printf("+++++++++++++++++\n");
    affichage(m);
    printf("+++++++++++++++++\n");
    affichage(m3);
    
    return EXIT_SUCCESS;
}

struct mat_float *creer_initialiser_matrice (int l, int c){
    struct mat_float *matr=NULL;
    matr=(struct mat_float *)malloc(sizeof(matr));
    matr->tab_coeff=(double **)malloc(c*sizeof(double*));
    for(int i=0;i<l;i++){
        matr->tab_coeff[i]=(double *)malloc(l*sizeof(double));
    }
    matr->col=c;
    matr->lig=l;
    matr=remplir(matr);
    return matr;
};


struct mat_float *reduire_matrice(struct mat_float *m, int l, int c) {
    struct mat_float *m1 = creer_initialiser_matrice(m->lig - 1, m->col - 1);
    if (m1 == NULL) {
        return NULL; // Gestion d'erreur : échec de création de la nouvelle matrice
    }

    int ik = 0;
    int jk = 0;

    for (int i = 0; i < m->lig; i++) {
        if (i == l) {
            continue; // Ignorer la ligne l
        }

        for (int j = 0; j < m->col; j++) {
            if (j == c) {
                continue; // Ignorer la colonne c
            }

            m1->tab_coeff[ik][jk] = m->tab_coeff[i][j];
            jk++;
        }

        ik++;
        jk = 0;
    }

    return m1;
}

void affichage(struct mat_float *m){
    for(int i=0;i<m->lig;i++){
        for (int j=0; j<m->col; j++) {
            printf("%.0f-",m->tab_coeff[i][j]);
        }
        printf("\n");
    }
}

struct mat_float * remplir(struct mat_float *m){
    time_t x=time(NULL);
    unsigned int y=(unsigned int)x;
    srand(y);
    for(int i=0;i<m->lig;i++){
        for(int j=0;j<m->lig;j++){
            m->tab_coeff[i][j]=rand()%100;
        }
    }
    return m;
}

struct mat_float * additionner_matrice(struct mat_float *m1,struct mat_float *m2){
    struct mat_float *m=creer_initialiser_matrice(m1->lig, m1->col);
    
    if(m1->lig!=m2->lig || m1->col!=m2->col){
        printf("la somme est impossible!\n");
    }else{
        for (int i=0; i<m1->lig; i++) {
            for (int j=0; j<m1->col; j++) {
                m->tab_coeff[i][j]=m1->tab_coeff[i][j]+m2->tab_coeff[i][j];
            }
        }
    }
    
    
    return m;
}


struct mat_float * multiplier_matrice (struct mat_float *m1,struct mat_float *m2){
    struct mat_float *m=creer_initialiser_matrice(m1->lig, m2->col);
    
    for (int x=0; x<m->lig; x++) {
        for (int y=0; y<m->col; y++) {
            m->tab_coeff[x][y]=0;
        }
    }
    if(m1->col != m2->lig){
        printf("la multiplication est impossible!\n");
    }else{
        for (int i=0; i<m1->lig; i++) {
            for (int j=0; j<m2->col; j++) {
                for (int k=0; k<m1->col; k++) {
                    m->tab_coeff[i][j]=(m1->tab_coeff[i][k]*m2->tab_coeff[k][j])+m->tab_coeff[i][j];
                }
            }
        }
    }
    return m;
}


int determinant_matrice(struct mat_float *m,int i,int j){
    int det;
    if(i==0){
        det=0;
    }else{
        if((i+j)%2==0){
            return m->tab_coeff[i][j]*determinant_matrice(reduire_matrice(m, i, j),i-1,j)+det;
        }else{
            return -m->tab_coeff[i][j]*determinant_matrice(reduire_matrice(m, i, j),i-1,j)+det;
        }
    }
    
    return det;
}

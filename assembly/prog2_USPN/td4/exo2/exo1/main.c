#include <stdio.h>
struct matrice {
            unsigned nb_lignes;
            unsigned nb_colonnes;
            int coeff[10][10];
};

void reduire_mat(struct matrice *m);
void transposer_mat(struct matrice *am_t, const struct matrice *am);
int main() {
    struct matrice m = {2, 3, {{-7, 0, 4}, {1, 8, -3},{1, 8, -9}}};
    int i,j;
    int n=3;
//    printf("%p\n", m.coeff[0]);
//    printf("%p\n", m.coeff);
//    printf("%p\n", m.coeff[1][0]);
    reduire_mat(&m);
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-1; j++) {
            printf("%d\n",m.coeff[i][j]);
        }
    }
    return 0;
}

void transposer_mat(struct matrice *am_t, const struct matrice *am){
    unsigned z;
    int i,j,n=3;
    am_t->nb_colonnes=am->nb_lignes;
    am_t->nb_lignes=am->nb_colonnes;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            *(*(am_t->coeff+i)+j)=*(*(am->coeff+j)+i);
        }
    }
}


void reduire_mat(struct matrice *m){
    struct matrice *p;
    int i,j,n=3;
    m->nb_colonnes--;
    m->nb_lignes--;
    p=m;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            *(*(p->coeff+i)+j)=*(*(p->coeff+i+1)+j+1);
        }
    }
    m=p;
    
}

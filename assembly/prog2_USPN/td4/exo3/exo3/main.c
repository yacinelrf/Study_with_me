#include <stdio.h>

struct uef {
    unsigned coefficient;
    float note;
};
typedef struct releve_BF_N2_info {
    unsigned long identifiant;
    struct uef algebre;
    struct uef programmation;
    struct uef logique;
} *lien;//declare comme pointeur
float moyenne_BF(lien);
void trier_moyenne_tab_releves(lien *t, int taille);
int main() {
    lien t[10];
    t[5]->logique.note;
    printf("Hello, World!\n");
    return 0;
}


float moyenne_BF(lien x){
    return (x->algebre.note*x->algebre.coefficient+x->programmation.note*x->programmation.coefficient+x->logique.note*x->logique.coefficient)/(x->algebre.coefficient+x->programmation.coefficient+x->logique.coefficient);
}

void trier_moyenne_tab_releves(lien *t, int taille){
    int i,j;
    lien x;
    for(i=1;i<taille;i++){
        j=i;
        while (j>0 && moyenne_BF(t[j])<moyenne_BF(t[j-1])) {
            x=t[j-1];
            t[j-1]=t[j];
            t[j]=x;
            j--;
        }
    }
}

int nombre_BF_valide_tab_releves(lien *t, int taille){
    int i=0,j,s=0;
    while(moyenne_BF(t[1])<10){
        i++;
    }
    for(j=i;j<taille;j++){
        s++;
    }
    return s;
}

int rechercher_tab_releves(lien *t, int taille, float m_min, float m_max){
    
}

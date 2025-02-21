#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct mai{
    int val;
    struct mai* p;
}mai;//mai ici c'est le nom qu'on va appeler avec notre structure lors de l'execution


EXO_01

int verif(struct mai* tete){
    if (tete==NULL){
        return 1;
    }
    else{
        return 0;
    };

}

int main(){
    struct mai* tete;
    if(verif(tete)==1){
        printf("la liste est vide");
    }else{
        printf("la liste n'est pas vide");
    }
}

EXO_02

void afficherListe(struct mai* tete) {
   struct mai* q = tete;
   printf("Liste : ");
   while (q != NULL) {
      printf("%d ", q->val);
      q = q->p;
   }
   printf("\n");
}

int remplir(struct mai* tete, int nbr){
    struct mai* q;
    struct mai* d;
    int i;
    for(i=0;i<=nbr;i++){
        q=(struct mai*)malloc(sizeof(mai));
        scanf("%d",&q->val);
        d=q;
        q=q->p;
    }
    return 0;
}

int ajouterDebut(struct mai* tete){
    struct mai* q;
    int i;
    i=1;
    while(i==1){
        q=(struct mai*)malloc(sizeof(mai));
        q->p=tete;
        tete=q;
        printf("si vous voulez ajouter un autre element entrer 1");
        scanf("%d",&i);
    }
    return 0;
}

int ajouterPosition(struct mai* tete , int pos){
    struct mai* q;
    struct mai* d;
    struct mai* a;
    q=tete;
    int i;
    i=1;
    do{
        q=q->p;
        i=i+1;
    }while(i<pos);
    a=q->p;
    d=(struct mai*)malloc(sizeof(mai));
    q->p=d;
    d->p=a;
    return 0;
    }


int ajouterFin(struct mai* tete){
    struct mai* q;
    struct mai* a =tete;
    q=(struct mai*)malloc(sizeof(mai));
    while(a->p!=NULL){
        a=a->p;
    }
    a->p=q;
    q->p=NULL;
    return 0;
}

int ajouterTrier(struct mai* tete,int x){
    struct mai* q=tete;
    struct mai* w;
    struct mai* a=tete->p;
    int val;
    while (a->val<x){
        q=q->p;
        a=a->p;
    }
    w=(struct mai*)malloc(sizeof(mai));
    q->p=w;
    w->p=a;
    return 0;
}

int comtebiliser(struct mai* tete){
    struct mai* q;
    q=tete;
    while(q!=NULL){
        q=q->p;
        i=i+1;
    }
    return 0;
}
int recherche(struct mai* x,int n){
    int i;
    struct mai* p;
    i=0;
    p=x;
    while(i<n && p!=NULL){
        p=p->p;
        i=i+1;
    }
    printf("&d",p);
    return 0;
}
int supp(struct mai* t,int n){
    struct mai* p;
    struct mai* q;
    int i;
    p=t;
    if(n!=1){
        i=2;
        while(i!=n){
            p=p->p;
            i=i+1;
        }
        q=p->p;
        p=q->p;
        free(q);
    }
    else{
        q=t;
        t=t->p;
        free(q);
    }
    return 0;

}
 
int destroy(struct mai* t){
    struct mai* p;
    struct mai* q;
    p=t;
    while(p!=NULL){
        q=p;
        p=p->p;
        free(q);
    }
    return 0;
}


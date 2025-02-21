#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct mai{
    int val;
    struct mai* suiv;
    struct mai* pre;
};
int vide(int *p){
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct mai* creerliste(int n,struct mai* t){
    int i;
    struct mai* q;
    struct mai* p;
    if(n==0){
        t=NULL;
    }
    else{
        for(i=1;i<n+1;i++){
            if(i==1){
                t=(struct mai*)malloc(sizeof(q));
                printf("veuillez inserer la valeur numero %d\n\t",i);
                scanf("%d",&t->val);
                t->suiv=NULL;
                t->pre=NULL;
                p=t;
            }
            else{
                q=(struct mai*)malloc(sizeof(q));
                printf("veuillez inserer la valeur numero %d\n\t",i);
                scanf("%d",&q->val);
                q->suiv=NULL;
                q->pre=p;
                p->suiv=q;
                p=q;
            }
            
        }
    }
    return t;
}

struct mai* AjoutDebut(struct mai* t){
    struct mai* q;
    q=(struct mai*)malloc(sizeof(q));
    printf("veuillez insirer la valeur que tu veux ajouter au debut de votre liste");
    scanf("%d",&q->val);
    q->pre=NULL;
    q->suiv=t;
    t=q;
    return t;
}

struct mai* AjoutPos(struct mai* t,int position,valeur){
    int i;
    struct mai* p;
    struct mai* q;
    struct mai* w;
    i=1;
    p=t;
    q=t->suiv;
    if(position>2){
        for(i=1;i<position;i++){
            p=p->suiv;
            q=q->suiv;
        }
    }
    w=(struct mai*)malloc(sizeof(w));
    w->val=valeur;
    w->suiv=q;
    w->pre=p;
    p->suiv=w;
    q->pre=w;
    return t;
}

struct mai* AjoutFin(struct mai* t,int valeur){
    struct mai* q;
    struct mai* w;
    q=t;
    while(q->suiv!=NULL){
        q=q->suiv;
    }
    w=(struct mai*)malloc(sizeof(w));
    q->suiv=w;
    w->pre=q;
    w->suiv=NULL;
    w->val=valeur;
    return t;
}

int compte(struct mai* t){
    int i=0;
    while(t!=NULL){
        i=i+1;
        t=t->suiv;
    }
    return i;
}

int recherche(struct mai* t,int n){
    int i;
    for(i=1;i<n;i++){
        t=t->suiv;
    }
    return t->val;
}

struct mai* sup(struct mai* t,int n){
    int i;
    i=2;
    struct mai* q;
    struct mai* p;
    struct mai* w;
    q=t;
    p=q->suiv;
    w=p->suiv;
    while(i!=n){
        q=q->suiv;
        p=p->suiv;
        w=w->suiv;
        i=i+1;
    }
    q->suiv=w;
    w->pre=q;
    free(p);
    return t;
}

struct mai* destroy(struct mai* t){
    struct mai* q;
    q=t;
    while(t!=NULL){
        q=q->suiv;
        free(t);
        t=q;
    }
    return t;
}

struct mai* ajouttri(struct mai* t,int valeur){
    struct mai* p;
    int i;
    p=t;
    i=1;
    while(p->val<valeur){
        p=p->suiv;
        i=i+1;
    }
    AjoutPos(t, i, valeur);
    return t;
}

void afficherListe(struct mai* t,int n){
    int i=1,x;
    printf("votre liste contient les valeurs suivantes\n\t");
    while (t!=NULL) {
        x=t->val;
        printf("la valeur numero %d est %d\n\t",i,x);
        t=t->suiv;
        i=i+1;
    }
}



int main(){
    int *i=NULL,n,reponse1,reponse2,reponse3,reponse4,reponse5,position,x,y,z,supp,dest,tri;
    struct mai* t;
    if(vide(i)==0){
        printf("yes");
    }
    printf("veuillez introduire le nombre des valeur que tu veux insirer \n");
    scanf("%d",&n);
    t=creerliste(n, t);
    afficherListe(t,n);
    printf("si tu veux ajouter une valeur a votre liste veuillez entre 1\n\t");
    scanf("%d",&reponse1);
    if(reponse1==1){
        afficherListe(AjoutDebut(t),n+1);
        n=n+1;
    }
    printf("si vous voulez ajouter une valeur au milieu de votre liste veuillez entrer 1\n\t");
    scanf("%d",&reponse2);
    if(reponse2==1){
        printf("insirez la position ou vous voulez l'insirer\t");
        scanf("%d",&position);
        printf("veuilez entrer la valeur\t");
        scanf("%d",&x);
        afficherListe(AjoutPos(t,position,x),n+1);
        n=n+1;
    }
    printf("si vous voulez ajouter une valeur a la fin de votre liste veuillez entrer 1\n\t");
    scanf("%d",&reponse3);
    if(reponse3==1){
        printf("veuillez entrer la valeur que vous voulez ajouter\n\t");
        scanf("%d",&y);
        afficherListe(AjoutFin(t,y),n+1);
        n=n+1;
    }
    printf("le nombre des element dans votre liste est %d \n",compte(t));
    printf("quel element de cette liste que cous voulez voir son contenu \n");
    scanf("%d",&z);
    printf("la valeur du %d element est %d \n",z,recherche(t,z));
    printf("si vous voulez supprimer une valeur de votre liste insirez 1");
    scanf("%d",&reponse5);
    if(reponse5==1){
        printf("ecrivez la position de l'element que tu veux supprimer");
        scanf("%d",&supp);
        afficherListe( sup(t,supp),n);
        n=n-1;
    }
    printf("si tu veux detruire la liste veuillez insirer 1");
    scanf("%d",&dest);
    if(dest==1){
        destroy(t);
    }
    printf("si vous voulez ajouter un elemen en gardant la liste triee insirez 1");
    scanf("%d",&tri);
    if(tri==1){
        printf("ecrevez la valeur que vous souhitez insirer");
        scanf("%d",&reponse4);
        ajouttri(t,reponse4);
    }
}

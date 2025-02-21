#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mai{
    struct info{
        char matricule[7];
        char nom[30];
        int grp;
        float notecontrole;
    }info;
    struct mai* suiv;
}mai;

struct maii{
    struct mai* val;
    struct maii* suiv;
}maii;
 
struct maii* division(struct mai* tete,int n,nbr){
    int x,i,j;
    struct mai* p;
    struct maii* tete1;
    struct maii* r;
    struct mai* w;
    struct maii* q;
    x=nbr/n;
    while(tete!=NULL){
        for(i=1;i<x;i++){
            p=p->suiv;
        }
        j++;
        if(j==1){
            w=tete;
            tete=p->suiv;
            p->suiv=NULL;
            tete1=(struct maii*)malloc(sizeof(tete1));
            tete1->suiv=NULL;
            tete1->val=w;
            r=tete1;
        }else{
            w=tete;
            tete=p->suiv;
            p->suiv=NULL;
            q=(struct maii*)malloc(sizeof(q));
            r->suiv=q;
            q->suiv=NULL;
            q->val=w;
        }
    }
    return tete1;
}
int main(){
    int x,i,nbr;
    struct mai* p;
    struct mai* q;
    struct mai* tete;
    nbr=0;
    printf("veuillez entrer le nombre des etudiants");
    scanf("%d",&x);
    for(i=1;i<=x;i++){
        if(i==1){
            p=(struct mai*)malloc(sizeof(p));
            scanf("%d",&p->info.grp);
            tete=p;
            q=p;
            
        }
        else{
            p=(struct mai*)malloc(sizeof(p));
            scanf("%d",&p->info.grp);
            q->suiv=p;
            q=p;
        }
        nbr=nbr+1;
    }
    p=tete;
    while(p!=NULL){
        printf("%d",p->info.grp);
        p=p->suiv;
    }
}

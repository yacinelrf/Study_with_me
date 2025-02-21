#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mai{
    int val;
    struct mai* suiv;
}mai;

struct mai* creerfile(struct mai* tete){
    return NULL;
}


struct mai* enfiler(struct mai* tete,int n){
    struct mai* p;
    struct mai* q;
    p=tete;
    while(p->suiv!=NULL){
        p=p->suiv;
    }
    q=(struct mai*)malloc(sizeof(mai));
    q->val=n;
    q->suiv=NULL;
    p->suiv=q;
    return tete;
}

struct mai* creer(){
    struct mai* tete;
    struct mai* p;
    struct mai* q;
    int i,x;
    tete=(struct mai*)malloc(sizeof(mai));
    tete->val=100;
    q=tete;
    for(i=1;i<5;i++){
        p=(struct mai*)malloc(sizeof(mai));
        q->suiv=p;
        printf("veuillez entrer un nbr");
        scanf("%d",&x);
        p->val=x;
        p->suiv=NULL;
        q=p;
    }
    return tete;
}
struct mai* supp(struct mai* tete){
    struct mai* p;
    struct mai* q;
    int i;
    p=tete;
    for(i=1;i<3;i++){
        q=p;
        p=p->suiv;
    }
    q->suiv=p->suiv->suiv;
    free(p);
    return tete;
}
//struct mai-------->>>>

float mediane(int n){
    int t[n];
    for(i=1;i<=n;i++){
        scanf();
    }
    int x;
    if(n%2==0){
        return t[n/2];
    }
    else{
        x=n/2;
        return t[x]+t[x+1];
    }
}

int prem(int n,int x){
    if(n%x==0){
        return 0;
    }
    else{
        if(x==1){
            return 0;
        }
        else{
            return 1+prem(n,x-1);
        }
    }
}

int main(){
   
}

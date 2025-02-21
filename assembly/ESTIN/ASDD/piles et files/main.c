#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct mai{
    int val;
    struct mai* suiv;
};

int tab[10];

struct pile{
    struct mai* sommet;
};

struct pile* initpile(struct pile* pil){
    pil=NULL;
    return pil;
}

struct pile* empiler(struct pile* pil,int x){
    struct mai* q;
    if(pil==NULL){
        q=(struct mai*)malloc(sizeof(q));
        pil->sommet=q;
    }
    if(pil!=NULL){
        q=(struct mai*)malloc(sizeof(q));
        q->suiv=pil->sommet;
        q->val=x;
        pil->sommet=q;
    }
    return pil;
}

int depiler(struct pile* pil){
    int x;
    x=pil->sommet->val;
    pil->sommet=pil->sommet->suiv;
    return x;
};

struct pile* afficher(struct pile* pil){
    struct mai* q;
    int i;
    i=0;
    q=(struct mai*)malloc(sizeof(q));
    q=pil->sommet;
    while(q!=NULL){
        q=q->suiv;
        i=i+1;
    };
    printf("le nombre des elements dans votre liste est :%d\n",i);
    return 0;
}

int pile_vide(struct pile* pil){
    if(pil==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct mai* sommet_de_pile(struct pile* pil){
    return pil->sommet;
}

int nbrelements(struct pile* pil){
    int x,i;
    struct pile* q;
    struct mai* p;
    i=0;
    q=(struct pile*)malloc(sizeof(q));
    p=pil->sommet;
    while(p!=NULL){
        x=pil->sommet->val;
        depiler(pil);
        empiler(q,x);
        p=p->suiv;
        i=i+1;
    }
    return i;
}

int invers(struct pile* pil){
    struct mai* p;
    int x,i;
    p=(struct mai*)malloc(sizeof(p));
    p=pil->sommet;
    i=0;
    while(p!=NULL){
        tab[i]=p->val;
        depiler(pil);
        i=i+1;
    }
    while(i!=0){
        printf("%d",tab[i]);
        i=i-1;
    }
    

    return 0;
}

int main(){
    int n,i,x,reponse;
    struct pile* pill;
    pill=(struct pile*)malloc(sizeof(pill));
    printf("veuillez entrer le nombre d'elemrnts que voys voulez creer dans votre pile\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("veuillez entrer l'element numero %d: ",i);
        scanf("%d",&x);
        empiler(pill,x);
    }
    printf("si vous voulez voir les elemts de votre liste inverse veuillez insirer 1");
    scanf("%d",&reponse);
    if(reponse==1){
        invers(pill);
    }
    printf("si vous voulez savoire le nombre des elemnts dans votre pile veuillez entrer 1\n");
    scanf("%d",&reponse);
    if(reponse==1){
        printf("le nombre des elements dans votre pile est %d\n",nbrelements(pill));
    }
    afficher(pill);
    printf("si vous voulez ajouter un element a votre pille veuillez insirer 1 : ");
    scanf("%d",&reponse);
    if(reponse==1){
        printf("veuillez entrer la valeur que vous voulez ajouter :");
        scanf("%d",&x);
        empiler(pill,x);
    };
    afficher(pill);
    printf("si vous voulez supremer un element de la liste veuillez insirer 1 : ");
    scanf("%d",&reponse);
    if(reponse==1){
        depiler(pill);
        printf("la valeur que vous avez supprimer est %d ",x);
    }
    afficher(pill);
    

}

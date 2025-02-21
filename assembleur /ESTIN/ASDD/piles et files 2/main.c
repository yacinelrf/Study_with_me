#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct mai{
    int val;
    struct mai* suiv;
};

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

struct pile* depiler(struct pile* pil,int x){
    x=pil->sommet->val;
    pil->sommet=pil->sommet->suiv;
    return pil;
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
        depiler(pill,x);
        printf("la valeur que vous avez supprimer est %d ",x);
    }
}

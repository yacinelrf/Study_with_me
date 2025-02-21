#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//EXO_01

int main(){
    int n,k;
    int *pn,*pk;
    pn=&n;
    pk=&k;
    printf("veuillez entrer deux entiers\n");
    scanf("%d %d",pn,pk);
    printf("%d+%d=%d \n",*pn,*pk,*pn+*pk);
}


EXO_02

int main(){
    int T[5];
    int i,s,*p;
    s=0;
    for(p=T;p<T+5;p++){
        scanf("%d",p);
    };
    for(p=T;p<T+5;p++){
        s=s+*p;
    };
    printf("%d",s);
}


//EXO_03

struct personne{
    char nom[10],prenom[10];
    int age;
};
struct personne T[2];
struct personne *p;
int main(){
    int i,s,d;
    for(i=0;i<=1;i++){
        scanf("%s",&T[i].nom);
        scanf("%s",&T[i].prenom);
        scanf("%d",&T[i].age);
    }
    p=&T[0];
    for(i=0;i<=1;i++){
        if(T[i].age<s){
            p=&T[i];
        };
            };
    printf("le plus petit est %s %s",p->nom,p->prenom);



//EXO_04

int main(){
    int *p,i;
    printf("veuillez entrer le nombre des cases \n");
    scanf("%d",&i);
    int T[i];
    for (p=T;p<T+i;p++){
        scanf("%d",p);
    };
    for (p=T;p<T+i;p++){
        printf("%d\t",*p);
    };
}



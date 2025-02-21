#include <stdio.h>
#include <stdlib.h>
struct polynome {
            int * coefficients;
            int taille;
            int degre;
};



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

struct polynome *creer_polynome(struct polynome p,int n){
    struct polynome *adr;
    adr=(struct polynome*)malloc(sizeof(struct polynome));
    adr->taille=n;
    adr->coefficients=NULL;
    return adr;
}

void reformater_polynome(struct polynome *p,int n){
    int *adr_coeff;
    adr_coeff=(int*)malloc(n*sizeof(adr_coeff));
}

void detruire_polynome(struct polynome *p){
    free(p);
}

void scalaire_polynome(struct polynome *p,int a){
    int i=0;
    struct polynome *q=p;
    while(q->coefficients[i]!=0){
        q->coefficients[i]=(q->coefficients[i])*a;
        i++;
            }
}


struct polynome *additionner_polynome(struct polynome *p,struct polynome *q){
    int i=0,maxp=0,maxq=0,maxx,j=0;
    struct polynome *s=(struct polynome*)malloc(sizeof(struct polynome));
    while(p->coefficients[j]!=0){
        maxp++;
    }
    while(p->coefficients[j]!=0){
        maxq++;
    }
    if(maxp>maxq){
        maxx=maxp;
    }else{
        maxx=maxq;
    }
    while (maxp!=0 || maxq!=0) {
        s->coefficients[maxx]=p->coefficients[maxp]+q->coefficients[maxq];
        maxp--;
        maxx--;
        maxq--;
    }
    
    return s;
}

struct polynome *multiplier_polynome(struct polynome *p,struct polynome *q){
    
    int i=0;
    struct polynome *prod=(struct polynome*)malloc((p->degre+q->degre)*sizeof(struct polynome));
    while (p->coefficients[i]!=0 || q->coefficients[i]!=0) {
        scalaire_polynome(p, q->coefficients[i]);
        prod=additionner_polynome(p,q);
        i++;
    }
    return prod;
}

struct polynome *deriver_polynome(struct polynome *p){
    int i=0;
    while (p->coefficients[i]!=0) {
        p->coefficients[i]=p->coefficients[i]*(p->degre-1);
        p->degre=p->degre-1;
        p->taille--;
    }
    return p;
}

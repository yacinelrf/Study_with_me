#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct polynome {
            int * coefficients;
            int taille;
            int degre;
};

struct polynome deriv(struct polynome p){
    struct polynome d;
    d.coefficients=(int *)calloc(p.taille-1, sizeof(int));
    d.taille=p.taille-1;
    d.degre=p.degre-1;
    for (int i=0; i<d.degre; i++) {
        d.coefficients[i]=p.coefficients[i+1]*(i);
    }
    for (int i=0; i<=p.degre-1; i++) {
        printf("%dx^(%d)+",d.coefficients[i],i);
    }
    
    printf("\n");
   
    return d;
}


struct polynome xf(struct polynome p){
    struct polynome xp;
    xp.coefficients=(int *)calloc(p.taille+1, sizeof(int));
    xp.taille=p.taille+1;
    xp.degre=p.degre+1;
    for (int j=0; j<xp.degre; j++) {
        xp.coefficients[j]=0;
    }
    for (int i=0; i<p.degre; i++) {
        xp.coefficients[i+1]=p.coefficients[i];
        
    }

    for (int i=0; i<=p.degre+1; i++) {
        printf("%dx^(%d)+",xp.coefficients[i],i);
    }
    
    printf("\n");
   
    
    return xp;
}

struct polynome sous(struct polynome p,struct polynome q){
    struct polynome r;
    r.taille=p.taille;
    r.degre=p.degre;
    for (int j=0; j<p.degre+1; j++) {
        r.coefficients[j]=0;
    }
    for (int i=0; i<=p.degre; i++) {
        if(i>q.degre){
            r.coefficients[i]=p.coefficients[i];
        }else{

            r.coefficients[i]=p.coefficients[i]-q.coefficients[i];
        }
    }
    for (int i=0; i<=p.degre; i++) {
        printf("%dx^(%d)+",r.coefficients[i],i);
    }
    
    printf("\n");
   
    return r;
}


struct polynome prod(struct polynome p,struct polynome q){
    struct polynome prd;
    prd.degre=p.degre+q.degre;
    for (int j=0; j<q.degre; j++) {
        for (int i=0; i<p.degre; i++) {
            prd.coefficients[i+j]=prd.coefficients[j+i]+p.coefficients[i]*q.coefficients[j];
        }
        
    }
    
    
    return prd;
}





int main(){
    struct polynome p,q,d,prd;
    int dp=-1,dq=-1;
    int i;
    while(dp<0 || dq<0){
        if(dp<0){
            printf("veuillez entrer une valeur positive de dp\n");
            scanf("%d",&dp);
        }
        if(dq<0){
            printf("veuillez entrer une valeur positive de dq\n");
            scanf("%d",&dq);
        }
    }
    p.coefficients=(int *)calloc(dp, sizeof(int));
    d.coefficients=(int *)calloc(dq, sizeof(int));
    q.coefficients=(int *)calloc(dq, sizeof(int));
    prd.coefficients=(int *)calloc(dq+dp, sizeof(int));
    for ( i=0; i<dp; i++) {
        scanf("%d",&p.coefficients[i]);
    }
    for (i=0; i<dp; i++) {
        printf("%dx^(%d)+",p.coefficients[i],i);
    }
    printf("\n");
    

    for ( i=0; i<dq; i++) {
        scanf("%d",&q.coefficients[i]);
    }
    for (i=0; i<dq; i++) {
        printf("%dx^(%d)+\n",q.coefficients[i],i);
    }
    printf("\n");

    for (int j=0; j<p.degre+1; j++) {
        d.coefficients[j]=0;
    }
    p.degre=dp;
    p.taille=dp;
    d=sous(deriv(xf(p)),xf(deriv(p)));
    
    
    for (i=0; i<=dp-1; i++) {
        printf("%dx^(%d)+",d.coefficients[i],i);
    }
    
    printf("\n");
    for (i=0; i<=dp+dq; i++) {
        prd.coefficients[i]=0;
    }
    for (i=0; i<=dp+dq; i++) {
        printf("%dx^(%d)+",prod(p, q).coefficients[i],i);
    }
    
    printf("\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 50
int C_bin=0;
int C_mem=0;

unsigned binomial (int n, int p){
    if(p>n) {
        return 0;
    }
    if(p==0 || p==n){
        return 1;
    }
    C_bin++;
    return binomial(n-1, p)+binomial(n-1, p-1);
}

unsigned binomial_mem_aux(unsigned n, unsigned p,unsigned binomial_tab [N][N]){
    if(p>n) return 0;
    if(p==0 || p==n) return 1;
    C_mem++;
    binomial_tab[n][p]= binomial(n-1, p)+binomial(n-1, p-1);
    
    return binomial_tab[n][p];
}
unsigned binomial_mem (unsigned n, unsigned p) {
      unsigned binomial_tab [N][N] = {0};
      return binomial_mem_aux (n, p, binomial_tab );
}


unsigned binomial_ter_aux(unsigned n, unsigned p,unsigned x){
    if (p>n){
        return 0;
    };
    if(p==0 || p==n){
        return x;
    };
    return binomial_ter_aux(n-1, p-1,n/p*x);
}


unsigned binomial_ter(unsigned n, unsigned p){
    
    return binomial_ter_aux(n-1, p-1,1);
    
    
}















int main(){
    int n,p;
   
    clock_t c=clock(),y,z;
    printf("veuillez entrer la valeur de n\n");
    scanf("%d",&n);
    while(n<0){
        printf("ERREUR: veuillez entrer une valeur positive\n");
        scanf("%d",&n);
    }
    printf("veuillez entrer la valeur de p\n");
    scanf("%d",&p);
    while(p<0){
        printf("ERREUR: veuillez entrer une valeur positive\n");
        scanf("%d",&p);
    }
    
    printf("n=%d p=%d\n",n,p);
    
    
    srand(time(NULL));
    printf("-le resultat est :%d\n-le nombre d'apelles est :%d\n %lu\n",binomial ( n,  p),C_bin,c);
    y=clock();
    printf("-le resultat est :%d\n-le nombre d'apelles est :%d\n %lu\n",binomial_mem ( n,  p),C_mem,y);
    z=clock();
    printf("%lu\n",z);
    printf("%d\n",binomial_ter(n,p));
}

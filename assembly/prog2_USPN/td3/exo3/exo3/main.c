#include <stdio.h>
#define N 50
unsigned binomial_mem (unsigned n, unsigned p);
unsigned binomial (unsigned n, unsigned p);

int main() {

    printf("%d\n",binomial (6, 2));
    return 0;
}


unsigned binomial (unsigned n, unsigned p){
    if(p>n) return 0;
    if(p==0 || p==n) return 1;
    return binomial(n-1, p)+binomial(n-1, p-1);
}

unsigned binomial_mem_aux(unsigned n, unsigned p,unsigned binomial_tab [N][N]){
    if(p>n) return 0;
    if(p==0 || p==n) return 1;
    binomial_tab[n][p]= binomial(n-1, p)+binomial(n-1, p-1);
    return binomial_tab[n][p];
}
unsigned binomial_mem (unsigned n, unsigned p) {
      unsigned binomial_tab [N][N] = {0};
      return binomial_mem_aux (n, p, binomial_tab );
}

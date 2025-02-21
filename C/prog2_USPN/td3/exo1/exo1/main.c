#include <stdio.h>
#include <stdlib.h>


double puissance_term_aux(double x,unsigned n,double y){
    if(n==0) return y;
    return puissance_term_aux(x,n-1,x*y);
    
    
}
double puissance_term (double x, unsigned n) {
    return puissance_term_aux(x,n,1);
}


int main() {

    printf("%f\n",puissance_term (2,2));
    return 0;
}

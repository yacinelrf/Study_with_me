#include <stdio.h>
#include <stdlib.h>

float produit_tab (float * t, unsigned n) {
            if (n == 0) return 1;
            return t[n-1] * produit_tab (t, n-1);
}

float produit_tab_term_aux(float * t, unsigned n,float x){
    if(n==0) return x;
    return produit_tab_term_aux(t,n-1,x*t[n-1]);
    
    
}
float produit_tab_term(float * t, unsigned n){
    return produit_tab_term_aux(t,n,t[n]);
}

int main() {
    float t[]={3,6,4,2};
    printf("%f\n",produit_tab_term(t,3));
    return 0;
}

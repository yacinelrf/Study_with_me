#include <stdio.h>

double puissance_Iter(double x,int n);
double puissance_Rec(double x,int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World! %.2lf\n",puissance_Iter(5, 3));
    printf(" %.2lf\n",puissance_Rec(3.6, 3));
    
    return 0;
}


double puissance_Iter(double x,int n){
    int i;
    double p=1;
    if(n==0){
        return p;
    }else{
        for (i=n;i>0;i--){
            p=p*x;;
        }
        return p;
    }
}

double puissance_Rec(double x,int n){
    if(n==0){
        return 1;
    }else{
        return x*puissance_Rec(x,n-1);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 3
typedef int matrice[N][N];

int main() {
    int x;
  
    matrice **m3=(int **)malloc(N*sizeof(int *));
    
    for(x=0;x<N;x++){
        m3=(int *)malloc(N*sizeof(int));
    }
    m3=NULL;
    
    matrice m1={{0,1,0},{0,0,1},{0,0,0}},m2={{0,1,0},{0,0,1},{0,0,0}},prod={0};
    
    
    
    int i,j,k;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            for (k=0; k<N; k++) {
                *(*(prod+i)+j)=*(*(m1+i)+k)**(*(m2+k)+j)+*(*(prod+i)+j);
            }
            printf("%d",*(*(prod+i)+j));
        }
        printf("\n");
    }
    
    
    

    
    return 0;
}

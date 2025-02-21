
#include <stdio.h>


void etw(int n){
    int i,j;
    for (i=0;i<n/2;i++){
        for(j=0;j<n/2;j++){
            if(i==0 || i==n/2-1 || j==n/2-1 || j==0){
                printf("*");
            }else{
                printf(" ");
            }
        }
        for(j=n/2;j<n;j++){
            if((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0) ){
                printf("0");
            }else{
                printf("+");
            }
        }
        printf("\n");
        
    }
    for (i=0;i<n/2;i++){
        for(j=n/2;j<n;j++){
            if((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0) ){
                printf("0");
            }else{
                printf("+");
            }
        }
        for(j=0;j<n/2;j++){
            if(i==0 || i==n/2-1 || j==n/2-1 || j==0){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
        
    }
}
void oups(int deb,int n){
    int i,j;
    for (i=deb;i<n;i++){
        for(j=0;j<n;j++){
            if((i%2!=0 && j%2==0)||(i%2==0 && j%2!=0) ){
                printf("+");
            }else{
                printf("0");
            }
        }
        printf("\n");
        
    }
}
//
//void table(int n){
//
//    char tab[70][70];
//    int i,j,deb=0,fin=n,orig_i,orig_j;
//    char c='a';
//    j=i=deb;
//    //d----g
//    while (fin >= deb) {
//            orig_i = i = deb;
//            orig_j = j = deb;
//
//            // Remplissage du bord supérieur
//            while (j <= fin) {
//                tab[i][j++] = c++;
//            }
//            j--;
//
//            // Remplissage du bord droit
//            while (i < fin) {
//                tab[++i][j] = c++;
//            }
//
//            // Remplissage du bord inférieur
//            while (j > deb) {
//                tab[i][--j] = c++;
//            }
//
//            // Remplissage du bord gauche
//            while (i > orig_i) {
//                tab[--i][j] = c++;
//            }
//
//            // Redéfinition des limites
//            deb++;
//            fin--;
//        }
//
//
//    }
//
//
//
//    for(i=0;i<n;i++){
//        for(j=0;j<n;j++){
//            printf("%c",tab[i][j]);
//        }
//        printf("\n");
//    }
//}
void table(int n) {
    char tab[70][70];
    int i, j, deb = 0, fin = n - 1;
    char c = 'a';
    int orig_i, orig_j;
    
    while (fin >= deb) {
        orig_i = i = deb;
        orig_j = j = deb;
        
        // Remplissage du bord supérieur
        while (j <= fin) {
            tab[i][j++] = c++;
        }
        j--;
        
        // Remplissage du bord droit
        while (i < fin) {
            tab[++i][j] = c++;
        }
        
        // Remplissage du bord inférieur
        while (j > deb) {
            tab[i][--j] = c++;
        }
        
        // Remplissage du bord gauche
        while (i > orig_i) {
            tab[--i][j] = c++;
        }
        
        // Redéfinition des limites
        deb++;
        fin--;
    }
    
    // Affichage de la table
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    etw(n);
    table(5);
    return 0;
}

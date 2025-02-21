#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void affiche_bin_rev(unsigned int n,int tab[50]);
void affiche_bin(int tab[50]);
int  affiche_bin_rec(int n);
void affiche_bin_rec2(int n,int i);

int main() {
    int tab[50];
    affiche_bin_rev(47,tab);
    affiche_bin(tab);
    printf("%d\n",affiche_bin_rec(47));
    affiche_bin_rec2(47,8);
    
    return 0;
}


void affiche_bin_rev(unsigned int n,int tab[50]){
    int i=0,j=0;
    while(n!=0){
        tab[i]=n%2;
        n=n/2;
        i++;
    }
    tab[i]=2;
    
    while(tab[j]!=2){
        printf("%d",tab[j]);
        j++;
    }
    printf("\n");
}

void affiche_bin(int tab[50]){
    int i=0,j=0;
    int tab2[50];
    while(tab[i+1]!=2){
        i++;
        j++;
    }
    while(j>=0){
        printf("%d",tab[j]);
        j--;
    }
    printf("\n");
    
    
}

int affiche_bin_rec(int n){
    if(n/2==0){
        return 1;
    }else{
        return affiche_bin_rec(n/2)*10+n%2;
    }
}

void affiche_bin_rec2(int n,int i){
    if(n/2==0){
        printf("%d",n%2);
    }else{
        affiche_bin_rec2(n/2,i--);
        printf("%d",n%2);
    }
    
}



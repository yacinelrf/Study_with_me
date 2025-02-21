#include <stdio.h>

//------------exo4_td1------------------
typedef struct{
    int j;
    int m;
    int a;
}
date;

typedef struct{
    char nom[30];
    date dt;
} individu;




int nbrjour(date date0){
    if(date0.m==2){
        if(date0.a%400==0 || ((date0.a%4==0 && date0.a%100!=0))){
            return 29;
        }
        else{
            return 28;
        }
    }
        else{
        switch(date0.m){
            case 1 :
            case 3 :
            case 5 :
            case 7 :
            case 8 :
            case 10:
            case 12:
                return 31;
                break;
            case 4 :
            case 6 :
            case 9 :
            case 11:
                return 30;
                break;
        }
                
        }
    return 0;

}


date lendemain(date date0){
    if(date0.j==nbrjour(date0)){
        date0.j=1;
        if(date0.m==12){
            date0.m=1;
            date0.a++;
        }else{
            date0.m++;
        }
        
    }else{
        date0.j++;
    }
    return date0;
}

int comparer_date(date date1,date date2){
    if(date1.a>date2.a){
        return 1;
    }
    if(date1.a<date2.a){
        return -1;
    }
    
    
    if(date1.a==date2.a){
        if(date1.m==date2.m){
            if(date1.j>date2.j){
                return 1;
            }
            if(date1.j<date2.j){
                return -1;
            }
            if(date1.j==date2.j){
                return 0;
            }
        }
        if(date1.m>date2.m){
            return 1;
        }
        if(date1.m<date2.m){
            return -1;
        }

    }
    
    return 0;
    
    
}




int ecart_date_rec(date date1,date date2){
    if (comparer_date(date1,date2)==0){
        return 0;
    }else{
        return 1+ecart_date_rec(date1,lendemain(date2));
    }
}

//--------------------------------------------------


struct commande {
     int numero; /* identification de la commande */
     float volume; /* volume de bois à traiter, en mètres cubes */
     date reception; /* date de livraison des grumes à la scierie */
};

int nbre_max_commande (date deb, struct commande tab_recu[4], int n){
    int i,j=0;
    struct commande  tab_triee[4];
    for(i=0;i<n;i++){
        if(comparer_date(tab_recu[i].reception, deb)==1){
            tab_triee[j].reception.a=tab_recu[i].reception.a;
            tab_triee[j].reception.j=tab_recu[i].reception.j;
            tab_triee[j].reception.m=tab_recu[i].reception.m;
            printf("%d\n",tab_recu[i].numero);
            deb=tab_recu[i].reception;
            j++;
        }
}
    return j;
}


int main() {
    int n;
    date dt={10,9,2009};
    printf("veuillez entrer le nombre de commondes\n");
    scanf("%d",&n);
    struct commande tab_triee[4]={{1,1,{9,9,2009}},{2,2,{10,10,2010}},{3,3,{11,11,2011}},{12,12,{12,12,2012}}};
    nbre_max_commande(dt, tab_triee, n);
    return 0;
}

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

int max(individu tab[],int n){
    date mind=tab[0].dt,maxd;
    int i;
    for(i=0;i<n-1;i++){
        if(comparer_date(tab[i].dt, tab[i+1].dt)==1){
            maxd=tab[i].dt;
            if(comparer_date(tab[i].dt,mind)==-1){
                mind=tab[i].dt;
            }
        }else{
            maxd=tab[i+1].dt;
            if(comparer_date(tab[i].dt,mind)==-1){
                mind=tab[i].dt;
            }
        };
    }
    return ecart_date_rec(maxd, mind);
}
int diff_age_max_bis(individu tab[],int n){
    date mind=tab[0].dt,maxd=tab[0].dt;
    int i,j=0;
    for(i=0;i<n-1;i++){
        if(comparer_date(tab[i].dt,maxd)==1){
            maxd=tab[i].dt;
            j=i;
        }
    }
    mind=maxd;
    for(i=0;i<=j;i++){
        if(comparer_date(tab[i].dt,mind)==-1){
            mind=tab[i].dt;
        }
    }
    return ecart_date_rec(maxd, mind);
}

int diff_age_max_bis_rec(individu tab[],int g,int d){
    date dt;
    if(d==g){
        return 0;
    }else{
        if(comparer_date(tab[d].dt, tab[g].dt)==1){
            diff_age_max_bis_rec(tab,g+1,d);
            return ecart_date_rec(tab[d].dt, tab[g].dt);

        }else{
            diff_age_max_bis_rec(tab,g,d-1);
            return ecart_date_rec(tab[d].dt, tab[g].dt);
            
        }
       
    }
    
    
}




//-----------------
int main() {
    int n;
    individu tab[4]={{"aa",{26,05,1999}},{"bb",{26,05,2005}},{"cc",{26,05,2001}},{"dd",{26,05,2009}}};
    printf("%d\n",max(tab, 4));
    printf("%d",diff_age_max_bis(tab,4));
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int j;
    int m;
    int a;
}
date;




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




int ecart_date_rec(date date1,date date2,int x){
    if (comparer_date(date1,date2)==0){
        printf("%d\n",x);
        return 0;
        
    }else{
        x++;
        return 1+ecart_date_rec(date1,lendemain(date2),x);
        
    }
}


int ecart_dates_term_aux(date debut, date fin, int acc){
    if (comparer_date(fin,debut)==0){
        return acc;
    }else{
        return ecart_dates_term_aux(lendemain(debut),fin, acc+1);
    }
}

int ecart_dates_term( date debut,  date fin) {
        if (comparer_date(debut, fin) > 0) {
        return (-1) * ecart_dates_term_aux(fin, debut, 0);
        }
        return ecart_dates_term_aux(debut, fin, 0);
}



int main(){
    date date1, date2;
    date1.j=26;
    date1.m=05;
    date1.a=2000;
    date2.j=26;
    date2.m=05;
    date2.a=1900;
    printf("%d\n",ecart_dates_term(date1,date2));
    
    
    
    
    return 0;
}


/*
Scrivere un programma C++ che presi in ingresso due valori L e R, stampi R 
quadrati di lato L, senza la base, come nel disegno sottostante in cui i valori 
letti sono L = 4 e R = 3 (la distanza tra un quadrato e il successivo è uguale 
a L). Si supponga che sia L che R siano strettamente positivi e in particolare 
che L ≥ 2.
*/
#include<iostream>
#define CAR 'x'

using namespace std;

int main (){
    int L, R, i, j, temp, cont=0;

    do{
        cout<<"Quanti quadrati volete stampare: ";
        cin>>R;
        cout<<"Dire quanto deve essere lungo il lato di un quadrato: ";
        cin>>L;
    } while(R<1 || L<2);

    temp = L*(R*2)-L;

    for(i=0;i<L;i++){ 
        for(j=0;j<temp;j++){
            if(i==0){
                if (cont>=L){ 
                    if(cont==L*2){
                        cout<<CAR;
                        cont=1;
                    } else {
                        cont++;
                        cout<<" ";
                    }
                } else{ 
                    cont++; 
                    cout<<CAR;
                }
            } else {
                cont++;
                if(cont==1 || cont==L){
                    cout<<CAR;
                } else if (cont==L*2){
                    cont=0;
                    cout<<" ";
                } else {
                    cout<<" ";
                }
            }
        }
        cont=0;
        cout<<"\n";

    }
}
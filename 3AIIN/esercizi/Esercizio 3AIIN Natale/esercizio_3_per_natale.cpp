#include<iostream>
#define CAR '0'; 


using namespace std;

int main (){
    int i, j, n; 

    do{
        cout<<"Dire un numero positivo: ";
        cin>>n;
    } while(n<0);

    for(i=0;i<n;i++){
        if(i==0 || i==n-1){ // stampa un'intera riga di CAR se siamo alla prima riga o all'ultima
            for(j=0;j<n;j++){
                cout<<CAR;
                cout<<" ";
            }
            cout<<endl;
        } else { // inzia stampare solo se non siamo sulla prima o l'ultima riga
            for(j=0; j<=i;j++){
                if(j==i){ // stampa se il numero di i è uguale al numero di j
                    cout<<CAR;
                    cout<<" ";
                } else { // stampa spazi quando la condizione di questo else non vale
                    cout<<"  ";
                }
            }
            cout<<"\n"; 
        }
    }
    return 0;
}
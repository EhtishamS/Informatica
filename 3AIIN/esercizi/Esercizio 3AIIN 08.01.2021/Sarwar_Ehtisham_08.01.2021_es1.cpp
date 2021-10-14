 /*
    Name: calcolatrice;
    Author: Sarwar Ehtisham;
    Date: 08/01/2021;
    Description: 
*/
#include<iostream>

#define Tappo '='

using namespace std;

int main(){
    char operatore;
    int operando2, risultato, flag=0;

    cout<<"inserire il primo operando: ";
    cin>>risultato;
    
    do{
        cout<<"Inserire il operatore (per terminare utilizzare =): ";
        cin>>operatore;
        
        if(operatore != Tappo){
            cout<<"inserire un'altro operando: ";
            cin>>operando2;
        }

        switch (operatore) {
        case '+':
            risultato +=operando2;
            break;
        case '-':
            risultato -=operando2;
            break;
        case '/':
            if(operando2 == 0){
                cout<<"Errore hai provato a fare la divisione per 0!";
                flag=1;
            } else {
                risultato /=operando2;
            }
            break;
        case '*':
            risultato *= operando2;
            break;
        }
    
    } while(operatore != Tappo && flag ==0);

    cout<<"\nIl risultato finale e il seguente: "<<risultato<<endl; 
    
    return 0;
}

/*      

    Name: Sarwar_Ehtisham_07122020.cpp      
    Author: Sarwar Ehtisham     
    Date: 07/12/20 7:27      
    Description:       
    Scrivi un pgm C++ che calcola il fattoriale di un numero naturale.       
    Esegui un controllo dell'input.      
    Definizione di fattoriale      
    0! = 1      
    n! = 1 * 2 * 3 * 4 * ..... * n

*/
#include<iostream>

using namespace std;

int main() {
    int n, count=1, prod=1;

    do{
        cout<<"Inserire un numero(numero>0): ";
        cin>>n;
    }while(n<0);

    while(count<=n){
        prod*=count;
        count++;
    }

    cout<<"Il fattoriale di "<<n<<" e'"<<prod;
    
    return 0;
}
/*
    Scrivi un pgm C++ che, letti da tastiera due numeri naturali m ed n (esegui un controllo dell'input), calcoli  la potenza m^n, se esiste.
    Ti ricordo:
    se n = 0 e m = 0 l'espressione non ha significato
    se n = 0 e m != 0 l'la potenza vale 1
    In generale: m^n = m*m*...*m (n volte)
*/
#include<iostream>

using namespace std;

int main (){
    int n, m, pot;

    do{
        cout<<"Inserire la base e l'esponente: ";
        cin>>m>>n;
    }while(m<0 || n<0);

    if(n==0 && m==0){
        cout<<"L'espressione non ha significato";
    } else if (n==0 && m!=0){
        cout<<"La potenza di "<<m<<" elevato alla "<<n<<" vale= 1";
    } else {
        pot=m;
        for(int i=1;i<n;i++){
            pot*=m;
        }
        cout<<"La potenza di "<<m<<" elevato alla "<<n<<" vale = "<<pot;
    }

    return 0;
}
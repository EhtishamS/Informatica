/*
Scrivi un pgm C++ che stampa il k-esimo termine della successione di Fibonacci definita come: 

S0 = 1;
S1 = 1;
Sn = Sn-1 + Sn-2;   per n>=2
*/
#include<iostream>

using namespace std;

int main(){
    int s0=1, s1=1, sn=1, k;

    do{
        cout<<"Inserire un numero (numero>0): ";
        cin>>k;
    }while(k<=0);

    for(int i=1;i<k;i++){
        sn=s1+s0;
        s0=s1;
        s1=sn;
    }
    cout<<"Il termine "<<k<<" della successione di fibonacci e' = "<<sn;

    return 0;
}
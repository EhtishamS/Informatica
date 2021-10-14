#include<iostream>
#define TAPPO -1

using namespace std;

int main () {
    int inizio, fine, sequenza_uno, n, cont=0, max=0, temp_inizio, temp_fine;

    do{
        cout<<"Inserire sequenza di 1 e 0: ";
        cin>>n;

        if(n==1){

            if(sequenza_uno==0){
            temp_inizio = cont+1;
            }

            sequenza_uno++;

            if(sequenza_uno>max){
                max=sequenza_uno;
                inizio = temp_inizio;
                fine = fine_inizio;
            }

        } else {
            if(sequenza_uno>0){
                temp_fine = cont;
            }

            sequenza_uno = 0;
        }

        cont++;
    } while(n!=TAPPO);

    cout<<"Lunghezza = "<<max<<"\nInizio = "<<inizio<<"\nFine = "<<fine;
    return 0;
}
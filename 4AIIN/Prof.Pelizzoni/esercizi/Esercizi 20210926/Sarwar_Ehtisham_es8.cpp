/*
Scrivi una funzione ricorsiva che calcola la somma degli elementi di un array di interi di numElem elementi.
*/
#include<iostream>

using namespace std;

int sommaVet(int v[], int numElem);

int main(){
	int vet[] = {1,3,4,5,2,6,3,10};
	int numElem = sizeof(vet)/sizeof(vet[0]);
	
	cout<<"La somma degli elementi del vettore e: "<<sommaVet(vet,numElem);
}

int sommaVet(int v[], int numElem){
	if(numElem==0){
		return 0;
	} else {
		return v[numElem-1]+sommaVet(v,numElem-1);
	}
}

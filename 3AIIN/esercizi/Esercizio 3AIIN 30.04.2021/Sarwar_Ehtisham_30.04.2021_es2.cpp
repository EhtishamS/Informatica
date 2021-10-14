#include<iostream>

using namespace std;

#define MAX 20

int sommaPosPari(int vet[], int numElem);

int main (){
	int vet[MAX], numElem, somma;
	
	do{
		cout<<"Inserire la dimensione del vettore: ";
		cin>>numElem;
	}while(numElem<=0 || numElem>MAX);
	
	for(int i=0;i<numElem;i++){
		cout<<"Inserire un numero interno per la cella ["<<i+1<<"]: ";
		cin>>vet[i];
	}
	
	
	somma = sommaPosPari(vet,numElem-1);
	
	cout<<"La somma delle posizioni pari e': "<<somma;
	return 0;
}

int sommaPosPari(int vet[], int numElem){
	if(numElem<0){
		return 0;
	} else if(numElem%2!=0){
		return vet[numElem]+sommaPosPari(vet, numElem-=1);
	} else {
		return sommaPosPari(vet, numElem-1);
	}
}


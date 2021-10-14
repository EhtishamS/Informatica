#include<iostream>

using namespace std;

#define MAX 20

int trovaElem(int vet[], int numElem, int elemCerca);

int main(){
	int vet[MAX], numElem, elemCerca, trovato;
	
	do{
		cout<<"Inserire la dimensione del vettore: ";
		cin>>numElem;
	}while(numElem<=0 || numElem>MAX);
	
	for(int i=0;i<numElem;i++){
		cout<<"Inserire un intero nella cella ["<<i+1<<"]: ";
		cin>>vet[i];
	}
	
	
	cout<<"Inserire l'elemento da cercare: ";
	cin>>elemCerca;
	
	trovato = trovaElem(vet,numElem-1,elemCerca);
	
	if(trovato!=0){
		cout<<"Trovato! nell'indice "<<trovato;
	} else{
		cout<<"Non trovato!";
	}
	
	return 0;
}

int trovaElem(int vet[], int numElem, int elemCerca){
	if(numElem<0){
		return 0;
	} else if(vet[numElem] == elemCerca){
		return numElem;
	} else {
		return trovaElem(vet,numElem-=1,elemCerca);
	}
}


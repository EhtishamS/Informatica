/*
Scrivi un sottopgm che dato un vettore di interi verifica se il vettore è ordinato in modo 
crescente. 

Questo sottopgm è una funzione o una procedura?

è una funzione.
*/

#include<iostream>

using namespace std;

int controlloVettoreCrescente(const int* vett, const int numElem);

int main(){
	int vett[] = {1,4,6,9,7};
	int numElem = sizeof(vett)/sizeof(vett[0]);
	
	if(!controlloVettoreCrescente(vett,numElem))
		cout<<"Il vettore e crescente!";
	else
		cout<<"Il vettore non e crescente!";
	return 0;
}

int controlloVettoreCrescente(const int* vett, const int numElem){
	
	for(int i=0;i<numElem-1;i++){
		if(vett[i]>vett[i+1]){
			return 1;
		}
	}
	
	return 0;
}


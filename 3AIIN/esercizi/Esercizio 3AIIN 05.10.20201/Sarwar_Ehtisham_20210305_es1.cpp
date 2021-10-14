#include<iostream>

#define MAX 100
using namespace std;

void insert(int v[], int numElem);
void vet(int w[], int numElem, int v[]);
int numPrimo(int num);

int main(){
	int v[MAX], numElem, w[MAX];
	
	do{
		cout<<"Dire la lunghezza del vettore: ";
		cin>>numElem;
	}while(numElem<1);
	
	insert(v, numElem);
	vet(w,numElem,v);
	
	return 0;
}

void insert(int v[], int numElem){
	int i, temp;
	
	for(i=0;i<numElem;i++){
		do{
			cout<<"Inserire un numero per la cella ["<<i<<"]: ";
			cin>>temp;
		}while(temp<2);
		v[i]=temp;
	}
}

void vet(int w[], int numElem, int v[]){
	int i, somma=0;
	
	for(i=0;i<numElem;i++){
		if(numPrimo(v[i])==1){
			somma+=v[i];
			w[i]=somma;
		} else {
			w[i]=somma;
		}
	}
	
	for(i=0;i<numElem;i++){
		cout<<w[i]<<" ";
	}
}

int numPrimo(int num){
	int divisore;
	for(divisore = 2;divisore<num;divisore++){
		if(num%divisore==0){
			return 1;
		}
	}
	return 0;
}

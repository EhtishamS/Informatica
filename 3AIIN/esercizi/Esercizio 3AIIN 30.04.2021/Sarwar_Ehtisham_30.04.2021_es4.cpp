#include<iostream>

using namespace std;

#define MAX 20

int trovaMin(int vet[], int numElem, int min);

int main(){
	int min=0, numElem, vet[MAX];
	
	do{
		cout<<"Inserire la dimensione del vettore: ";
		cin>>numElem;
	}while(numElem<=0 || numElem>MAX);
	
	for(int i=0;i<numElem;i++){
		cout<<"Inserire un elemento per cella ["<<i+1<<"]: ";
		cin>>vet[i];
	}
	
	min = trovaMin(vet,numElem-1,vet[numElem-1]);
	
	cout<<"Il minore elemento di tutti e: "<<min;
	
	return 0;
}

int trovaMin(int vet[], int numElem, int min){
	if(numElem<0){
		return min;
	} else if(min>vet[numElem]){
		return trovaMin(vet,numElem-1,vet[numElem]);
    } else {
		return trovaMin(vet,numElem-1,min);
	}
}


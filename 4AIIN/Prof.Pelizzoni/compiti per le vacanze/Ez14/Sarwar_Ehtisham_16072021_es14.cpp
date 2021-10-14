#include<iostream>

using namespace std;

#define MAX 100

void inserimento(int vet[],int numElem);
void shuffle(int A[], int B[], int C[], int numElem);
void visualizza(int vet[], int numElem);

int main(){
	int A[MAX], B[MAX];
	int numElem;
	
	do{
		cout<<"Inserire il numero di elementi che vuole inserire negli array: ";
		cin>>numElem;
	}while(numElem<=0 || numElem>MAX);
	
	cout<<"\nINSERIMENTO VETTORE 1:\n";
	inserimento(A,numElem);
	cout<<"\nINSERIMENTO VETTORE 2:\n";
	inserimento(B,numElem);
	
	int *C = new int [numElem*2];
	
	shuffle(A,B,C,numElem);
	
	cout<<"\nOUTPUT VETTORE 3:";
	visualizza(C,numElem*2);
	
}

void inserimento(int vet[],int numElem){
	for(int i=0;i<numElem;i++){
		cout<<"Inserire l'elemento per ["<<i+1<<"]: ";
		cin>>vet[i];
	}
}

void shuffle(int A[], int B[], int C[], int numElem){
	int contA = 0, contB = 0;
	
	for(int i=0;i<numElem*2;i++){
		if(i%2==0){
			*(C+i) = A[contA];
			contA++;
		} else {
			*(C+i) = B[contB];
			contB++;
		}
	}
}

void visualizza(int *C, int numElem){
	cout<<"\n";
	for(int i=0;i<numElem;i++){
		cout<<C[i]<<" ";
	}
}

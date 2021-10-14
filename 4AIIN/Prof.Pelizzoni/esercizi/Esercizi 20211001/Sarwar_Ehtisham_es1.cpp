#include<iostream>

using namespace std;

#define MAX_DIM 5

void insert(double *vett[], int *numElem);
double* sortDec(double *vett[], int numElem);
void stampa1(double *vett[], int numElem);
void stampa2(double *vett[], double *vetDec, int numElem);

int main(){
	double *vett[MAX_DIM];
	int numElem;
	double *vetDec;
	
	insert(vett,&numElem);
	stampa1(vett,numElem);
	vetDec = sortDec(vett,numElem);
	stampa2(vett,vetDec,numElem);
	return 0;
}

void insert(double *vett[], int *numElem){
	do{
		cout<<"Inserire la lunghezza del vettore: ";
		cin>>*numElem;
	}while(*numElem<=0 || *numElem>MAX_DIM);
	
	cout<<"\nINSERIMENTO:\n";
	double num;
	for(int i=0;i<*numElem;i++){
		cout<<"Inserire un valore: ";
		cin>>num;
		*(vett+i) =new double;
		*vett[i] = num;
	}
}

double* sortDec(double *vett[], int numElem){
	int max;
	
	double *vetDec = new double[numElem];
	
	for(int i=0;i<numElem;i++){
		vetDec[i] = *vett[i];
	}
	
	for(int i=0;i<numElem-1;i++){
		max = i;
		for(int j=i+1;j<numElem;j++){
			if(vetDec[max]<vetDec[j])
				max = j;
		}
		double num = vetDec[i];
		vetDec[i] = vetDec[max];
		vetDec[max] = num;
	}
	
	return vetDec;
}

void stampa1(double *vett[], int numElem){
	cout<<"\nSTAMPA:\n";
	
	for(int i=0;i<numElem;i++){
		cout<<*vett[i]<<" ";
	}
}

void stampa2(double *vett[], double *vetDec, int numElem){
	cout<<"\nSTAMPA:\n";
	
	for(int i=0;i<numElem;i++){
		cout<<*vett[i]<<" ";
	}
	
	cout<<"\n";
	
	for(int i=0;i<numElem;i++){
		cout<<vetDec[i]<<" ";
	}
}

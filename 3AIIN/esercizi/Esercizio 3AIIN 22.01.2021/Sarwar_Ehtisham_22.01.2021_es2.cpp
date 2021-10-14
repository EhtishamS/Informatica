#include<iostream>
#define MAX 100
using namespace std;

int main (){
	int v[MAX], numElem, i, m, temp;
	
	do{
		cout<<"Inserire la lunghezza del vettore: ";
		cin>>numElem;
	}while(numElem<0 || numElem>MAX);
	
	cout<<"Di quando devono essere spostati gli elementi: ";
	cin>>m;
	
	for(i=0;i<numElem;i++){
		cout<<"Inserire il valore nella cella ["<<i<<"]: ";
		cin>>v[i];
	}
	
	for(i=0;i<numElem/2;i++){
		temp=v[i];
		v[i]=v[i+m];
		v[i+m]=temp;	
	}
	
	for(i=0;i<numElem;i++){
		cout<<v[i]<<" ";
	}
	
	return 0;
}

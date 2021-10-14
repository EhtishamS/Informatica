#include<iostream>

using namespace std;

int main (){
	int k, somma_fattoriale, i, fattoriale=1;

	do{
		cout<<"Inserire un valore: ";
		cin>>k;
	}while(k<=0);
	
	for(i=1;i<=k;i++){
		fattoriale = fattoriale *i;
		somma_fattoriale = somma_fattoriale + fattoriale;
		cout<<somma_fattoriale<<endl;
	}
	cout<<"fattoriale e' questo: "<<somma_fattoriale;
}

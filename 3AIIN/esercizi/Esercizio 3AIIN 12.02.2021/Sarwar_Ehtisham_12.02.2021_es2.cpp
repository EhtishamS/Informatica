#include<iostream>

using namespace std;
int potenza(int n, int pot_prec);

int main (){
	int ris, n, i, a, potenza_prec, sommatoria;
	
	
	do{
		cout<<"Inserire la base (>0): ";
		cin>>a;
		cout<<"Inserire l'esponente massimo(>0): ";
		cin>>n;
	} while(a<=0 || n<=0);
	
	
	potenza_prec=a;
	
	for(i=0;i<=n;i++){
		if(i<2){
			ris = potenza(a,i);
			ris--;
			sommatoria +=ris;
		} else {
			ris = potenza(a,potenza_prec);
			potenza_prec = ris;
			ris--;
			sommatoria +=ris;
		}
	}
	
	cout<<"\nRisulatato della sommatoria e: "<<sommatoria; 
}

int potenza(int n, int pot_prec){
	int risultato; 
	
	risultato = n*pot_prec;
	
	return risultato;
}

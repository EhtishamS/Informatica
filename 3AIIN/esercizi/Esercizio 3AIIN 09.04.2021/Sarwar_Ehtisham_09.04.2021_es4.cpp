#include<iostream>

using namespace std;

unsigned long long int coeffiecienteBinominale(int esp);
unsigned long long int c(int n, int k);
unsigned long long int fattoriale(int x);

int main(){
	int esp;
	do{
		cout<<"Inserire l'esponenete: ";
		cin>>esp;
	}while(esp<=0);
	
	cout<<"Il coefficient binominale e: "<<coeffiecienteBinominale(esp);
	
	return 0;
}

unsigned long long int coeffiecienteBinominale(int esp){
	unsigned long long int risultato=0;
	int i;
	
	for(i=0;i<=esp;i++){
		risultato +=c(esp,i); 
	}
	
	return risultato; 
}

unsigned long long int c(int n, int k){
	unsigned long long int divisione, c;
	
	divisione = fattoriale(k) *fattoriale((n-k));
	c = fattoriale(n)/divisione;
	
	return c;
}

unsigned long long int fattoriale(int x){
	int i;
	unsigned long long int ris=1;
	
	for(i=1;i<=x;i++){
		ris*=i;
	}
	return ris;	
}



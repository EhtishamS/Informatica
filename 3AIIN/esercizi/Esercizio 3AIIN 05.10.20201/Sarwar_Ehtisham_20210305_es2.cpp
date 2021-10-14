#include<iostream>

using namespace std;

int quad(int n); 
int sommaQuad(int a, int b);

int main (){
	int a, b, sommaTot;
	
	do{
		cout<<"Inserire da quale numero fino a quale numero vuole vedere i quadrati: ";
		cin>>a>>b;
	}while(a>b || a<2 || (b-a)<=1 );
	
	sommaTot = sommaQuad(a,b);
	
	cout<<"Somma totale: "<<sommaTot;
	return 0;
}

int sommaQuad(int a, int b){
	int i, somma;
	for(i=a+1;i<b;i++){
		somma +=quad(i);
	}
	
	return somma;
}

int quad(int n){
	int i, somma=0, numDisp, numPrec=0;
	for(i=1;i<n;i++){
		numDisp=1;
		while(numDisp){
			if(numPrec%2!=0){
				somma+=numPrec;
				numDisp=0;
			}
			numPrec++;
		}
	}
	return somma;
}

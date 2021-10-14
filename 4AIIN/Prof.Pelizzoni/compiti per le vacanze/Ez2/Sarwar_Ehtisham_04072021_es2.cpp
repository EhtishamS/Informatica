/*
Scrivi un pgm C++ che legge tre interi positivi n, h e k, con h < k, genera un vettore v 
di n (<= DIM_MAX) numeri interi casuali compresi tra h e k (estremi inclusi); stampa il 
vettore v. 
Il pgm successivamente costruisce e stampa un altro vettore w di n elementi, i cui 
elementi wi siano dati dal numero di elementi di v multipli di vi.

Esempio: Supponiamo che i due interi lett in input siano n=10, h = 2 e k = 18. Sia inoltre
V = (10, 6, 5, 2, 7, 9, 3, 5, 15, 18, 17, 18) il vettore di n = 12 numeri interi casuali 
compresi tra h = 2 e k = 18. Allora il vettore W sarà il seguente:
W = {1, 3, 4, 5, 1, 3, 6, 4, 1, 2, 1, 2).

*/

#include<iostream>
#include<time.h>
#include<string>
#include<stdlib.h>

using namespace std;

#define MAX 100

void inizializzaW(int w[]);
void inserimentoV(int v[], int n, int h, int k);
void costruzioneW(const int v[], int w[], int n);
void stampa(int v[], int n);

int main(){
	int v[MAX], w[MAX], n, h, k;
	
	srand(time(NULL));
	
	inizializzaW(w);
	
	do{
		cout<<"Inserire la lunghezza del vettore: ";
		cin>>n;
		cout<<"Inserire un intervallo: ";
		cin>>h>>k;
	}while(n<=0 || n>MAX || h<1 || k<=h);
	
	inserimentoV(v,n,h,k);
	costruzioneW(v,w,n);
	
	cout<<"\n\nStampa del vettore v: "<<endl;
	stampa(v,n);
	
	cout<<"\n\nStampa del vettore w: "<<endl;
	stampa(w,n);
	
	return 0;
}

void inizializzaW(int w[]){ 
	for(int i=0;i<MAX;i++){
		w[i] = 0;
	}
}

void inserimentoV(int v[], int n, int h, int k){ // inserisce all'interno di v elementi casuali tra h e k
	for(int i=0;i<n;i++){
		v[i] = rand()% (k-h+1)+h;
	}
}

void costruzioneW(const int v[], int w[], int n){ // controlla tutti i multipli e usa le celle di w[i] come contatori per celle di v[i]
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[j]>=v[i] && v[j]%v[i] == 0)
				w[i]++;
		}
	}
}

void stampa(int v[], int n){
	for(int i=0;i<n;i++){
		cout<<v[i]<<" ";
	}
}


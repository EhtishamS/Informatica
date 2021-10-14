/*
Scrivere una funzione ricorsiva che calcola, dati due numeri interi M(>0) ed N(>=0), la potenza M^N.
*/
#include<iostream>

using namespace std;

int calcPotenza(int m, int n);

int main(){
	int m = 10;
	int n = 0;
	
	cout<<m<<" elevato alla "<<n<<" e uguale a: "<<calcPotenza(m,n);
	return 0;
}

int calcPotenza(int m, int n){
	if(n==0){
		return 0;
	} else if(n==1){
		return m;
	} else {
		return m*calcPotenza(m,n-1);
	}
}

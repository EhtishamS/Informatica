#include<iostream>

using namespace std;

#define DIM_MAX 10

int occorr(const int vett[], int n, int c);

int main(){
	int vett[DIM_MAX] = {5,2,5,1,5,5,2};
	int numElem = sizeof(vett)/sizeof(vett[0]);
	int n=4, c=5, contaC;
	
	
	contaC = occorr(vett,n,c);
	
	cout<<"Il numero "<<c<<" e presente nel vettore "<<contaC<<" volte.";
	
	return 0;
}

int occorr(const int vett[], int n, int c){
	if(n==-1)
		return 0;
	else {
		if(vett[n]==c)
			return occorr(vett,n-1,c)+1;	
		else 
			return occorr(vett,n-1,c);
	}
}


#include<iostream>

using namespace std;

double somma(double a, int i);

int main(){
	int n, i=1;
	double a, sum=0;
	
	do{
		cout<<"Inserire da che valore vuole partire: ";
		cin>>a;
		cout<<"Inserire quante iterazioni vuole fare: ";
		cin>>n;
	}while(a<=0);
	
	
	sum = somma(a,n);
	
	cout<<"somma: "<<sum;
	return 0;
}

double somma(double a, int i){
	if(i==0){
		return 0;
	} else {
		return (a-(i/a))+somma(a,i-1);
	}
}


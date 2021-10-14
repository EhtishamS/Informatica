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
	
	while(i<=n){
		sum = sum+somma(a,i);
		i++;
	}
	
	cout<<"somma: "<<sum;
	return 0;
}

double somma(double a, int i){
	double sum;
	sum = a-(i/a);
	return sum;
}


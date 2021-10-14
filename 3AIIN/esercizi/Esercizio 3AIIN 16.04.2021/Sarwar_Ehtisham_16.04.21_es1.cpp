#include<iostream>

using namespace std;

int somma(int num);

int main(){
	int i=0, num, sum=0;
	
	do{
		cout<<"Inserire un numero: ";
		cin>>num;
	}while(num<=0);
	
	sum = somma(num);
	
	cout<<"somma: "<<sum;
	return 0;
}

int somma(int num){
	if(num==0){
		return 0;
	} else {
		return num + somma(num-1);
	}
}

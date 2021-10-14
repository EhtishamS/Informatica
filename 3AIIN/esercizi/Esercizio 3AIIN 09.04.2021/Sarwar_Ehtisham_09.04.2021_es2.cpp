#include<iostream>
#include<math.h>

using namespace std;

#define E 0.007

double radice(int x); 	

int main(){
	double x, rad;
	do{
		cout<<"Inserire un valore di cui vuole calcolare la radice quadrata: ";
		cin>>x;
	}while(x<=0);
	
	rad = radice(x);
	
	cout<<"La radice di "<<x<<" e "<<rad;
	return 0;
}

double radice(int x){
	double yCorrente, yPrecedente=x, differenza;
	yCorrente = (0.5) * (yPrecedente+(x/yPrecedente));
	
//	cout<<"\nPrecendente: "<<yPrecedente<<" Corrente: "<<yCorrente;
	
	while(differenza = fabs(yCorrente-yPrecedente)>E){
		yPrecedente=yCorrente;
		yCorrente = (0.5) * (yPrecedente+(x/yPrecedente));
//		cout<<"\nPrecendente: "<<yPrecedente<<"Corrente: "<<yCorrente;
	}
	
	return yCorrente;
}


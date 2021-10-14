/*
consegna:
Scrivere una procedura che presi in input un carattere c e un intero dispari n (letti nel 
main()), stampa una forma, simile a una clessidra, come si deduce dai seguenti esempi 
(c = '*'): 
 n = 1 n = 3 n = 5   n = 7 
 *      ***  *****  ******* 
         *    ***    ***** 
        ***    *      *** 
              ***      * 
             *****    *** 
                     ***** 
                    *******
*/

#include<iostream>

using namespace std;

void printClessidra(char c, int n);

int main(){
	char c;
	int n;
	
	cout<<"Inserire un carattere: ";
	cin>>c;
	
	do{
		cout<<"Inserire un numero dispari: ";
		cin>>n;
	}while(n%2==0);
	
	printClessidra(c,n);
	
	return 0;
}

void printClessidra(char c, int n){ // aiuta a stampare la struttura di una clessidra
	int copyN = n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<copyN+((n-copyN)/2);j++){
			if(j<(n-copyN)/2)
				cout<<" ";
			else
				cout<<c;
		}
			
		if(i>=(n/2))
			copyN+=2;
		else 
			copyN-=2;

		cout<<endl;
	}
}

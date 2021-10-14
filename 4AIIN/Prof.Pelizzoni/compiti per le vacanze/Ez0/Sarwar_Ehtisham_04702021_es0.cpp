/*
consegna:
Scrivere un algoritmo (utilizza il linguaggio di progetto) che risolva il seguente 
problema: dati due numeri N > 10 e K > 0 inseriti dall’utente, si stampi quanti 
sono i numeri interi compresi tra 10 e N incluso, tali che la somma delle proprie 
cifre sia uguale a K e sia la prima che l’ultima cifra del numero siano dispari. 
Ad esempio con N = 100 e K = 8 la risposta sarebbe 4, poiché i numeri che soddisfano 
le condizioni elencate sono il 17, il 35, il 53 e il 71.
*/

#include <iostream>

using namespace std;

int controlloK(int N, int K);

int main() {
    int N, K, contK;
    do{
    	cout<<"Inserire fino a quale numero vuole analizzare: ";
    	cin>>N;
    	cout<<"Quale numero vuole ricercare: ";
    	cin>>K;
	}while(N<=10 || K<0); // controllo richiesto
	
	contK = controlloK(N,K);
	
	cout<<"I numeri tra 10 fino ad "<<N<<" che sono uguali a "<<K<<" sono: "<<contK;
	
	return 0;
}

int controlloK(int N, int K){ // questo sottoprogramma controlla quante volte e presente K.
	int resto, sum, num, contK=0;
	
	for(int i=10;i<=N;i++){ // va da 10 fino ad N incluso
		sum = 0;
		num = i;
		resto = num%10;
		
		if(resto%2!=0){ // controlla che l'ultima cifra del numero sia dispari
			sum+=resto;
			num/=10;
		
			while(num>0){ // continua fino a quando num e maggiore di 0 perché 1/10 e uguale a 0
				resto = num%10;
				
				if(num/10==0){ // dato che l'ultimo numero diviso 10 farà sempre 0 allora faccio questo controllo per vedere se il numero che voglio vedere sia l'ultimo oppure no
					if(resto%2==0) // vede che il numero sia paridispari
						sum = 0;
					else 
						sum+=resto;
				} else
					sum+=resto;
				
				num/=10;
			}
		}
		
		if(sum == K){ // controllo che somma sia uguale a k se lo e allora aumento il contatore altrimenti nulla.
			contK++;
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return contK;
}

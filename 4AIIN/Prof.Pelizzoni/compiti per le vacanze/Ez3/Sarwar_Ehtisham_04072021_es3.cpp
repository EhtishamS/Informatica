/*
Scrivi un pgm C++ che legge in input una stringa str composta da singole cifre 
numeriche alternate con i simboli “+” e “-”. Calcolare e stampare il valore 
dell’espressione aritmetica rappresentata da str. 
NOTA: il Calcolo deve essere svolto da un sottopgm. E’ una funzione? 
Esempio 
Sia str = “3 - 5 + 4 + 7 - 2”. Il valore dell’espressione rappresentato da str è 7. 
Sia str = “- 3 + 8 - 7 - 2”. Il valore dell’espressione rappresentato da S è -4.
*/

#include<iostream>
#include<string.h>

using namespace std;

#define MAX 100
#define MAXT 120

int risolutore(char espressione[]);
int lunghezza(char espressione[], int pos);

int main(){
	char espressione[MAX], temp[MAXT];
	int soluzione;
	
	do{
		cout<<"Inserire un espressione risolvere: ";
		cin.getline(temp,MAXT);
	}while(strlen(temp)>MAX);
	
	strcpy(espressione, temp);
	
	soluzione = risolutore(espressione);
	
	cout<<"\nLa soluzione e': "<<soluzione;
	return 0;
}

int risolutore(char espressione[]){ // calcola la soluzione dell'espressione e lo da in main
	int num = 0, molt=lunghezza(espressione, 0);
	int somma=1;
	
	for(int i=0;espressione[i];i++){ // dentro questo ciclo lavora in tal modo che riesca a lavorare con cifre oltre alle unità
		if(espressione[i]!=' '){
			if(espressione[i] >= '0' && espressione[i] <= '9'){
				if(somma)
					num += (espressione[i] - '0')*molt;
				else 
					num -= (espressione[i] - '0')*molt;
				molt /= 10;
			} else {
				molt = lunghezza(espressione, i+1);
				
				if(espressione[i] == '+'){
					somma=1;
				} else if(espressione[i] == '-'){
					somma=0;
				}
			}
		}
	}
	
	return num;
}

int lunghezza(char espressione[], int pos){ // calcola la lunghezza
	int molt=1;
	int stop = 1;
	for(int i=pos;espressione[i] && stop;i++){
		if(espressione[i]!=' '){
			if(espressione[i] >= '0' && espressione[i] <= '9'){
				molt*=10;
			} else {
				stop=0;
			}
		}
	}
	
	molt/=10;
	
	return molt;
}

/*
Scrivi un sottopgm che riceve peso (in kg) e altezza (in cm) in una variabile di tipo 
record e ritorna il BMI. 
Si legga una sequenza di coppie (peso, altezza) e per ciascuna coppia richiama il 
sottogm che calcola e restituisce il BMI. La sequenza termina quando viene letta la 
coppia (0, 0). 

Questo sottopgm è una funzione o una procedura? 

e una funzione
*/
#include<iostream>

using namespace std;

enum categorie{GMAGREZZA,SOTTOPESO,NORMOPESO,SOVRAPESO,OBCLI,OBCL2,OBCL3};

struct persona{
	double peso;
	double altezza;
};

int bmi(const persona soggetti);


int main(){
	persona soggetti;
	
	do{
		cout<<"Inserire l'altezza del soggetto: ";
		cin>>soggetti.altezza;
		cout<<"Inserire il peso del soggetto: ";
		cin>>soggetti.peso;
		if(soggetti.peso>0 && soggetti.altezza>0){
			cout<<bmi<<endl;
		}
	} while(soggetti.peso || soggetti.altezza);
	
	
	return 0;
}

int bmi(const persona soggetti){
	double ris = soggetti.peso * (soggetti.altezza*soggetti.altezza) / 100;
	
	if(ris<16.5)
		return 0;
	else if(ris>=16.0 && ris<=18.49)
		return 1;
	else if(ris>=18.5 && ris <=24.99)
		return 2;
	else if(ris>=25.0 && ris <=29.99)
		return 3;
	else if(ris>=30.0 && ris <=34.99)
		return 4;
	else if(ris>=35.0 && ris <=39.99)
		return 5;
		
	return 6;
}

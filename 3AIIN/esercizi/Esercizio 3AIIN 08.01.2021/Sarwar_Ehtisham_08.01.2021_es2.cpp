/*
	Name: Diametro_tondino;
    Author: Sarwar_Ehtisham;
    Date: 11/01/2021;
    Description:Dato in ingresso il diametro di tondini verificare se si applica lo sconto, se il pezzo è accettabile
    o se il pezzo verra scartato.
*/


#include<iostream>
#define DIAMETRO 30
#define PREZZO_PER_PEZZO 10.00
#define SCONTO 0.2
#define DIAMETRO_ACCETTABILE 0.5
#define DIAMENTRO_SCONTO 1
#define NUMERO_PEZZI 1

using namespace std;

int main (){
	double Diamentro_tondino, prezzo_totale=0, percentuale_pezzi_scartati;
	int pezzi_scartati=0, pezzi_accettati=0, pezzi_sconto=0;
	
	for(int i=1;i<=NUMERO_PEZZI;i++){
		do{
			cout<<"Inserire il diametro del tondino del pezzo ("<<i<<"): ";
			cin>>Diamentro_tondino;
		}while(Diamentro_tondino<=0);
		
		if((Diamentro_tondino>=DIAMETRO && Diamentro_tondino<=DIAMETRO+DIAMETRO_ACCETTABILE) || (Diamentro_tondino<=DIAMETRO && Diamentro_tondino>=DIAMETRO-DIAMETRO_ACCETTABILE)){
			prezzo_totale+=PREZZO_PER_PEZZO;
			pezzi_accettati++;
			cout<<"prezzo totale: "<<prezzo_totale<<" pezzi accettati: "<<pezzi_accettati<<endl;
		} else if((Diamentro_tondino>DIAMETRO+DIAMETRO_ACCETTABILE && Diamentro_tondino<=DIAMETRO+DIAMENTRO_SCONTO) || (Diamentro_tondino<DIAMETRO+DIAMETRO_ACCETTABILE && Diamentro_tondino>=DIAMETRO-DIAMENTRO_SCONTO)){
			prezzo_totale= prezzo_totale+(PREZZO_PER_PEZZO-(PREZZO_PER_PEZZO*SCONTO));
			pezzi_sconto++;
			cout<<"prezzo totale: "<<prezzo_totale<<" pezzi scontati: "<<pezzi_sconto<<endl;
		} else {
			pezzi_scartati++;
			cout<<"pezzi scartati: "<<pezzi_scartati<<endl;
		}
	}
	
	percentuale_pezzi_scartati=(pezzi_scartati*100)/NUMERO_PEZZI;
		
	cout<<"Il numero totale dei tondini accettati che aveva il diametro tra 29.5 e 30.5 e' uguale a: "<<pezzi_accettati<<endl;
	cout<<"Il numero totale dei tondini che hanno il diametro tra 29 e 31 e' uguale a: "<<pezzi_sconto<<endl;
	cout<<"La percentuale di pezzi scartati e' uguale a: "<<percentuale_pezzi_scartati<<"%"<<endl;
	cout<<"Il prezzo che il cliente deve pagare e' uguale a: "<<prezzo_totale<<" euro";
	
	return 0;
}

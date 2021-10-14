#include<iostream>

using namespace std;

#define MAX_PIATTI 100 
#define DIM_STR 25+1 

typedef struct { 
 	char nomePiatto [DIM_STR]; 
 	float costo ; 
 	int qta ; // quantità 
} piatto ; 
 
typedef struct { 
 	int giorno , mese , anno ; 
 	int ora , minuti ; 
} dataOra ; 
 
typedef struct { 
 	dataOra dataOrdine ; 
 	int numeroTavolo ; 
 	piatto piatti [MAX_PIATTI]; 
 	int piattiRichiesti; 
} ordine ;

void stampaOrdine(const ordine ordineSingolo);
float totaleOrdine(const ordine ordineSingolo);
void stampaOrdini(const ordine *ordini, int numElem, const dataOra dataOrdine, float S);
bool ordineInData(const ordine ordineSingolo, const dataOra dataOrdine);

int main(){
	ordine ordini [] = { 
 		{ 
 			{31 ,8 ,2020 ,14 ,30} , 
 			5, 
 			{ 
 				{" Penne ", 10, 2}, 
				{" Tortellini ", 12, 3}, 
				{" Tagliata ", 18, 1} 
 			}, 
 			3 
 		}, 
 		{ 
 			{31 ,8 ,2020 ,16 ,30} , 
 			7, 
 			{ 
 				{" Penne ", 10, 1}, 
 				{" Spaghetti ", 8, 1}, 
 				{" Stufato ", 22, 2}, 
 				{" Torta ", 4, 2} 
 			}, 
 			4 
 		}, 
 		{ 
 			{30 ,8 ,2020 ,16 ,30} , 
 			5, 
 			{ 
 				{" Cannelloni ", 10, 7}, 
 				{" Torta ", 8, 7} 
 			}, 
 			2 
 		} 
	};
	
	int numElem = 3;
	float s = 1.0;
	dataOra data;
	
	data.anno = 2020;
	data.mese = 8;
	data.giorno =31;
	data.ora = 14;
	data.minuti = 30;
	
	stampaOrdini(ordini,numElem,data,s);
	
	
	return 0;
}

void stampaOrdine(const ordine ordineSingolo){
	cout<<"Data ordine: "<<ordineSingolo.dataOrdine.ora<<":"<<ordineSingolo.dataOrdine.minuti<<" ";
	cout<<ordineSingolo.dataOrdine.giorno<<"/"<<ordineSingolo.dataOrdine.mese<<"/"<<ordineSingolo.dataOrdine.anno;
	
	cout<<"\nIl tavolo riservato: "<<ordineSingolo.numeroTavolo;
	
	cout<<"\nPiatti richiesti:";
	
	for(int i=0;i<ordineSingolo.piattiRichiesti;i++){
		cout<<"\n-"<<ordineSingolo.piatti[i].nomePiatto;
	}
	
	cout<<"\ncosto totale ordine: "<< totaleOrdine(ordineSingolo);
}

float totaleOrdine(const ordine ordineSingolo){
	float costoTotale = 0;
	
	for(int i=0;i<ordineSingolo.piattiRichiesti;i++){
		costoTotale += (ordineSingolo.piatti[i].costo*ordineSingolo.piatti[i].qta);
	}
	
	return costoTotale;
}

void stampaOrdini(const ordine *ordini, int numElem, const dataOra dataOrdine, float S){
	for(int i=0;i<numElem;i++){
		if(ordineInData(ordini[i],dataOrdine)==1 && totaleOrdine(ordini[i])>S){
			stampaOrdine(ordini[i]);
		}
	}
}

bool ordineInData(const ordine ordineSingolo, const dataOra dataOrdine){
	if(ordineSingolo.dataOrdine.anno == dataOrdine.anno && ordineSingolo.dataOrdine.mese == dataOrdine.mese && ordineSingolo.dataOrdine.giorno == dataOrdine.giorno && ordineSingolo.dataOrdine.ora == dataOrdine.ora && ordineSingolo.dataOrdine.minuti == dataOrdine.minuti){
		return true;
	}
	
	return false;
}

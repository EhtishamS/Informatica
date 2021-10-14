#include<iostream>
#include<string>

#define DIM_STR_NOME 21 
#define DIM_STR_TITOLO 31 
#define MAX_LIBRI 10 

using namespace std;

// tutti i tipi struct vengono definitie cui
struct data{     
	int giorno;     
	int mese;     
	int anno; 
}; 

struct libro{     
	char cognome[DIM_STR_NOME];     
	char nome[DIM_STR_NOME];        
	char titolo [DIM_STR_TITOLO];     
	double costo; 
	data dataPubblicazione; 
}; 

struct libreria{
	libro scaffale[MAX_LIBRI];
	int numLibri;
};

// Queste sono tutte le funzioni
int insert(libreria & lib);
libro leggiLibro();
void stampa(struct libreria & lib);
double calcoloCosto(libreria costo);
libreria autorePerCar(libreria nome, char carattere);

int main(){
	libreria lib;
	lib.numLibri = 0;
	int bene, scelta;
	
	do{
		cout<<"\n\n";
		cout<<"1. SE VUOLE INSERIRE UN NUOVO LIBRO";
		cout<<"\n2. SE VUOI STAMPARE TUTTI I LIBRI PRESENTI SULLO SCAFFALE";
		cout<<"\n3. SE VUOI CALCOLARE IL COSTO DI TUTTI I LIBRI PRESENTI SULLO SCAFFALE";
		cout<<"\n4. SE VUOI COPPIARE I DATI DI AUTORE IL QUALE NOME INIZIA PER UN CARATTERE CHE DARAI TU";
		cout<<"\n0. FINE LAVORO\n";
		cin>>scelta;
		cout<<"\n\n";
		
		switch(scelta){
			case 1:
				bene = insert(lib);	
				if(bene){
					cout<<"l'inserimento e' andato a buon fine";
				}
				break;
			case 2:
				stampa(lib);
				break;
			case 3:
				double costo;
				costo = calcoloCosto(lib);
				cout<<"Il costo dei libri totale e di "<<costo<<" euro";
				break;
			case 4:
				struct libreria autore;
				char carattere;
				cout<<"Inserire un carattere: ";
				cin>>carattere;
				autore = autorePerCar(lib,carattere);
				stampa(autore);
				break;
		}
	} while(scelta != 0);
	
	cout<<"fine lavoro!";
	return 0;	
}

int insert(libreria & lib){
	int AndataBene = 1;
	
	if(lib.numLibri<MAX_LIBRI){
		lib.scaffale[lib.numLibri] = leggiLibro();
		lib.numLibri = lib.numLibri + 1;
		
	} else {
		cout<<"Non c'e' posto!";
		AndataBene = 0;
	}
	
	return AndataBene;
}

libro leggiLibro(){
	libro l;
	
	cout<<"Inserire il cognome dell'autore: ";
	cin>>l.cognome;
	
	cout<<"Inserire il nome dell'autore: ";
	cin>>l.nome;
	cin.ignore(100, '\n');
	
	cout<<"Inserire il titolo del libro: ";
	gets(l.titolo);
	
	cout<<"Inserire il costo del libro: ";
	cin>>l.costo;

	cout<<"Inserire la data di pubblizione (anno mese giorno): ";
	cin>>l.dataPubblicazione.anno>>l.dataPubblicazione.mese>>l.dataPubblicazione.giorno;
	
	return l;
}

void stampa(struct libreria & lib){
	int i;
	
	for(i=0;i<lib.numLibri;i++){
		cout<<"\ncognome dell autore ["<<i+1<<"]: "<<lib.scaffale[i].cognome;
		cout<<"\nnome dell autore ["<<i+1<<"]: "<<lib.scaffale[i].nome;
		cout<<"\nIl titolo del libro ["<<i+1<<"]: "<<lib.scaffale[i].titolo;
		cout<<"\nIl costo del libro ["<<i+1<<"]: "<<lib.scaffale[i].costo;
		cout<<"\nLa data di pubblicazione ["<<i+1<<"]: "<<lib.scaffale[i].dataPubblicazione.anno<<" "<<lib.scaffale[i].dataPubblicazione.mese<<" "<<lib.scaffale[i].dataPubblicazione.giorno;
		cout<<"\n\n";
	}
}

double calcoloCosto(struct libreria costo){
	int i;
	double costoTot= 0.0;
	
	for(i=0;i<costo.numLibri;i++){
		costoTot += costo.scaffale[i].costo; 
	}
	
	return costoTot;
}

libreria autorePerCar(libreria nome, char carattere){
	struct libreria car;
	int i, j;
	car.numLibri = 0;
		
	for(i=0;i<nome.numLibri;i++){
		if(nome.scaffale[i].cognome[0]==carattere){
			car.scaffale[car.numLibri] = nome.scaffale[i];
			car.numLibri++; 
		}
	}
	
	return car;
}

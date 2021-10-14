#include<iostream>
#include<string.h>

using namespace std;

#define DIM_STR_TITOLO 20+1
#define DIM_STR_PITTORE 18+1
#define DIM_STR_GENERE 15+1
#define TEMP 80
#define MAX_PITTORI 5
#define MAX_QUADRI 5

typedef struct{
	char titolo[DIM_STR_TITOLO];
	char autore[DIM_STR_PITTORE];
	double altezza;
	double larghezza;
}quadro;

typedef struct{
	char nomePittore[DIM_STR_PITTORE];
	char genere[DIM_STR_GENERE];
}pittore;

void leggiPittori(pittore artisti[], int &numPittori);
void leggiQuadri(quadro disegni[], int &numQuadri);
void stampaQuadriQuadrati(quadro disegni[], int numQuadri);
void stampaQuadro(quadro disegno);
int numQuadriPittore(quadro disegni[], int numQuadri, char namePittore[]);
void numQuadriPerOgniPittore(quadro disegni[], int numQuadri, pittore artisti[], int numPittori);

int main(){
	pittore artisti[MAX_PITTORI];
	int numPittori = 0;
	
	quadro disegni[MAX_QUADRI];
	int numQuadri = 0;
	int numeroQuadri;
	
	char namePittore[DIM_STR_PITTORE];
	leggiPittori(artisti, numPittori);
	leggiQuadri(disegni, numQuadri);
	stampaQuadriQuadrati(disegni,numQuadri);
	cout<<"\nInserire il nome del pittore: ";
	cin.getline(namePittore, DIM_STR_PITTORE);
	
	numeroQuadri = numQuadriPittore(disegni, numQuadri, namePittore);
	
	if(numeroQuadri == 0){
		cout<<"\nNome non esistente";
	} else {
		cout<<"\nIl pittore "<<namePittore<<" ha fatto "<<numeroQuadri;
	}
	
	numQuadriPerOgniPittore(disegni,numQuadri, artisti,numPittori);

	return 0;
}

void leggiPittori(pittore artisti[], int &numPittori){
	char temp[TEMP];
	do{
		cout<<"Quanti autori vuole inserire: ";
		cin>>numPittori;
	}while(numPittori<=0 || numPittori > MAX_PITTORI);
	
	for(int i=0;i<numPittori;i++){
		cout<<"\nPittore ["<<i+1<<"] ";
		
		//controllo che il nome del pittore sia nei limiti
		cin.ignore(100, '\n');
		cout<<"\nInserire il nome del pittore: ";
		cin.getline(temp, TEMP);
		
		while(strlen(temp)>DIM_STR_PITTORE){
			cout<<"Reinserire il nome del pittore: ";
			cin.getline(temp, TEMP);
		}
		strcpy(artisti[i].nomePittore, temp);
		
		//controllo che il genere sia nei limiti
		cout<<"Inserire il genere del pittore: ";
		cin.getline(temp, TEMP);
		
		while(strlen(temp)>DIM_STR_GENERE){
			cout<<"Reinserire il genere del pittore: ";
			cin.getline(temp, TEMP);
		}
		strcpy(artisti[i].genere, temp);
	}
}

void leggiQuadri(quadro disegni[], int &numQuadri){
	char temp[TEMP];
	
	do{
		cout<<"\nQuanti quadri vuoi inserire: ";
		cin>>numQuadri;
	}while(numQuadri<=0 || numQuadri>MAX_QUADRI);
	
	for(int i=0;i<numQuadri;i++){
		cout<<"\nQuadro ["<<i+1<<"]";
		
		//controllo che il titolo del quadro siano nel limite
		cout<<"\nInserire il totolo del quadro: ";
		cin.ignore(100, '\n');
		cin.getline(temp, TEMP);
		
		while(strlen(temp)>DIM_STR_TITOLO){
			cout<<"Reinserire il titolo del quadro: ";
			cin.getline(temp, TEMP);
		}
		strcpy(disegni[i].titolo, temp);
		
		//controllo che il totolo del quadro siano nel limite
		cout<<"Inserire il nome dell'autore del quadro: ";
		cin.getline(temp, TEMP);
		
		while(strlen(temp)>DIM_STR_PITTORE){
			cout<<"Reinserire il nome dell'autore del quadro: ";
			cin.getline(temp, TEMP);
		}
		strcpy(disegni[i].autore, temp);
		
		//Inserimento delle dimensioni del quadro
		do{
			cout<<"Inserire l'altezza del quadro: ";
			cin>>disegni[i].altezza;
		}while(disegni[i].altezza<=0);
		
		do{
			cout<<"Inserire la larghezza del quadro: ";
			cin>>disegni[i].larghezza;	
		}while(disegni[i].larghezza<=0);
		
	}
}

void stampaQuadriQuadrati(quadro disegni[], int numQuadri){
	
	for(int i=0;i<numQuadri;i++){
		if(disegni[i].altezza == disegni[i].larghezza){
			stampaQuadro(disegni[i]);
		}
	}
}

void stampaQuadro(quadro disegno){
	cout<<"\n\nIl titolo del quadro e': "<<disegno.titolo;
	cout<<"\nIl nome dell'autore dei questo quadro e': "<<disegno.autore;
	cout<<"\nAltezza del quadro: "<<disegno.altezza;
	cout<<"\nLarghezza del quadro: "<<disegno.larghezza;
}

int numQuadriPittore(quadro disegni[], int numQuadri, char namePittore[]){
	int contQuadr=0;
	
	for(int i=0;i<numQuadri;i++){
		if(strcmp(disegni[i].autore,namePittore)==0){
			contQuadr++;
		}
	}	
	return contQuadr;
}

void numQuadriPerOgniPittore(quadro disegni[], int numQuadri, pittore artisti[], int numPittori){
	int contQuadri[numPittori];
	
	for(int i=0;i<numPittori;i++){
		contQuadri[i]=0;
	}
	
	for(int i=0;i<numPittori;i++){
		for(int j=0;j<numQuadri;j++){
			if(strcmp(artisti[i].nomePittore,disegni[j].autore)==0){
				contQuadri[i]++;
			}
		}
	}
	
	cout<<"\nQuadri per pittori: \n";
	for(int i=0;i<numPittori;i++){
		cout<<"\n";
		cout<<"Pittore "<<artisti[i].nomePittore<<" ha fatto\t"<<contQuadri[i];
	}
}


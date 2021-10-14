#include<iostream>
#include<string.h>

using namespace std;

#define DIM_STR_TITOLO 30+1
#define DIM_STR_PITTORE 40+1
#define DIM_STR_GENERE 20+1
#define PITTORI 30+1
#define QUADRI 40+1

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

int menu();
int leggiPittori(pittore pittori[], int &numPittore);
int cercaPittore(pittore const pittori[], char artista[], int numPittori);
int leggiQuadri(quadro quadri[], int &numQuadro);
void stampaQuadriQuadrati(quadro const quadri[], const int numQuadro);
void numeroQuadro(quadro const quadri[], const int numQuadro, char nomePittore[]);
void numeroQuadri(quadro const quadri[], const int numQuadro, pittore const pittori[], const int numPittore);

int main(){
	quadro quadri[QUADRI];
	pittore pittori[PITTORI];
	int numQuadro = 0;
	int numPittore = 0;
	int scelta;
	int risultato;
	char nomePittore[DIM_STR_PITTORE];
	
	do{
		scelta = menu();
		
		switch(scelta){
			case 1:
				risultato = leggiPittori(pittori, numPittore);
				
				if(risultato)
					cout<<"\nInserimento terminato correttamente!\n";
				else 
					cout<<"\nErrore!\n";
				break;
			case 2:
				risultato = leggiQuadri(quadri, numQuadro);
				
				if(risultato)
					cout<<"\nInserimento terminato correttamente!\n";
				else
					cout<<"\nErrore!\n";
				break;
			case 3:
				stampaQuadriQuadrati(quadri, numQuadro);
				break;
			case 4:
				cin.ignore(100, '\n'):
				cout<<"Inserire il nome del pittore da ricercare: ";
				cin.getline(nomePittore, DIM_STR_PITTORE);
				
				numeroQuadro(quadri, numQuadro, nomePittore);
				break;
			case 5:
				numeroQuadri(quadri, numQuadro, pittori, numPittore);
				break;
		}
	}while(scelta!=0);
	
	cout<<"\nProgramma terminato!";
		
	return 0;
}

int menu(){
	int scelta;
	
	do{
		cout<<"\nScegliere tra le opzioni date:";
		cout<<"\n1. Leggi il pittore.";
		cout<<"\n2. Leggi il quadro.";
		cout<<"\n3. Stampare quadri di forma quadrata.";
		cout<<"\n4. Stampare il num quadri di un pittore.";
		cout<<"\n5. Stamapre il num quadri per ogni pittore.";
		cout<<"\n0. Fine lavoro.";
		cout<<"\nScegliere l'opzione:\n>";
		cin>>scelta;
	}while(scelta <0 || scelta>5);
	
	return scelta;
}

int leggiPittori(pittore pittori[], int &numPittore){
	char artista[PITTORI];
	
	if(numPittore<PITTORI){
		cout<<"\nINSERIMENTO PITTORE: \n";
	
		cin.ignore(100, '\n');
		do{
			cout<<"Inserire nome pittore: ";
			cin.getline(artista, PITTORI);
		}while(cercaPittore(pittori, artista, numPittore));
		
		strcpy(pittori[numPittore].nomePittore, artista);
		
		cout<<"Inserire genere pittore: ";
		cin.getline(pittori[numPittore].genere, PITTORI);
		numPittore++;
		return 1;
	}
	
	return 0;
}

int cercaPittore(pittore const pittori[], char artista[], int numPittori){
	for(int i=0;i<numPittori;i++){
		if(strcmp(pittori[i].nomePittore, artista) == 0){
			cout<<"\nEsiste gia' questo nome!\n";
			return 1;
		}
	}
	
	return 0;
}

int leggiQuadri(quadro quadri[], int &numQuadro){
	if(numQuadro<QUADRI){
		cout<<"\nLETTURA DEL QUADRO:\n";
		
		cout<<"Inserire il titolo del quadro: ";
		cin>>quadri[numQuadro].titolo;
		cin.ignore(100, '\n');
		
		cout<<"Inserire Il nome dell'autore: ";
		cin.getline(quadri[numQuadro].autore, QUADRI);
		
		cout<<"Inserire l'altezza del quadro: ";
		cin>>quadri[numQuadro].altezza;
		
		cout<<"Inserire la larghezza del quadro: ";
		cin>>quadri[numQuadro].larghezza;
		
		numQuadro++;
		return 1;
	}
	
	return 0;
}

void stampaQuadriQuadrati(quadro const quadri[], const int numQuadro){
	for(int i=0;i<numQuadro;i++){
		if(quadri[i].altezza == quadri[i].larghezza){
			cout<<"\nTitolo: "<<quadri[i].titolo;
			cout<<"\nautore: "<<quadri[i].autore;
			cout<<"\naltezza: "<<quadri[i].altezza;
			cout<<"\nlarghezza: "<<quadri[i].larghezza<<endl;
		}
	}
}

void numeroQuadro(quadro const quadri[], const int numQuadro, char nomePittore[]){
	int contQuadro = 0;
	
	for(int i=0;i<numQuadro;i++){
		if(strcmp(nomePittore,quadri[i].autore) == 0)
			contQuadro++;
	}
	
	cout<<"\nNUMERO QUADRI DI "<<nomePittore<<": \n";
	cout<<contQuadro<<endl;
}

void numeroQuadri(quadro const quadri[], const int numQuadro, pittore const pittori[], const int numPittore){
	int contQuadri[PITTORI];
	
	for(int i=0;i<numPittore;i++){
		contQuadri[i] = 0;
	}
	
	for(int i=0;i<numPittore;i++){
		for(int j=0;j<numQuadro;j++){
			if(strcmp(pittori[i].nomePittore, quadri[j].autore) == 0)
				contQuadri[i]++;
		}
	}
	
	cout<<"\nNUMERO QUADRI DEI PITTORI:"<<endl;
	
	for(int i=0;i<numPittore;i++){
		cout<<pittori[i].nomePittore<<"\t"<<contQuadri[i]<<endl;
	}
}


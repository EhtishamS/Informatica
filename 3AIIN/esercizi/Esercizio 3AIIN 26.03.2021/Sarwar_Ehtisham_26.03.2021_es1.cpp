#include<iostream>
#include<string.h>

using namespace std;

#define MAX_PITTORI 3 
#define DIM_STR_NOME 20+1 
#define DIM_STR_GENERE 15+1 

typedef struct{ 
    int giorno; 
    int mese; 
    int anno; 
} data; 


typedef struct{ 
    char nomePittore[DIM_STR_NOME]; 
    char genere[DIM_STR_GENERE]; 
    data dataNascita; 
}pittore; 

int menu();
int insertPittore(pittore artisti[], int &numPittori);
pittore leggiPittore();
int controllaData(pittore artista);
void stampaPittori(const pittore artisti[], int numPittori);
void stampaPittore(const pittore &artista);
int ricercaArtista(const pittore artisti[], int numPittori);
void cancellaPittore(pittore artisti[], int &numPittori , int &cancellazione);
int ricercaGenere(const pittore artisti[], char genere[], int numPittori);
void stampaOrdinataNome(pittore artisti[], int numPittori);
void sortNome(pittore artisti[], int numPittori);

int main(){
    pittore artisti[MAX_PITTORI]; 
    int numPittori = 0, scelta, inserimento, cancellazione;
    
    do{
    	scelta = menu();
		switch(scelta){
			case 1:
				inserimento = insertPittore(artisti, numPittori);
				if(inserimento == 1){
					cout<<"\nL'inserimento e' andato bene!\n";
				} else{
					cout<<"\nL'inserimento non riuscito!\n";
				}
				break;
			case 2:
				stampaPittori(artisti, numPittori);
				break;
			case 3:
				int posiz;
				posiz = ricercaArtista(artisti, numPittori);
				if(posiz == -1){
					cout<<"\nIl nome non esiste!\n";
				} else{
					stampaPittore(artisti[posiz]);
				}
				break;
			case 4:
				cancellaPittore(artisti,numPittori,cancellazione);
				if(cancellazione == 1){
					cout<<"\nCancellazione effettuata!\n";
				} else{
					cout<<"\nCancellazione non effettuta!\n";
				}
				break;
			case 5:
				char genere[DIM_STR_GENERE];
				int trovato; 
				
				cin.ignore(100, '\n');
				cout<<"\nInserire il genere: \n> ";
				cin.getline(genere, DIM_STR_GENERE);
				
				trovato = ricercaGenere(artisti,genere,numPittori);
				
				if(trovato == -1)
					cout<<"\nNon esiste un pittore per questo genere!";
				
				break;		
			case 6:
				stampaOrdinataNome(artisti, numPittori);
				break;
		}
	}while(scelta!=0);
    return 0;
} 

int menu() { 
    int scelta; 
    do{
        cout<<"\nGESTIONE PITTORI: \n"; 
        cout<<"1) Inserimento di un pittore: "<<endl; 
        cout<<"2) Stampa i dati di tutti i pittori: "<<endl; 
        cout<<"3) Ricerca di un pittore per nome: "<<endl; 
        cout<<"4) Cancellazione di un pittore per nome: "<<endl; 
        cout<<"5) Ricerca dei pittori per genere: "<<endl; 
        cout<<"6) Stampa ordinata dei pittori per nome: "<<endl; 
        cout<<"0) Fine lavoro \n\n"; 
        cout<<"Digita la funzione scelta: \n>"; 
        cin>> scelta;        
    }while(scelta < 0 || scelta > 6);

    return scelta; 
}

int insertPittore(pittore artisti[], int &numPittori){
	if(numPittori<MAX_PITTORI){
		artisti[numPittori] = leggiPittore();
		numPittori++;
		return 1;
	}else{
		return 0;	
	}
}

pittore leggiPittore(){
	pittore artista;

	cin.ignore(100, '\n');
    cout<<"\nInserire il nome del pittore: \n>";
    cin.getline(artista.nomePittore, DIM_STR_NOME);
    cout<<"Inserire il genere del pittore: \n>";
    cin.getline(artista.genere, DIM_STR_GENERE);
    
    do{
	    cout<<"Inserire la data di nascita del pittore (gg mm yyyy): \n> ";
		cin>>artista.dataNascita.giorno>>artista.dataNascita.mese>>artista.dataNascita.anno;
	}while(controllaData(artista) == 0);

	return artista;
}

int controllaData(pittore artista){
	int giorno, mese, anno;
	
	giorno = artista.dataNascita.giorno;
	mese = artista.dataNascita.mese;
	anno = artista.dataNascita.anno;

	if(anno>1900){
		if(1<=mese<=12){
			if(0<=giorno<=31){
				return 1;
			}
		}
	}
	return 0;
}

void stampaPittori(const pittore artisti[], int numPittori){
	int i;
	
	for(i=0;i<numPittori;i++){
		cout<<"\nArtista ["<<i+1<<"]: ";
		stampaPittore(artisti[i]);
	}
}

void stampaPittore(const pittore &artista){
	cout<<"\nNome: "<<artista.nomePittore<<endl;
	cout<<"Genere: "<<artista.genere<<endl;
	cout<<"Data di Nascita: "<<artista.dataNascita.giorno<<"/"<<artista.dataNascita.mese<<"/"<<artista.dataNascita.anno<<endl;
}

int ricercaArtista(const pittore artisti[], int numPittori){
	int i;
	char nomeArtista[DIM_STR_NOME];
				
	cin.ignore(100,'\n');
	cout<<"Inserire il nome: ";
	cin.getline(nomeArtista, DIM_STR_NOME);
	
	for(i=0;i<numPittori;i++){
		if(strcmp(nomeArtista,artisti[i].nomePittore)==0){
			return i;
		}
	}
	return -1;
}

void cancellaPittore(pittore artisti[], int &numPittori, int &cancellazione){
	int posiz, i;
	char sioNo;
	pittore artista;
	
	cout<<"\nArtista da cancellare\n";
	posiz = ricercaArtista(artisti, numPittori);
	
	while(posiz == -1){
		cout<<"\nArtista non trovato reinserire i dati\n";
		posiz = ricercaArtista(artisti, numPittori);
	}
	
	stampaPittore(artisti[posiz]);
	
	cout<<"\nScelgliere tra y/n: ";
	cin>>sioNo;
	while(sioNo != 'y' && sioNo != 'n'){
		cout<<"Scegliere tra le opzioni perfavore: ";
		cin>>sioNo;
	}
	
	if(sioNo == 'y'){
		for(i=posiz;i<numPittori;i++){
			artisti[i]=artisti[i+1];
		}
		numPittori--;
		cancellazione == 1;
	} else{
		cancellazione == 0;
	}
}

int ricercaGenere(const pittore artisti[], char genere[], int numPittori){
	int i, trovato = 0;
	
	for(i=0;i<numPittori;i++){
		if(strcmp(artisti[i].genere,genere) == 0){
			trovato = 1;
			stampaPittore(artisti[i]);
		}
	}
	
	if(trovato == 1){
		return 0;
	} else{
		return -1;
	}
}

void stampaOrdinataNome(pittore artisti[], int numPittori){

	sortNome(artisti, numPittori);
	stampaPittori(artisti, numPittori);
}

void sortNome(pittore artisti[], int numPittori){
	int i, j, posizMin;
	pittore temp;
	
	for(i=0;i<numPittori-1;i++){
		posizMin = i;
		for(j=i+1;j<numPittori;j++){
			if(strcmp(artisti[posizMin].nomePittore,artisti[j].nomePittore) > 0){
				posizMin = j;	
			}
		}
		temp = artisti[i];
		artisti[i] =  artisti[posizMin];
		artisti[posizMin] = temp;
	}	
}


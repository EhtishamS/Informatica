#include<iostream>
#include<string.h>

using namespace std;

#define MAX_PIANI 20
#define MAX_UFFICI 40
#define NOME_STR 25
#define COGNOME_STR 30

enum esposizione{NORD, NORDEST, EST, SUDEST, SUD, SUDOVEST, OVEST, NORDOEVEST, INDEFINITA};

typedef struct {
    char nome[NOME_STR];
    char cognome[COGNOME_STR];
    int categoria;
    double stipedio;
}impiegato;

typedef struct{
	impiegato lavoratore;
	esposizione esp;
}ufficio;

typedef struct{
    int numPiani;
    int numUffici;
    ufficio uffici[MAX_PIANI][MAX_UFFICI];
}edificio;

int menu();
void inizializzaEdificio(edificio &torre);
void insertEdificio(edificio &torre);
void insertUffici(edificio &torre);
void stampaEdificio(edificio &torre);

int main(){
	int scelta;
    
	edificio torre;
	inizializzaEdificio(torre);
	
	do{
		scelta = menu();
		switch(scelta){
			case 1:
				insertEdificio(torre);
				break;
			case 2:
				insertUffici(torre);
				break;
			case 3:
				stampaEdificio(torre);
				break;
		}
	}while(scelta!=0);
	
	return 0;
}

int menu(){
	int scelta;
	
	do{
		cout<<"1. Definire le dimensioni dell'edificio."<<endl;
		cout<<"2. Inserire dati riguardo ai uffici."<<endl;
		cout<<"3. Stampa Edificio."<<endl;
		cout<<"0. Fine lavoro.";
		cout<<"\nInserire la scelta \n> ";
		cin>>scelta;
	}while(scelta<0 || scelta > 3);
	
	return scelta;
}

void inizializzaEdificio(edificio &torre){
	int i, j;
	impiegato lav1;
	
	strcpy(lav1.nome,"none");
	strcpy(lav1.cognome,"none");
	lav1.categoria = 0;
	lav1.stipedio = 0.00;
	
	for(i=0;i<MAX_PIANI;i++){
		for(j=0;j<MAX_UFFICI;j++){
			torre.uffici[i][j].lavoratore = lav1;
			torre.uffici[i][j].esp = (esposizione) 8;
		}
	}
}

void insertEdificio(edificio &torre){    // O
    int i, j;
    
    do{
        cout<<"\nQuanti piani ha il suo edificio: \n> ";
        cin>>torre.numPiani;
    }while(torre.numPiani<=0 || torre.numPiani>MAX_PIANI);

    do{
        cout<<"Quanti uffici ha per ogni piano: \n> ";
        cin>>torre.numUffici;
    }while(torre.numUffici<=0 || torre.numUffici>MAX_UFFICI);
    cout<<"\n\n";
}

void insertUffici(edificio &torre){
	int piano;
	int ufficio;
	int scelta;
	
	do{
		cout<<"\nInserire il numero del piano su cui vuole lavorare: \n> ";
		cin>>piano;
		cout<<"Inserire il numero dell'ufficio in cui vuole lavorare: \n> ";
		cin>>ufficio;
	}while((piano<0 || piano>=torre.numPiani) || (ufficio<0 || ufficio>=torre.numUffici));

	do{
		cout<<"\nInserire l'esposione dell'uffico che ha inserito: ";
		cout<<"\n1. NORD";
		cout<<"\n2. NORDEST";
		cout<<"\n3. EST";
		cout<<"\n4. SUDEST";
		cout<<"\n5. SUD";
		cout<<"\n6. SUDOVEST";
		cout<<"\n7. OVEST";
		cout<<"\n8. NORDOVEST";
		cout<<"\n\nInserire la sua scelta: \n> ";
		cin>>scelta;
	}while(scelta<=0 || scelta>8);
	
	scelta--;
	
	torre.uffici[piano][ufficio].esp = (esposizione) scelta;

	cout<<"Inserire il nome dell'impiegato dell'ufficio: \n> ";
	cin.ignore(100, '\n');
	cin.getline(torre.uffici[piano][ufficio].lavoratore.nome, NOME_STR);
	
	cout<<"Inserire il cognome dell'impiegato dell'ufficio: \n> ";
	cin.getline(torre.uffici[piano][ufficio].lavoratore.cognome, COGNOME_STR);
	
	cout<<"Inserire la categoria dell'impiegato: \n> ";
	cin>>torre.uffici[piano][ufficio].lavoratore.categoria;
	
	cout<<"Inserire lo stipendio dell'impiegato: \n> ";
	cin>>torre.uffici[piano][ufficio].lavoratore.stipedio;
	
	cout<<"\n\n";
}

void stampaEdificio(edificio &torre){
	int i, j;
	
	for(i=0;i<torre.numPiani;i++){
		cout<<"\nPIANO N."<<i<<endl;
		for(j=0;j<torre.numUffici;j++){
			cout<<"\nUFFICIO N."<<j+1<<endl;
			switch(torre.uffici[i][j].esp){
				case 0:
					cout<<"Esposizione: NORD";
					break;
				case 1:
					cout<<"Esposizione: NORDEST";
					break;
				case 2:
					cout<<"Esposizione: EST";
					break;
				case 3:
					cout<<"Esposizione: SUDEST";
					break;
				case 4:
					cout<<"Esposizione: SUD";
					break;
				case 5:
					cout<<"Esposizione: SUDOVEST";
					break;
				case 6:
					cout<<"Esposizione: OVEST";
					break;
				case 7:
					cout<<"Esposizione: NORDOVEST";
					break;
				case 8:
					cout<<"Esposizione: INDEFINITA";
					break;
			}
			
		cout<<"\nNome impiegato: "<<torre.uffici[i][j].lavoratore.nome;
		cout<<"\nCognome impiegato: "<<torre.uffici[i][j].lavoratore.cognome;
		cout<<"\nCategoria impiegato: "<<torre.uffici[i][j].lavoratore.categoria;
		cout<<"\nStipendio impiegato: "<<torre.uffici[i][j].lavoratore.stipedio;
		cout<<"\n\n";
		}
	}
}

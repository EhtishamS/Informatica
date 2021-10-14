#include<iostream>
#include<string.h>

using namespace std;

#define MAX_STUDENTI 30
#define MAX_TEMP 80

typedef struct{
	char cognome[25];
	char nome[21];
	double peso;
	double altezza;
}studente;

void InsertStudenti(studente classe[],int &numStudenti);
void stampaOrdinata(studente classe[],int numStudenti);

int main(){
	studente classe[MAX_STUDENTI];
	int numStudenti = 0;
	
	InsertStudenti(classe, numStudenti);
	stampaOrdinata(classe, numStudenti);
	
	return 0;
}

void InsertStudenti(studente classe[],int &numStudenti){
	char temp[MAX_TEMP];
	do{
		cout<<"Quanti studenti vuole inserire (<=30): ";
		cin>>numStudenti;
	}while(numStudenti<=0 || numStudenti>MAX_STUDENTI);

	for(int i;i<numStudenti;i++){
		cout<<"\nStudente ["<<i+1<<"]: ";
		
		do{
			cout<<"\nInserire il cognome del studente: ";
			cin>>temp;
		}while(strlen(temp)<=0 || strlen(temp)>MAX_STUDENTI);
		strcpy(classe[i].cognome,temp);
		
		do{
			cout<<"Inserire il nome del studente: ";
			cin>>temp;
		}while(strlen(temp)<=0 || strlen(temp)>MAX_STUDENTI);
		strcpy(classe[i].nome,temp);
		
		cout<<"Inserire il peso del studente: ";
		cin>>classe[i].peso;
		
		cout<<"Inserire l'altezza del studento: ";
		cin>>classe[i].altezza;
	}
}

void stampaOrdinata(studente classe[],int numStudenti){
	int i, j, posmin;
	studente temp;
	
	for(i=0;i<numStudenti-1;i++){
		posmin = i;
		for(j=i+1;j<numStudenti;j++){
			if((classe[posmin].peso>classe[j].peso) && (classe[posmin].altezza>classe[j].altezza)){
				posmin = j;
			}
		}
		temp = classe[i];
		classe[i] = classe[posmin];
		classe[posmin] = temp;
	}	
	
	for(i=0;i<numStudenti;i++){
		cout<<"\n\nStudente ["<<i+1<<"]: ";
		cout<<"\nNome: "<<classe[i].nome;
		cout<<"\nCognome: "<<classe[i].cognome;
		cout<<"\nPeso: "<<classe[i].peso;
		cout<<"\nAltezza: "<<classe[i].altezza;
	}
}


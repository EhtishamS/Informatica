#include<iostream>
#include<string.h>

using namespace std;

#define NMAX 5
#define DIMSTR 100

struct elemento{
	char s[DIMSTR];
	int c;
};

char menu();
int inserimento(elemento elementi[], int &numElem, char ns[]);
int cercaStr(elemento elementi[], int numElem, char ns[]);
int cancellazione(elemento elementi[], int &numElem, char ns[]);
void visualizzazione(elemento elementi[], int numElem);
void sort(elemento elementi[], int numElem);

int main(){
	elemento elementi[NMAX];
	int numElem=0;
	char scelta;
	char ns[DIMSTR];
	int risultato;
	
	
	do{
		scelta = menu();
		
		switch(scelta){
			case 'I':
				cin.ignore(100, '\n');
				cout<<"\nInserire una stringa: ";
				cin.getline(ns,DIMSTR);
				
				risultato = inserimento(elementi,numElem,ns);
				
				if(risultato)
					cout<<"\nInserimento terminato correttamente!\n";
				else
					cout<<"\nInserimento non riuscito!\n";
				break; 
			
			case 'C':
				cin.ignore(100, '\n');
				cout<<"\nInserire un stringa: ";
				cin.getline(ns,DIMSTR);
				
				risultato = cancellazione(elementi,numElem,ns);
				
				if(risultato)
					cout<<"\nCancellazione fatta correttamente.\n";
				else
					cout<<"\nErrore elemento non esistente!\n";
				break;
			case 'V':
				visualizzazione(elementi,numElem);
				break;
		}	
	}while(scelta != 'F');
	
	cout<<"\nProgramma terminato!";
	
	return 0;
}

char menu(){
	char scelta;
	
	do{
		cout<<"\nScegliere tra queste opzioni: ";
		cout<<"\nI. Inserimento.";
		cout<<"\nC. Cancellazione.";
		cout<<"\nV. Visualizzione.";
		cout<<"\nF. Fine lavoro.";
		cout<<"\nInserire la propria scelta:\n>";
		cin>>scelta;
	}while(scelta != 'I' && scelta != 'C' && scelta != 'V' && scelta != 'F');
	
	return scelta;
}

int inserimento(elemento elementi[], int &numElem, char ns[]){
	int risultato = cercaStr(elementi,numElem,ns);
	
	if(numElem<NMAX && risultato==-1){
		strcpy(elementi[numElem].s,ns);
		elementi[numElem].c = 1;
		numElem++;
		return 1;
	} else if(risultato!=-1){
		strcpy(elementi[risultato].s,ns);
		elementi[risultato].c++;
		return 1;
	} else if(numElem>=NMAX && risultato!=-1){
		strcpy(elementi[risultato].s,ns);
		elementi[risultato].c++;
		return 1;
	}
	
	return 0;
}

int cercaStr(elemento elementi[], int numElem, char ns[]){
	for(int i=0;i<numElem;i++){
		if(strcmp(elementi[i].s,ns) == 0)
			return i;
	}
	
	return -1;
}

int cancellazione(elemento elementi[], int &numElem, char ns[]){
	int risultato = cercaStr(elementi,numElem,ns);
	
	if(risultato!=-1){
		if(elementi[risultato].c-1 == 0){
			for(int i=risultato;i<numElem-1;i++){
				elementi[i] = elementi[i+1];
			}
			numElem--;
		} else{
			elementi[risultato].c--;
		}
		return 1;	
	}
	
	return 0;
}

void visualizzazione(elemento elementi[], int numElem){
	sort(elementi,numElem);
	
	cout<<endl;
	
	for(int i=0;i<numElem;i++){
		cout<<elementi[i].s<<"\t"<<elementi[i].c<<endl;
	}
}

void sort(elemento elementi[], int numElem){
	int posizMax;
	
	for(int i=0;i<numElem-1;i++){
		posizMax = i;
		for(int j=i+1;j<numElem;j++){
			if(strcmp(elementi[j].s,elementi[posizMax].s)>0)
				posizMax = j;
		}
		elemento temp;
		temp = elementi[posizMax];
		elementi[posizMax] = elementi[i];
		elementi[i] = temp;
	}
}


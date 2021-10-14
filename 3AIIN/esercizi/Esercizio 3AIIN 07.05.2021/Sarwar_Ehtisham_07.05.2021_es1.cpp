#include<iostream>
#include<string.h>

#define DIM_STR 25+1 
#define NMAX 50 

using namespace std;

typedef struct{ 
	char s[DIM_STR]; 
 	int c; 
}elem;

int menu();
int Inserimento(elem lista[], int &numElem);
int cercaStr(elem lista[], int numElem, char str[]);
void shifitingDestra(elem lista[], int numElem, int num);
void stampa(elem lista[], int numElem);
int cancellazione(elem lista[], int &numElem);
void shifitingSinistra(elem lista[], int numElem, int num);
void visualizzazione(elem lista[], int numElem);
void copia(elem lista[], elem copyLista[], int numElem);
void sort(elem copyLista[], int numElem);
int ricercaBinaria(elem lista[], int numElem, char str[]);

int main(){
	elem lista[NMAX]; 
	int numElem=0, esito;
	char scelta, str[DIM_STR];
	
	do{
		scelta = menu();
		
		switch(scelta){
			case 'i':
				esito = Inserimento(lista,numElem);
				if(esito){
					cout<<"\nInserimento andato a buon fine!";
				} else {
					cout<<"\nInserimento fallito!";
				}
				stampa(lista,numElem);
				break;
			case 'c':
				esito = cancellazione(lista,numElem);
				
				if(esito){
					cout<<"\nCancellazione eseguita con successso!";
				} else {
					cout<<"\nStringa non Esistente!";
				}
				stampa(lista,numElem);
				break;
			case 'v':
				visualizzazione(lista,numElem);
				break;
			case 'r':
				
				cout<<"\nInserire una ricerca: ";
				cin>>str;
				
				esito = ricercaBinaria(lista,numElem,str);
				
				if(esito!=-1){
					cout<<"\nOccorrenza: "<<lista[esito].c;
				} else {
					cout<<"\nElemento non esistente!";
				}
				break;
		}
		
	}while(scelta != 'f');
	return 0;
}

int menu(){
	char scelta;
	
	cout<<"\n\nGESTIONE STRINGHE\n"; 
 	cout<<"I/i - Inserimento \n"; 
	cout<<"C/c - Cancellazione \n"; 
	cout<<"V/v - Visualizzazione \n"; 
	cout<<"R/r - Ricerca \n"; 
 	cout<<"F/f - Fine lavoro \n\n"; 
 	cout<<"Digita una scelta \n";
 	cin>>scelta;
 	
 	if(scelta>= 'A' && scelta<='Z')
 		scelta+=32;	
	
 	return scelta;
}

int Inserimento(elem lista[], int &numElem){
	char ns[DIM_STR];
	int pos, trovato = 1;
	
	cout<<"Inserire una stringa: ";
	cin>>ns;
	
	if(numElem<NMAX){
		pos = cercaStr(lista,numElem,ns);
		
		if(numElem == 0){
			strcpy(lista[numElem].s,ns);
			lista[numElem].c = 1;
		} else if(pos == -1){
			for(int i=0;i<=numElem && trovato;i++){
				if(strcmp(lista[i].s,ns)>0){
					shifitingDestra(lista,numElem,i);
					strcpy(lista[i].s,ns);
					lista[i].c = 1;
					trovato = 0;
				}
			}
		} else if(pos != -1){
			lista[pos].c++;
			numElem--;
		}
		
		numElem++;
		return 1;
	}
	
	return -1;
}

int cercaStr(elem lista[], int numElem, char str[]){
	int i;
	
	for(i=0;i<numElem;i++){
		if(strcmp(lista[i].s,str)==0){
			return i;
		} 
	}
	
	return -1;
}

void shifitingDestra(elem lista[], int numElem, int num){
	int i;
	
	for(i=numElem;i>=num;i--){
		lista[i+1] = lista[i];
	}
}

void stampa(elem lista[], int numElem){
	int i;
		
	for(i=0;i<numElem;i++){
		cout<<endl;
		cout<<lista[i].s<<" "<<lista[i].c;
	}
}

int cancellazione(elem lista[], int &numElem){
	char ns[DIM_STR];
	
	cout<<"Inserire la stringa da cancellare: ";
	cin>>ns;
	
	for(int i=0;i<=numElem;i++){
		if(strcmp(lista[i].s,ns) == 0){
			if(lista[i].c==1){
				shifitingSinistra(lista,numElem,i);
				numElem--;
				return 1;
			} else {
				lista[i].c--;
				return 1;
			}
		}
	}
	
	return 0;
}

void shifitingSinistra(elem lista[], int numElem, int num){
	int i;
	
	for(i=num;i<numElem;i++){
		lista[i] = lista[i+1];	
	}
}

void visualizzazione(elem lista[], int numElem){
	elem copyLista[NMAX];
	
	copia(lista,copyLista,numElem);
	sort(copyLista,numElem);
	
	for(int i=0;i<numElem;i++){
		cout<<"\n"<<copyLista[i].s<<"\t"<<copyLista[i].c;
	}	
}

void copia(elem lista[], elem copyLista[], int numElem){
	int i;
	
	for(i=0;i<numElem;i++){
		copyLista[i] = lista[i];
	}
}

void sort(elem copyLista[], int numElem){
	int max;
		
	for(int i=0;i<numElem;i++){
		max = i;
		
		for(int j=i+1;j<numElem;j++){
			if(copyLista[max].c < copyLista[j].c)
				max = j;
		}
		
		elem temp = copyLista[max];
		copyLista[max] = copyLista[i];
		copyLista[i] = temp;
	}
}

int ricercaBinaria(elem lista[], int numElem, char str[]){
	int low = 0, high = numElem-1, mid;
	
	while((low<=high)){
		mid = (low+high)/2;
		if(strcmp(str,lista[mid].s) < 0){
			high = mid-1;
		} else if(strcmp(str,lista[mid].s) > 0){
			low = mid+1;
		} else {
			return mid;
		}
	}
	return -1;
	
}

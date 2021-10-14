#include<iostream>
#include<string.h>

#define MAX_CITTA 5 
#define MAX_CAR 20+1

using namespace std;

int menu();
void inizializzaDistanze(int distanze[][MAX_CITTA]);
void inserireCitta(char citta[][MAX_CAR], int &numCitta, int distanze[][MAX_CITTA]);
void inserireDistanze(int distanze[][MAX_CITTA], int numCitta, char citta[][MAX_CAR]);
void stampaCitta(char citta[][MAX_CAR], int numCitta);
void stampaDistanze(int distanze[][MAX_CITTA], int numCitta);
int trovoCitta(char city[], char citta[][MAX_CAR], int numCitta);

int main(){
    char citta[MAX_CITTA][MAX_CAR]; 
    int distanze[MAX_CITTA][MAX_CITTA]; 
    int numCitta; 
    char arrivo[MAX_CAR]; 
    char partenza[MAX_CAR]; 
    int trovato; 
    int posizPartenza, posizArrivo; 
    int i,j;
    int scelta;

	inizializzaDistanze(distanze);
	
    do{
        scelta = menu();

        switch(scelta){
            case 1:
                inserireCitta(citta, numCitta, distanze);
                break;
			case 2:
				stampaCitta(citta, numCitta);
				break;
			case 3:
				stampaDistanze(distanze, numCitta);
				break;
			case 4:
				cout<<"inserire la citta' di partenza: ";
				cin>>partenza;
				cout<<"inserire la citta' di arrivo: ";
				cin>>arrivo;
				
				posizPartenza = trovoCitta(partenza, citta, numCitta);
				posizArrivo = trovoCitta(arrivo, citta, numCitta);
				
				if(posizPartenza == -1 && posizArrivo == -1){
					cout<<"\nEntrambe le citta inserite non esistono!\n\n";
				} else if(posizPartenza == -1){
					cout<<"\nUna delle citta non e' presente!\n\n";
				} else if(posizArrivo == -1){
					cout<<"\nUna delle citta non e' presente!\n\n";
				} else{
					cout<<"\nla citta di "<<partenza<<" e distante da "<<arrivo<<" di "<<distanze[posizPartenza][posizArrivo]<<" km\n\n";
				}
				break;			
        }
    }while(scelta!=0);
    
	cout<<"Programma terminato!";

    return 0;
}

void inizializzaDistanze(int distanze[][MAX_CITTA]){
	int i, j;
	
	for(i=0;i<MAX_CITTA;i++){
		for(j=0;j<i+1;j++){
			distanze[i][j]=0;
			distanze[j][i] = distanze[i][j];
		}
	}
}

int menu(){
    int scelta;
    do{
        cout<<"\n1.Inserire i nomi delle citta e le loro distanze";
        cout<<"\n2.stampare le citta";
        cout<<"\n3.stampa le distanze";
        cout<<"\n4.cacolare la distanza tra due citta'";
        cout<<"\n0.Fine lavoro";
        cout<<"\n> ";
        cin>>scelta;
        cout<<"\n\n";       
    }while(scelta<0 || scelta>4);

    return scelta;
}

void inserireCitta(char citta[][MAX_CAR], int &numCitta, int distanze[][MAX_CITTA]){
    int i;
    
    do{
        cout<<"Quante citta' desidera inserire: ";
        cin>>numCitta;
    }while(numCitta<0 || numCitta>MAX_CITTA);

    cout<<"\n";

    for(i=0;i<numCitta;i++){
        cout<<"Inserire la citta "<<i+1<<": ";
        cin>>citta[i];
    }    
	
	cout<<"\n\n";
    inserireDistanze(distanze, numCitta, citta);
}

void inserireDistanze(int distanze[][MAX_CITTA], int numCitta, char citta[][MAX_CAR]){
    int i, j;

    for(i=0;i<numCitta;i++){
        for(j=0;j<i;j++){
            cout<<"Inserire la distanza tra "<<citta[i]<<" e "<<citta[j]<<": ";
            cin>>distanze[i][j];
            distanze[j][i] = distanze[i][j];
        }
    }
}

void stampaCitta(char citta[][MAX_CAR], int numCitta){
	int i, j;
	
	cout<<"Le citta inserite sono le seguenti: \n\n";
	
	for(i=0;i<numCitta;i++){
			cout<<"citta ("<<i+1<<"): "<<citta[i];
			cout<<"\n";
	}
}

void stampaDistanze(int distanze[][MAX_CITTA], int numCitta){
	int i, j;
	
	cout<<"Le varie distanze sono le seguenti: \n\n";
	
	for(i=0;i<numCitta;i++){
		for(j=0;j<numCitta;j++){
			cout<<distanze[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int trovoCitta(char city[], char citta[][MAX_CAR], int numCitta){
	int dis, i, j, lunghezza, trovata=1;
	
	lunghezza = strlen(city);
	
	for(i=0;i<MAX_CITTA;i++){
		if(lunghezza==strlen(citta[i])){
			for(j=0;j<lunghezza&&trovata;j++){
				if(citta[i][j]!=city[j]){
					trovata = 0;
				}
			}
			
			if(trovata){
				return i;
			}
		}
	}
	return -1;
}

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

#define MAX 5
#define TENTATIVI 10


void inizializza(int hint[]);
void stampa(char lettereDisponibili[]);
void messaggeFiller(char secretMessage[]);
void lettere(char lettereDisponibili[], char secretMessage[]);
void guessMessage(char secretMessage[], char message[], char lettereDisponibili[], int hint[], int &tentativi);
void contLettereUguali(char secretMessage[], char message[], int hint[]);


int main(){
	char secretMessage[MAX];
	char message[MAX];
	char lettereDisponibili[MAX*2-1];
	int hint[MAX-1];
	int tentativi = TENTATIVI;
	
	srand(time(NULL));
	
	inizializza(hint);
	messaggeFiller(secretMessage);
	lettere(lettereDisponibili,secretMessage);
	guessMessage(secretMessage,message,lettereDisponibili,hint,tentativi);

	return 0;
}

void inizializza(int hint[]){
	for(int i=0;i<MAX-1;i++){
		hint[i]=0;
	}
}

void messaggeFiller(char secretMessage[]){
	bool esiste;
	
	for(int i=0;i<MAX-1;i++){
		esiste=false;
		do{
			secretMessage[i]=rand()%('z'-'a'+1)+'a';
			for(int j=0;j<i&&esiste==false;j++){
				if(secretMessage[i]==secretMessage[j])
					esiste = true;
			}
		}while(esiste);
	}
}

void guessMessage(char secretMessage[], char message[], char lettereDisponibili[], int hint[], int &tentativi){
	bool vittoria = false;
	
	cout<<"\nInserire le lettere nei posti mancanti:";
	while(tentativi>0 && vittoria==false){
		cout<<"\nTentativi mancanti: "<<tentativi<<endl;
		cout<<"_ _ _ _ "<<hint[0]<<hint[1]<<hint[2]<<hint[3]<<endl;
		stampa(lettereDisponibili);
		cout<<"\n> ";
		cin>>message;
		
		inizializza(hint);
		contLettereUguali(secretMessage,message,hint);
		
		if(hint[0]== 2 && hint[1]== 2 &&hint[2]== 2 && hint[3]==2)
			vittoria = true;
		tentativi--;
	}
	
	if(vittoria)
		cout<<"\nHai decodificato con successo! "<<"\""<<secretMessage<<"\"";
	else 
		cout<<"Il codice segreto era: "<<secretMessage;
}

void contLettereUguali(char secretMessage[], char message[], int hint[]){
	int contLettere = 0;
	int postoGiusto = 0;
	
	for(int i=0;i<MAX-1;i++){
		if(message[i] == secretMessage[i])
			postoGiusto++;
		for(int j=0;j<MAX-1;j++){
			if(message[i]==secretMessage[j])
				contLettere++;
		}
	}
	
	for(int i=0;i<contLettere;i++){
		hint[i]++;
	}
		
	for(int i=0;i<postoGiusto;i++){
		hint[i]++;
	}
}

void stampa(char lettereDisponibili[]){
	for(int i=0;i<MAX*2-2;i++){
		cout<<lettereDisponibili[i]<<" ";
	}
}

void lettere(char lettereDisponibili[], char secretMessage[]){
	bool esiste;
	int indice;
	
	for(int i=0;i<MAX*2-2;i++){
		lettereDisponibili[i]='0';	
	}
	
	for(int i=0;i<MAX-1;i++){
		do{
			indice = rand()%(MAX*2-2);
			esiste = false;
			
			if(lettereDisponibili[indice]=='0'){
				lettereDisponibili[indice] = secretMessage[i];
			} else 
				esiste = true;
		}while(esiste);	
	}
	
	for(int i=0;i<MAX*2-2;i++){
		if(lettereDisponibili[i]=='0'){
			do{
				esiste = false;
				lettereDisponibili[i] = rand()%('z'-'a'+1)+'a';
				
				for(int j=0;j<MAX*2-2&&esiste==false;j++){
					if(lettereDisponibili[i] == lettereDisponibili[j] && i!=j)
						esiste=true;
				}
			}while(esiste);
		}
	}
}

/*
Scrivi un sottopgm che ordina in modo crescente un vettore di stringhe.
Si utlizzi l'algoritmo studiato lo scorso anno: "Selection sort".

Nella letterature informatica esistono molti algoritmi di ordinamento. Cerca in internet l'algoritmo 
"Bubble sort" e applicalo nell'esercizio di prima ordinando l'array per lunghezza descrescente delle 
stringhe.

Il sottopgm è una funzione o una procedura?

è una procedura.
*/
#include<iostream>
#include<cstring>

using namespace std;

const int MAX_RIG = 7;
const int MAX_COL = 20+1;

void ordineSelSort(char matrix[][MAX_COL]);
void oridineBubSort(char matrix[][MAX_COL]);

int main(){
	char matrix[MAX_RIG][MAX_COL] = {
	{"ciao"},
	{"dacoli"},
	{"lopilop"},	
	{"fankling"},
	{"ribycube"},
	{"chubbybuddy"},
	{"ropeling"}};
	
	ordineSelSort(matrix);
	
	for(int i=0;i<MAX_RIG;i++){
		cout<<matrix[i]<<"\n";
	}
	
	cout<<"\n\n";
	oridineBubSort(matrix);
	
		
	for(int i=0;i<MAX_RIG;i++){
		cout<<matrix[i]<<"\n";
	}
	
	
	return 0;
}

void ordineSelSort(char matrix[][MAX_COL]){
	int min;
	
	for(int i=0;i<MAX_RIG-1;i++){
		min = i;
		for(int j=i+1;j<MAX_RIG-1;j++){
			if(strcmp(matrix[min],matrix[j])>0){
				min = j;
			}
		}
		char temp[MAX_COL];
		strcpy(temp,matrix[min]);
		strcpy(matrix[min],matrix[i]);
		strcpy(matrix[i],temp);
	}
}

void oridineBubSort(char matrix[][MAX_COL]){
	for(int i=0;i<MAX_RIG-1;i++){
		for(int j=0;j<MAX_RIG-1;j++){
			if(strlen(matrix[j])>strlen(matrix[j+1])){
				char temp[MAX_COL];
				strcpy(temp,matrix[j]);
				strcpy(matrix[j],matrix[j+1]);
				strcpy(matrix[j+1],temp);
			}
		}
	}
}

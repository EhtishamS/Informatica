/*
Scrivi un sottopgm che data una stringa cancella tutti i caratteri alfabetici (sia maiuscoli 
che minuscoli) eseguendo un’operazione di shift verso sx. 

Questo sottopgm è una funzione o una procedura?

procedura.
*/
#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

void cancCar(char *str);
void shiftLeft(char *str, const int inizio);

int main(){
	char str[] = "ciaocomeva1021r80s9";
	
	cancCar(str);
	
	cout<<str;
	return 0;
}


void cancCar(char *str){
	for(int i=0;i<strlen(str);i++){
		if(isalpha(str[i])){
			shiftLeft(str,i);
			i--;
		}
	}
}


void shiftLeft(char *str,const int inizio){
	for(int i=inizio;i<strlen(str);i++){
		str[i]=str[i+1];
	}
}

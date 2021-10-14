/*
Scrivi un sottoprm che data una stringa s contente anche delle cifre, sommi tutte le cifre e fornisca il 
valore totale di tale somma.

Esempio:
s="abc3x casa2 y34zq" il programma deve restituire 3+2+3+4=12

Il sottopgm è una funzione o una procedura?

è una funzione.
*/
#include<iostream>

using namespace std;

int sommaNumStr(char *str);

int main(){
	char str[] = "abc3x casa2 y34zq";
	
	cout<<"La somma dei numeri all'intero della stringa fa: "<<sommaNumStr(str);
	
	return 0;
}

int sommaNumStr(char *str){
	int sum = 0;
	
	for(int i=0;str[i];i++){
		if(str[i]>='0' && str[i]<='9'){
			sum += (str[i]-'0');
		}
	}
	
	return sum;
}

#include<iostream>
#include<string.h>

#define MAX 20
#define SPAZIO 32
#define PIU 43
#define MENO 45

using namespace std;

int valNum(char str[]);

int main (){
	char str[MAX];
	int segno, ris;
	
	cout<<"Inserisci una espressione: ";
	gets(str);
	
	ris = valNum(str);
	
	cout<<"\nIl risultato della sua espressione e: "<<ris;
	
	return 0;
}

int valNum(char str[]){
	int i, numElem=0, vet[MAX], risultato=0, cont_num=1;
	
	for(i=0;i<strlen(str);i++){
		if(str[i] != SPAZIO){
			if(str[i]=='+'){
				vet[numElem] = '+';
				numElem++;
				cont_num=1;
			} else if(str[i]=='-'){
				vet[numElem] = '-';
				numElem++;
				cont_num=1;
			} else {
				if(cont_num>1){
					vet[numElem-1] = (vet[numElem-1]*10)+(str[i]-'0');
				} else if (cont_num<=1){
					vet[numElem] = str[i]-'0';
					numElem++;
				}
				cont_num++;
			}
		}
	}
	
	for(i=0;i<numElem;i++){
		if(vet[i]!=PIU && vet[i]!=MENO && i==0){
			risultato = vet[i]; 
		} else if(vet[i]==PIU){
			i++;
			risultato +=vet[i];
		} else {
			i++;
			risultato -=vet[i];
		}
	}
	
	return risultato;
}

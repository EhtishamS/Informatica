#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

#define NOME_FILE 30+1
#define STR_CMB 2+1

int controlloFile(char *nomeFileIn, char *nomeFileOut);
void sostituisci(char *strigCmb, char *nomeFileIn, char* nomeFileOut);

int main(){	
	char nomeFileIn[NOME_FILE];
	char nomeFileOut[NOME_FILE];
	char strigCmb[STR_CMB];
	
	cout<<"Inserire il nome del file da aprire: ";
	cin>>nomeFileIn;
	
	cout<<"Inserire il nome del file dove salvare: ";
	cin>>nomeFileOut;
	
	cout<<"Inserire le i caratteri cambiare: ";
	cin>>strigCmb;
	
	if(controlloFile){
		sostituisci(strigCmb, nomeFileIn, nomeFileOut);
		cout<<"Fine elaborazione file!";
	}
		
	return 0;
}

int controlloFile(char *nomeFileIn, char *nomeFileOut){
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(nomeFileIn);
	outFile.open(nomeFileOut);
	
	if(!inFile){
		cout<<"\nImpossibile aprire il file di input!";
		return 0;
	}
	inFile.close();
	
	if(!outFile){
		cout<<"Impossibile aprire il fle di output!";
		return 0;
	}
	outFile.close();
		
	return 1;
}

void sostituisci(char *strigCmb, char *nomeFileIn, char* nomeFileOut){
	ifstream inFile;
	ofstream outFile;
	
	inFile.open(nomeFileIn);
	outFile.open(nomeFileOut);
	
	char car;
	
	inFile.get(car);
	if(car==strigCmb[0]){
		car = strigCmb[1];
	} else if(car==strigCmb[1]){
		car = strigCmb[0];
	} else if(car==toupper(strigCmb[0])){
		car = toupper(strigCmb[1]);
	} else if(car==toupper(strigCmb[1])){
		car = toupper(strigCmb[0]);
	}
	outFile<<car;
	
	while(!inFile.eof()){
		inFile.get(car);
		if(car==strigCmb[0]){
			car = strigCmb[1];
		} else if(car==strigCmb[1]){
			car = strigCmb[0];
		} else if(car==toupper(strigCmb[0])){
			car = toupper(strigCmb[1]);
		} else if(car==toupper(strigCmb[1])){
			car = toupper(strigCmb[0]);
		}
		outFile<<car;
	}
	
	inFile.close();
	outFile.close();
}

#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

#define INFILE "input.txt"
#define OUTFILE "output.txt"
#define DIM_MAX 80+1

void codificaMessaggio(char str[]);
int controlloVocaliMaggiori(char str);
int controlloVocaliMinori(char str);

int main(){
    char str[DIM_MAX];
    int numRighe;

    fstream fileInput, fileOutput;

    fileInput.open(INFILE,ios::in);
    fileOutput.open(OUTFILE,ios::out);

    if(!fileInput){
        cout<<"Impossibile aprire il file di input!";
        return 1;
    } 

    if(!fileOutput){
        cout<<"Impossibile aprire il file di output!";
        return 1;
    }

    fileInput>>numRighe;
    fileInput.getline(str, DIM_MAX);

    while(!fileInput.eof()){
        codificaMessaggio(str);
        fileOutput<<str<<endl;
        fileInput.getline(str, DIM_MAX);
    }

    fileInput.close();
    fileOutput.close();
    
    return 0;
}

void codificaMessaggio(char str[]){
    char car;
    int i;

    for(i=0;i<strlen(str);i++){
        // controllo per i caratteri dell'alfabeto maggiore;
        if(str[i] != ' '){
            if(str[i]>='A' && str[i]<='Z'){ // controllo se appartiene all'alfabeto maggiore oppure no
                car = controlloVocaliMaggiori(str[i]); // controllo che sia una vocale o no
                if(car!=0){
                    str[i] = car; // se controlloVocaliMaggiori vede che è una vocale questo ritorna la prossima vocale che assegno a str[i]
                } else {
                    car = controlloVocaliMaggiori(str[i]+1); //controlla se la prossima lettera è una vocale
                    if(str[i] == 'Z'){ // controlla che non siamo proprio alla fine dell'alfabeto
                        str[i] = 'B';
                    } else if(car != 0){ // se è una vocale dobbiamo sommare 2 perché così salta la vocale a va alla consonante
                        str[i] += 2; 
                    } else { // se non è una vocale semplicemente somma 1
                        str[i] += 1;
                    }
                }
            } else if(str[i]>='a' && str[i]<='z'){ // stesso controllo ma per l'alfabeto minore
                car = controlloVocaliMinori(str[i]);
                if(car!=0){
                    str[i] = car;
                } else {
                    car = controlloVocaliMinori(str[i]+1);
                    if(str[i] == 'z'){
                        str[i] = 'b';
                    } else if(car != 0){
                        str[i] += 2;
                    } else {
                        str[i] +=1;
                    }
                }
            } else if(str[i]>= '0' && str[i] <= '9'){ // controlla se sia un numero 
                if(str[i] == '9'){ // se siamo al limite questo torna a 0;
                    str[i] = '0';
                } else { // altrimenti somma 1 così va al prossimo numero;
                    str[i] += 1;
                }
            }
        }
    }
}


int controlloVocaliMaggiori(char str){ // controllo se la lettera e una consonante se lo e ritorna la succesiva altrimenti 0
	if(str == 'A'){
		return 'E';
	} else if(str == 'E'){
		return 'I';
	} else if(str == 'I'){
		return 'O';
	} else if(str == 'O'){
		return 'U';
	} else if(str == 'U'){
		return 'Y';
	} else if(str == 'Y'){
		return 'A';
	} else {
		return 0;
	}
}

int controlloVocaliMinori(char str){ // stesso controllo sta volta per l'alfabeto minore
	if(str == 'a'){
		return 'e';
	} else if(str == 'e'){
		return 'i';
	} else if(str == 'i'){
		return 'o';
	} else if(str == 'o'){
		return 'u';
	} else if(str == 'u'){
		return 'y';
	} else if(str == 'y'){
		return 'a';
	} else {
		return 0;
	}
}

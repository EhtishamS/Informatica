#include<iostream>
#define MAX 1
#define PER_ORA 40.0

using namespace std;

struct orario{
	int ore;
	int minuti;
	int secondi;
};

int orarioValido(struct orario valido);
void differenzaOrario(struct orario diff[], struct orario entra, struct orario esci);
int maggioreDelEntrata(struct orario primo, struct orario secondo);
void stampa(struct orario stampa[]);
double soldiGuadagnati(struct orario guadagno[]);

int main (){
	struct orario entrata, uscita, oreDiLavoro[MAX];
	int valido, maggiore;
	double guadagno;
	
	do{
		cout<<"Inserire l'ora di entrata (ora, min, sec): ";
		cin>>entrata.ore>>entrata.minuti>>entrata.secondi;
		valido = orarioValido(entrata);
	}while(!valido);

	do{
		cout<<"Inserire l'ora di uscita (ora, min, sec): ";
		cin>>uscita.ore>>uscita.minuti>>uscita.secondi;
		valido = orarioValido(uscita);
		maggiore = maggioreDelEntrata(entrata, uscita);
	}while(!valido || !maggiore);
	
	differenzaOrario(oreDiLavoro, entrata, uscita);
	stampa(oreDiLavoro);
	guadagno = soldiGuadagnati(oreDiLavoro);
	
	cout<<"\nHai ottenuto "<<guadagno<<" euro!"; 
	
	return 0;
}

// dice se l'orario è giusto o no.
int orarioValido(struct orario valido){
	if (valido.ore >= 0 && valido.ore <= 23){
		if (valido.minuti >= 0 && valido.minuti <= 59){
			if (valido.secondi >= 0 && valido.secondi <= 59){
				return 1;
			}
		}
	}
	return 0;
}

// dice se l'ora di uscita è maggiore dell'ora di entrata oppure no
int maggioreDelEntrata(struct orario primo, struct orario secondo){
	if(secondo.ore > primo.ore){
		return 1;
	} else if (secondo.minuti > primo.minuti){
		return 1;
	} else if (secondo.secondi > primo.secondi){
		return 1;	
	} else {
		return 0;
	}
}
//stampa le ore di lavoro che noi abbiamo fatto
void stampa(struct orario stampa[]){
	cout<<"\nHai lavorato "<<stampa[0].ore<<" "<<stampa[0].minuti<<" "<<stampa[0].secondi<<" ore!";
}

//Calcola quante ho lavorato 
void differenzaOrario(struct orario diff[], struct orario entra, struct orario esci){
	int tempOre, tempMinuti, tempSecondi;
	
	tempOre = esci.ore - entra.ore;
	tempMinuti = esci.minuti - entra.minuti;
	tempSecondi = esci.secondi - entra.secondi;
	
	if(tempMinuti < 0){
		tempOre--;
		if(tempMinuti == 59){
			tempMinuti = 0;
		} else {
			tempMinuti = 60 - entra.minuti;
		}
	} 
	if(tempSecondi < 0){
		if (tempSecondi == 59){
			tempSecondi = 0;
			tempMinuti--;
			if(tempMinuti < 0){
				tempOre--;
				if(tempMinuti == 59){
					tempMinuti = 0;
				} else {
					tempMinuti = 60 - entra.minuti;
				}
			}
		} else
			tempSecondi = 60 - entra.secondi;
	}
	diff[0].ore = tempOre;
	diff[0].minuti = tempMinuti;
	diff[0].secondi = tempSecondi;
}

//calcola quando guadagna in base alle ore di lavoro al giorno
double soldiGuadagnati(struct orario guadagno[]){
	double ore = PER_ORA, minuti = ore/60, secondi = minuti/60;
	ore = ore * guadagno[0].ore;
	minuti = minuti * guadagno[0].minuti;
	secondi = secondi * guadagno[0].secondi;
	
	return ore+minuti+secondi;
}

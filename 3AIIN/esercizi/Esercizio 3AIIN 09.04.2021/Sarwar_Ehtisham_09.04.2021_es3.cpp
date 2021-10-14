#include<iostream>

using namespace std;

#define STUDENTI 20
#define MAX_PLAYER 6

unsigned long long int fattoriale(int n);
unsigned long long int possibiliSquadre(int studenti);


int main(){
	int studenti = STUDENTI;
	unsigned long long int squadre;
	
	squadre = possibiliSquadre(studenti);	
	
	cout<<"Il numero possible di square e': "<<squadre;
	return 0;
}

unsigned long long int possibiliSquadre(int studenti){
	unsigned long long int squadre, divisione; 
	divisione = fattoriale(MAX_PLAYER)*fattoriale((studenti-MAX_PLAYER));
	squadre = fattoriale(studenti)/divisione;
	return squadre;
}

unsigned long long int fattoriale(int n){
	int i;
	unsigned long long int ris=1;
	
	for(i=1;i<=n;i++){
		ris*=i;
	}
	return ris;
}



#include<iostream>
#include<string.h>

using namespace std;

#define MAX_CARTE 52
#define DIM_MAX_STR 30

void visualizzaCarteGioco(char mazzoCarte[][DIM_MAX_STR],int n);
void visualizzaCartaGioco(char carta[DIM_MAX_STR]);
void OrdinareCarte(char mazzoCarte[][DIM_MAX_STR], int n);
int ricerca(char carta[DIM_MAX_STR], char cerca[DIM_MAX_STR]);


int main(){
	char mazzoCarte[MAX_CARTE][DIM_MAX_STR] = {
												{"Ace clubs"},{"2 clubs"},{"3 clubs"},{"4 clubs"},{"5 clubs"},{"6 clubs"},{"7 clubs"},{"8 clubs"},{"9 clubs"},{"jack clubs"},{"queen clubs"},{"king clubs"},
												{"Ace spades"},{"2 spades"},{"3 spades"},{"4 spades"},{"5 spades"},{"6 spades"},{"7 spades"},{"8 spades"},{"9 spades"},{"jack spades"},{"queen spades"},{"king spades"},
												{"Ace hearts"},{"2 hearts"},{"3 hearts"},{"4 hearts"},{"5 hearts"},{"6 hearts"},{"7 hearts"},{"8 hearts"},{"9 hearts"},{"jack hearts"},{"queen hearts"},{"king hearts"},
												{"Ace diamonds"},{"2 diamonds"},{"3 diamonds"},{"4 diamonds"},{"5 diamonds"},{"6 diamonds"},{"7 diamonds"},{"8 diamonds"},{"9 diamonds"},{"jack diamonds"},{"queen diamonds"},{"king diamonds"}};
	visualizzaCarteGioco(mazzoCarte,MAX_CARTE);
	return 0;
}

void visualizzaCarteGioco(char mazzoCarte[][DIM_MAX_STR],int n){
	for(int i=0;i<n;i++){
		visualizzaCartaGioco(mazzoCarte[i]);
	}
}

void visualizzaCartaGioco(char carta[DIM_MAX_STR]){
	cout<<carta<<endl;
}

void OrdinareCarte(char mazzoCarte[][DIM_MAX_STR], int n){
	bool spazio;
	for(int i=0;i<n;i++){
		spazio = false;
		for(int j=0;j<strlen(mazzoCarte[i]);j++){
			if(mazzoCarte[i][j]==' '){				
				spazio = true;
			}
			
			if(spazio){
				
			}
		}
	}
}


#include<iostream>
#include<stdlib.h>
#include<time.h>

#define MAX 30
#define INIZIO 97
#define CAR_GENERARE 25
#define NUM_COLONNE 10

using namespace std;

int main () {
	char v[MAX];
	int i, cont=0;
	
	srand(time(NULL));
	
	for(i=0;i<MAX;i++){
		v[i] = rand() %CAR_GENERARE+INIZIO;
	}
	
	for(i=0;i<MAX;i++){
		if(cont<NUM_COLONNE){
			cout<<v[i]<<" ";
			cont++;
		} else {
			cout<<endl;
			cout<<v[i]<<" ";
			cont=1;
		}
	}
	
	
	return 0;
}

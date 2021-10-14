/*
Scrivi un sottopgm che data una matrice di interi ritorna il valore massimo e la sua 
posizione. 

Questo sottopgm è una funzione o una procedura?

è una procedura
*/
#include<iostream>

using namespace std;

#define MAX_COL 4
#define MAX_RIG 4

void maxMatrix(int matrix[][MAX_COL], int &max, int &posixRig, int &posixCol);

int main(){
	int matrix[MAX_RIG][MAX_COL] = {
	{1,4,10,8},
	{8,3,98,2},
	{4,5,76,0},
	{5,1,14,2}
	};
	int max;
	int posixRig;
	int posixCol;
	
	maxMatrix(matrix,max,posixRig,posixCol);
	
	cout<<"Il valore piu' grande e "<<max<<" e si trova alla posizione:\n"<<"riga: "<<posixRig+1<<"\ncolonna: "<<posixCol+1;
	
	return 0;
}

void maxMatrix(int matrix[][MAX_COL], int &max, int &posixRig, int &posixCol){
	max = matrix[0][0];
	
	for(int i=0;i<MAX_RIG;i++){
		for(int j=0;j<MAX_COL;j++){
			if(max<matrix[i][j]){
				max = matrix[i][j];
				posixRig = i;
				posixCol = j;
			}
		}
	}
	
}


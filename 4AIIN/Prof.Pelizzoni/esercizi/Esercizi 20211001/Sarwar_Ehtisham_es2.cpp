#include<iostream>

using namespace std;

int* alloca(int numRighe, int numColonne);
void riempi(int *matrice, int numRighe, int numColonne);
int cerca(int *matrice,int chiave, int numRighe, int numColonne);


int main(){
	int numRighe, numColonne;
	int *matrice;
	int chiave;
	int *posiz = NULL;
	int contRig = 0;
	int num;
	
	do{
		cout<<"Inserire il numero di colonne: ";
		cin>>numColonne;
	}while(numColonne<=0);
	
	do{
		cout<<"Inserire il numero dei righe: ";
		cin>>numRighe;
	}while(numRighe<=0);
	
	matrice = alloca(numRighe, numColonne);
	riempi(matrice, numRighe, numColonne);
	
	cout<<"Inserire un valore da ricercare: ";
	cin>>chiave;
	
	num = cerca(matrice, chiave, numRighe, numColonne);
	
	while(num>numColonne-1){
		if(num -= numColonne-1>=0){
			num -= numColonne-1;
			contRig++;
		}
	}
	
	cout<<"L'elemento si trova alla riga: "<<contRig<<"\nColonna: "<<num;
	
	
	return 0;
}

int* alloca(int numRighe, int numColonne){
	int* matrice;
	matrice = new int[numRighe*numColonne];
	
	return matrice;
}

void riempi(int *matrice, int numRighe, int numColonne){
	for(int i=0;i<numRighe*numColonne;i++){
		cout<<"Inserire un dato per la riga "<<i/numColonne<<" e colonna "<<i%numRighe;
		cin>>matrice[i];
	}
}

int cerca(int *matrice,int chiave, int numRighe, int numColonne){
	for(int i=0;i<numRighe*numColonne;i++){
		if(matrice[i] == chiave){
			return i;
		}
	}
	
	return -1;
}

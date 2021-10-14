#include<iostream>
#define MAX_RIGHE 4
#define MAX_COLONNE 3

using namespace std;


int main () {
	int vet[MAX_RIGHE][MAX_COLONNE], i, j, cont=0, cont_max, num_Colonna;
	
	for(i=0;i<MAX_RIGHE;i++){
		for(j=0;j<MAX_COLONNE;j++){
			cout<<"Inserire un numero per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>vet[i][j];
		}
	}
	
	for(i=0;i<MAX_COLONNE;i++){
		for(j=0;j<MAX_RIGHE;j++){
			if(vet[j][i]%2!=0){
				cont++;
			}
		}
		
		if(cont>cont_max){
			num_Colonna=i;
			cont_max=cont;
		}
		
		cont=0;
	}
	
	cout<<"numero colonna: "<<num_Colonna;
	cout<<"\n\n";
	
	for(i=num_Colonna;i<num_Colonna+1;i++){
		for(j=0;j<MAX_RIGHE;j++){
			cout<<vet[j][i]<<endl;
		}
	}
	
	return 0;
}

#include<iostream>
#include<string.h>

using namespace std;

#define MAX_MAGAZ 30
#define MAX_MAGAZ_FINE MAX_MAGAZ*2

typedef struct{
	char codProd[6];
	unsigned int quantita;
}prodotto;

void Insert(prodotto magaz[],int &numProdMagaz);
void merge(prodotto magaz1[], int numProdMaga1, prodotto magaz2[], int numProdMaga2, prodotto magaz3[], int &numProdMagaz3);
void stampa(prodotto magaz[], int numProdMagaz);

int main(){
	prodotto magaz1[MAX_MAGAZ], magaz2[MAX_MAGAZ], magaz3[MAX_MAGAZ_FINE];
	int numProdMagaz1, numProdMagaz2, numProdMagaz3;
	
	cout<<"MAGAZZINO 1 "<<endl;
	Insert(magaz1, numProdMagaz1);
	cout<<"MAGAZZINO 2 "<<endl;
	Insert(magaz2, numProdMagaz2);
	
	merge(magaz1, numProdMagaz1, magaz2, numProdMagaz2, magaz3, numProdMagaz3);
	
	stampa(magaz3, numProdMagaz3);
	return 0;
}

void Insert(prodotto magaz[],int &numProdMagaz){
	do{
		cout<<"\nQuanti prodotto vuole inserire: ";
		cin>>numProdMagaz;
	}while(numProdMagaz<=0 || numProdMagaz>MAX_MAGAZ);
	
	for(int i=0;i<numProdMagaz;i++){
		cout<<"\nProdotto ["<<i+1<<"]: ";
		cout<<"\nInserire il codice del prodotto: ";
		cin>>magaz[i].codProd;
		cout<<"Inserire la quantita' del prodotto: ";
		cin>>magaz[i].quantita;
	}
}

void merge(prodotto magaz1[], int numProdMaga1, prodotto magaz2[], int numProdMaga2, prodotto magaz3[], int &numProdMagaz3){
	int temp1=0, temp2=0, temp3=0, trovato = 1;
	
	for(int i=0;i<MAX_MAGAZ_FINE&&trovato;i++){
		if(strcmp(magaz1[temp1].codProd,magaz2[temp2].codProd)<0 && temp2<numProdMaga2 && temp1<numProdMaga1){
			magaz3[temp3] = magaz1[temp1];
			temp1++;
			temp3++;
		} else if(strcmp(magaz2[temp2].codProd,magaz1[temp1].codProd)<0 && temp2<numProdMaga2 && temp1<numProdMaga1){
			magaz3[temp3] = magaz2[temp2];
			temp2++;
			temp3++;
		} else if(strcmp(magaz1[temp1].codProd,magaz2[temp2].codProd)==0 && temp2<numProdMaga2 && temp1<numProdMaga1){
			strcpy(magaz3[temp3].codProd,magaz1[temp1].codProd);
			magaz3[temp3].quantita = magaz1[temp1].quantita+magaz2[temp2].quantita; 
			temp1++;
			temp2++;
			temp3++;
		} else if(temp2<numProdMaga2){
			magaz3[temp3] = magaz2[temp2];
			temp3++;
			temp2++;
		} else if(temp1<numProdMaga1){
			magaz3[temp3] = magaz1[temp1];
			temp3++;
			temp1++;
		} else{
			trovato = 0;
		}
	}
	numProdMagaz3 = temp3;
}

void stampa(prodotto magaz[], int numProdMagaz){
	cout<<"\n\nMAGAZZINO 3:";
	for(int i=0;i<numProdMagaz;i++){
		cout<<"\n\nProdotto "<<i+1;
		cout<<"\ncodice prodotto: "<<magaz[i].codProd;
		cout<<"\nquantita prodotto: "<<magaz[i].quantita;
	}	
}


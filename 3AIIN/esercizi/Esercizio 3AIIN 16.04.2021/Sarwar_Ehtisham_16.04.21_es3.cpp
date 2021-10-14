#include<iostream>

using namespace std;

#define DIM_MAX 10

int contaPari(const int vett[], int numElem);

int main(){
	int vett[DIM_MAX] = {1,2,3,4,5,6,7,8,9,10};
	int numElem = sizeof(vett)/sizeof(vett[0]);
	int numPari=0;
	
	numPari = contaPari(vett,numElem);
	
	cout<<"Numeri pari nel vettore sono: "<<numPari;
	
	return 0;
}

int contaPari(const int vett[], int numElem){
	if(numElem==0)
		return 0;
	else {
		if(vett[numElem-1]%2==0)
//			cout<<vett[numElem-1];
			return contaPari(vett,numElem-1)+1;
		else
			return contaPari(vett,numElem-1);
	}
}


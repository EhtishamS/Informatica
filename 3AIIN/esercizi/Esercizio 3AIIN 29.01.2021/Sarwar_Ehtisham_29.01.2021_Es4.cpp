#include<iostream>

using namespace std;

int main (){
	int vet[]={3,3,3,2,1,4,2,1,3,5,5};
	int max_num, max_seq=0, cont, num=vet[0], i, j, numElem=sizeof(vet)/sizeof(vet[0]);
	
	max_num=vet[0];
	
	for(i=0;i<numElem;i++){
		if(vet[i]>max_num){
			max_num=vet[i];
		}	
	}	
	
	for(i=0;i<max_num;i++){
		cont=0;
		for(j=0;j<numElem;j++){
			if(vet[j]==i){
				cont++;
			}
		}
		if(cont>max_seq){
			max_seq=cont;
			num=i;
		}
	}
	
	cout<<"Il numero che e' stato ripetuto piu' volte e': "<<num<<"\nE' stato ripetuto "<<max_seq<<" volte!";
	
	return 0;
}

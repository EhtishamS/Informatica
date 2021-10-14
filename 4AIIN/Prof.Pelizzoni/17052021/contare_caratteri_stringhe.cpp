#include<iostream>
#include<string.h>

#define DIM_MAX 20
#define DIM_STR DIM_MAX+1

using namespace std;


typedef struct{
	char car;
	int conta;
}cella;

int insert(cella *v, const char *stringa);
void stampa(const cella *v, int numElem);

int main(){
	cella v[DIM_MAX];
	char stringa[DIM_STR] = "kkkksfffLLRRRRrrrssk";
	int numElem = insert(v,stringa);
	
	stampa(v,numElem);
	
	
	return 0;
}

int insert(cella *v, const char *stringa){
	int indexV = 0;
	int i=1;
	v[indexV].car = stringa[0];
	v[indexV].conta = 1;
	
	for(;i<strlen(stringa);i++){
		if(stringa[i] == stringa[i-1]){
			v[indexV].conta++;
		} else {
			indexV++;
			v[indexV].car = stringa[i];
			v[indexV].conta = 1;
		}
	}
	
	return indexV;
}

void stampa(const cella *v, int numElem){
	for(int i=0;i<numElem;i++){
		cout<<v[i].car<<"\t";
	}
	
	cout<<"\n";
	
	for(int i=0;i<numElem;i++){
		cout<<v[i].conta<<"\t";
	}
}


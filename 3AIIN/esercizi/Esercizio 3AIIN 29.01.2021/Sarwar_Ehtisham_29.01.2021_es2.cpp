#include<iostream>
#include<time.h>
#include<stdlib.h>

#define MAX 20
#define INIZ 5
#define NUM_GEN 15
#define CAR '#'

using namespace std;

int main (){
	int vet[MAX], i, j, max=0;
	
	srand(time(NULL));
	
	for(i=0;i<MAX;i++){
		vet[i]=rand()%NUM_GEN+INIZ;
		if(vet[i]>max){
			max=vet[i];
		}
	}
	
	
	for(i=0;i<MAX;i++){
		cout<<vet[i]<<"\t";
	}
	
	for(i=0;i<max;i++){
		cout<<"\n";
		for(j=0;j<MAX;j++){
			if(vet[j]>0){
				vet[j]--;
				cout<<CAR<<"\t";
			} else {
				cout<<"\t";
			}
		}
	}
	
	return 0;
}

#include<iostream>
#include<string.h>
#define MAX 100

using namespace std;

int main (){
    char strvet[MAX], i, flag=0, lunghezza;

    do{
    	cout<<"Inserire una stringa di caratteri: ";
    	cin>>strvet;
	}while(strlen(strvet)>MAX);
	
	lunghezza= strlen(strvet);
    
    for(i=0;i<lunghezza/2&&flag==0;i++){
    	if(strvet[i]!=strvet[lunghezza-(i+1)]){
    		flag=1;
		}
	}
	
	if(flag==1){
		cout<<"Sequenza non palindroma!";
	} else {
		cout<<"Sequenza palindroma!";
	}
   	return 0;    
}

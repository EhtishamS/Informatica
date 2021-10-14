#include<iostream>
#include<string.h>

#define MAX 100
#define SPACE 32
using namespace std;

int main (){
	char str[MAX];
	int i, j, lunghezza;
	
	do{
		cout<<"Inserire una stringa: ";
		gets(str);
		lunghezza = strlen(str)+1;
	}while(lunghezza <= 1);
	
	for(i=0;i<lunghezza-1;i++){
		if(str[i] == SPACE){
			for(j=i;j<lunghezza-1;j++){
				str[j]=str[j+1];
			}
		}
	}
	
	cout<<str;
	
	return 0;
}

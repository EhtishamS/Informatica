#include<iostream>
#include<string.h>

#define MAX 16 
#define TEMP 80
#define SPAZIO 32

using namespace std;


int main () {
	char str[MAX], temp[TEMP], car;
	int lunghezza, flag = 0, i;
	
	do{
		cout<<"Inserire qualcosa nella stringa: ";
		gets(temp);
		lunghezza = strlen (temp)+1;
		flag = 0;
		for(i=0;i<lunghezza-1&&flag==0;i++){
			if(temp[i]!=SPAZIO){
				if(temp[i]>'z' || temp[i]<'A'){
					flag = 1;
				} else if (temp[i]>'Z' && temp[i]<'a'){
					flag = 1;
				}
			}
		}
	}while(lunghezza <= 1 || lunghezza >= MAX || flag == 1);
	
	strcpy(str,temp);
	
	cout<<"La stringa controllata: "<<str;
}

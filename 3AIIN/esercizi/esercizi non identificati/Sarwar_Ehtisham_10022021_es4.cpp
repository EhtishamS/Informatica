#include<iostream>
#include<string.h>

#define MAX 25

using namespace std;

int main (){
	char strvet1[MAX], strvet2[MAX], strvet3[MAX];
	int i, j=0, string_measure_min;
	
	do{
		cout<<"Inserire una parola: ";
		cin>>strvet1;
		cout<<"Inserire una seconda parola: ";
		cin>>strvet2;
	} while(strlen(strvet1)>MAX || strlen(strvet2)>MAX);
	
	if(strlen(strvet1)>strlen(strvet2)){
		string_measure_min = strlen(strvet2);
	} else {
		string_measure_min = strlen(strvet1);
	}
	
	for(i=0;i<strlen(strvet1)+strlen(strvet2);i++){
		if(i>=string_measure_min){
			if(strlen(strvet1)==string_measure_min){
				strvet3[j]=strvet2[i];
				j++;
			} else {
				strvet3[j]=strvet1[i];
				j++;
			}
		} else {
			strvet3[j]=strvet1[i];
			j++;
			strvet3[j]=strvet2[i];
			j++;
		}
	}
	
	cout<<strvet1<<endl;
	cout<<strvet2<<endl;
	cout<<strvet3;
	
	return 0;
}

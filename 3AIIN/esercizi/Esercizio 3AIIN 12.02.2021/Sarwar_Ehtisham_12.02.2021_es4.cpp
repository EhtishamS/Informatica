#include<iostream>

#define RIGHE 3
#define COLONNE 10
using namespace std;

int main (){
	char car1, car2;
	int i, j;
	
	do{
		cout<<"Inserire un carattere in maiuscolo: ";
		cin>>car1;
		cout<<"Inserire un altro carattere in maiuscolo diverso dal primo: ";
		cin>>car2;
	}while((car1 < 'A' || car1 > 'Z') || (car2 < 'A' || car2 > 'Z') || (car1 == car2));
	
	for(i=0;i<RIGHE;i++){
		for(j=0;j<COLONNE;j++){
			if(i%2==0){
				if(j%2==0){
					cout<<car2;
				} else {
					cout<<car1;
				}
			} else {
				if(j%2==0){
					cout<<car1;
				} else {
					cout<<car2;
				}
			}
		}
		cout<<endl;
	}
	
	return 0;
	
}

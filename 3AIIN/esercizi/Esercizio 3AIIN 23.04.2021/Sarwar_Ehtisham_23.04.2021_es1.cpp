#include<iostream>
#include<fstream>

using namespace std;

int main(){
	char car; 
	int cont = 0;
	
	// ripete fino a quanto inserisco ctrl+z
	while((car = cin.get()) != EOF){
		cont++;
	}
	
	cout<<cont;
	
	return 0;
}


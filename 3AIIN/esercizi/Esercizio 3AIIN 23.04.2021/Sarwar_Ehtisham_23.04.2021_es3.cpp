#include<iostream>
#include<fstream>

#define INFILE "input_es_3.txt"
#define OUTFILE "output_es_3.txt"

using namespace std;

int main(){
	ifstream inFile;
	ofstream outFile;
	
	char car;
	int contCar = 0, contRighe = 0;
	
	//lettura dal file input
	inFile.open(INFILE);
	
	if(!inFile){
		cout<<"Impossibile aprire il file!";
	} else {
		
		inFile.get(car);
		
		while(!inFile.eof()){
			if(car == '\n'){
				contRighe++;
			}
			contCar++;
			inFile.get(car);
		}
		
		inFile.close();
	}
	
	//scrittura nel file output
	outFile.open(OUTFILE);
	
	if(!outFile){
		cout<<"Impossibile creare il file di output!";
	} else {
		outFile<<"Caratteri letti: "<<contCar<<"\nRighe lette: "<<contRighe;
		outFile.close();
	}
	
	return 0;
}


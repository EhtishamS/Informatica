#include<iostream>
#include<fstream>

#define INFILE "input_es_2.txt"
#define OUTFILE "output_es_2.txt"

using namespace std;

int fattoriale(int num);

int main(){
	ifstream inFile;
	ofstream outFile;
	
	int somma, num, num1, ris = 0;
	
	inFile.open(INFILE);
	outFile.open(OUTFILE);
	
	if(!inFile){
		cout<<"Impossibile aprire il file!";
	} else {
		
		inFile>>num>>num1;
		
		while(!inFile.eof()){
			somma = fattoriale(num)+fattoriale(num1);
			outFile<<somma<<endl;
			inFile>>num>>num1;
		}
		outFile.close();
		inFile.close();
	}
	
	return 0;
}

int fattoriale(int num){
	if(num==0){
		return 1;
	} else {
		return num*fattoriale(num-1);
	}
}


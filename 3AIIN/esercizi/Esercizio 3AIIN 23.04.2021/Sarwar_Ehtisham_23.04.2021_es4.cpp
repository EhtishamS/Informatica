#include<iostream>
#include<string.h>
#include<fstream>

#define INFILE "input_es_4.txt"
#define OUTFILE "output_es_4.txt"
#define DIM_MAX 80+1

using namespace std;

int main(){
	ifstream inFile;
	ofstream outFile;
	
	char riga[DIM_MAX];
	int lunghezza, contRiga = 1;
	
	//lettura dal file input
	inFile.open(INFILE);
	outFile.open(OUTFILE);
	
	if(!inFile && !outFile){
		cout<<"Impossibile aprire i file!";
	} else {
		inFile.getline(riga, DIM_MAX);
		lunghezza = strlen(riga)-1;
		
		while(!inFile.eof()){
			while(lunghezza>=0){
				
				if(riga[lunghezza] == '\t'){
					if(riga[0]!= ' ' && riga[0] != '\t' && riga[0] != '\n'){
						outFile<<contRiga<<endl;
						cout<<contRiga<<endl;
					}
				}
				
				lunghezza--;
			}
			
			inFile.getline(riga, DIM_MAX);
			lunghezza = strlen(riga)-1;
			contRiga++;
		}
		
		outFile.close();
		inFile.close();
	}
	
	return 0;
}


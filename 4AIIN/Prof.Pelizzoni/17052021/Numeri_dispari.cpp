#include<iostream>
#include<fstream>

using namespace std;

#define IN "input.txt"

int contDisp(int num);

int main(){
	ifstream inFile;
	int num;
		
	inFile.open(IN);
	
	if(!inFile){
		cout<<"Impossibile aprire il file!";
		return 1;
	} 
	
	inFile>>num;
	cout<<num<<"\n";
	
	while(!inFile.eof()){
		cout<<contDisp(num)<<"\n";
		inFile>>num;
		cout<<num<<"\n";
	}
	
	inFile.close();
	
	return 0;
}

int contDisp(int num){
	if(num==0){
		return 0;
	} else {
		if((num%10)%2!=0){
			num/=10;
			return 1+contDisp(num);
		}
		 
		num/=10;
		return contDisp(num);
		
	}
}

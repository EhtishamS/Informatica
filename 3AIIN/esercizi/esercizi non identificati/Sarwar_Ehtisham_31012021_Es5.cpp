#include<iostream>

#define MAX 4

using namespace std;

int main (){
	int mtr[MAX][MAX], mtr2[MAX][MAX], i, j, k;
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<"Digitare un numero per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>mtr[i][j];
		}
	}

	cout<<"\n\n";
	cout<<"Tabella di partenza:";
	cout<<"\n\n";
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<mtr[i][j]<<"\t";	
		}
		cout<<"\n";
	}
	
	for(i=0;i<MAX;i++){
		k=0;
		for(j=MAX-1;j>=0;j--){
			mtr2[i][k]=mtr[j][i];
			k++;
		}
	}
	
	cout<<"\n\n";
	cout<<"Tebella di arrivo:";
	cout<<"\n\n";
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<mtr2[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	return 0;
}

#include<iostream>
#define MAX 3
using namespace std;

int main (){
	int mtr[MAX][MAX], i, j, flag=0;
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<"Inserire il valore per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>mtr[i][j];
		}
	}
	
	
	cout<<"\n\n";
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<mtr[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	for(i=0;i<MAX&&flag==0;i++){
		for(j=0;j<MAX&&flag==0;j++){
			if(j<i){
				if(mtr[i][j]==mtr[j][i]){
					flag=0;
				} else {
					flag=1;
				}
			}
		}
	}
	
	if(flag==0){
		cout<<"\ne simmetrico!";
	} else {
		cout<<"\nnon e simmetrico!";
	}
	

	return 0;	
}

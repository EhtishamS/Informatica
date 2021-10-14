#include<iostream>
#include<time.h>
#include<stdlib.h>

#define MAX 6
#define NUM_GEN 44

using namespace std;

int main (){
	int m1[MAX][MAX], m2[MAX][MAX], i, j;
	
	srand(time(NULL));

	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			m1[i][j]=rand()%NUM_GEN+1;
		}
	}	
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<m1[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	cout<<"\n\n";
	
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			if(j<i){
				m2[i][j]=m1[i][j]+m1[j][i];	
			} else if (j==i){
				m2[i][j]=m1[i][j];
			} else {
				m2[i][j]=0;
			}
		}
	}
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			cout<<m2[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	return 0;
}

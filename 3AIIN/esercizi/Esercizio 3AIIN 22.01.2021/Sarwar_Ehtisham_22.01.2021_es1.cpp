#include<iostream>

using namespace std;

int main (){
	int v[] = {1,2,30,4,5,6,7};
	int i, numElem, temp;
	
	
	numElem = sizeof(v)/sizeof(v[0]);
	temp = v[numElem-1];
		
	for(i=numElem-1;i>0;i--){
		v[i]=v[i-1];
	}
	
	v[0]=temp;
	
	for(i=0;i<numElem;i++){
		cout<<v[i]<<" ";
	}
	
		
	return 0;
}

#include<iostream>

using namespace std;

int stessoSegno(const int a[], int n);
int d(int*y, int m,int a[]);

int main(){
	int n=2, a[4]={-1,0,1,-2}, x=0; 
 
 	x = d(&x,n+1,a);
 	
 	cout<<x;// ritorna 2
	return 0;
}

int stessoSegno(const int a[], int n){
	if(n==0)
		return 1;
	else if(a[n]>=0 && a[n-1]>=0)
		return stessoSegno(a,n-1);
	else if(a[n]<0 && a[n-1]<0)
		return stessoSegno(a,n-1);
	else
		return 0;
}

int d(int*y, int m,int a[]){ 
	int j; 
 	
	for(j=*y; j<m; j++){ 
 		a[j] = a[j] - *y; 
 		(*y)=a[j]*m; 
	}
	  
 	if(stessoSegno(a,m)) 
 		m++; 
 	else 
 		m--; 
 		
 	return m; 
}

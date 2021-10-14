#include<iostream>

using namespace std;

int main(){
    int n, tappo=0;

    do{
        cout<<"Inserire un naturale (0-9): ";
        cin>>n;
    }while(n<0 || n>9);

    for(tappo=0;tappo<n;tappo++){
        cout<<n;
    }
    
    return 0;
}
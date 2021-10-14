#include<iostream>
#define CAR '0'
using namespace std;

int main (){
    int i, j, n;

    do{
        cout<<"Dire un numero positivo maggiore di 1: ";
        cin>>n;
    } while (n<1);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==i){
                cout<<CAR;
                cout<<" ";
            } else {
                cout<<j<<" ";            }
        }
        cout<<"\n";
    }
    return 0;
}
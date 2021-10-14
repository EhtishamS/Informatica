#include<iostream>
#define CAR_CORNICE '*'
#define CAR_CENTRALE '8'

using namespace std;

int main (){
    int i, j, lato;

    do{
        cout<<"Dire quanto e' lungo il lato che deve essere un numero dispari: ";
        cin>>lato;
    } while(lato%2==0);

    for(i=0;i<lato;i++){
        for(j=0;j<lato;j++){
            if(lato/2==j && lato/2==i){
                cout<<CAR_CENTRALE;
                cout<<" ";
            } else {
                cout<<CAR_CORNICE;
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
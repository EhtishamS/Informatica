#include<iostream>

using namespace std;

int main(){
    int r, j, cont=1;

    do{
        cout<<"Inserire quante righe vuole visualizzare: ";
        cin>>r;
    }while(r<0);

    for(int i=1;i<=r;i++){
        for(j=1;j<=i;j++){
            cout<<cont<<" ";    
            cont++;
        }
        cout<<endl;
    }
}
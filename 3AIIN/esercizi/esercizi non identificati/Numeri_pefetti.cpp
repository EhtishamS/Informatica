/*
trovare un numero perfetto e divisibile per il 4
*/

#include<iostream>

using namespace std;

int main(){
    int n1, n2, sum=0;

    do{
        cout<<"Inserire il primo numero: ";
        cin>>n1;
        cout<<"Inserire il secondo numero: ";
        cin>>n2;
    }while(n1<0 || n2<0 || n2<=n1);


    for(int i=n1; i<=n2;i++){
        for(int j=1;j<i;j++){
            if(i%j==0){
                sum=sum+j;
            }
        }
        if(sum==i && sum%4==0){
            cout<<"Il numero "<<sum<<" e perfetto e divisibile per 4"<<endl;
        }
        sum=0;
    }
}
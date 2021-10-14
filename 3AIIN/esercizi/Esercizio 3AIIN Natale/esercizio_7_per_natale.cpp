#include<iostream>

using namespace std;

int main (){
    int INF, SUP, i, temp, flag, resto;
    do{
        cout<<"Inserire il primo estremo: ";
        cin>>INF;
        cout<<"Inserie il secondo estremo: ";
        cin>>SUP;
    } while (INF>SUP || INF<0);

    for(i=INF;i<=SUP;i++){
        flag=0;
        temp=i;        
        while(temp!=0 && flag==0){
            resto=temp%10;

            if(resto!=0){
                if(i%resto==0){ 
                    flag=0;
                } else {
                    flag=1;
                }
            }
            temp = temp/10; 
        }

        if(flag==0){
            cout<<"Il numero trovato di Lynch-Bell: "<<i<<"\n";
        }
    }
    return 0;
}

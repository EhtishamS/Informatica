#include<iostream>

using namespace std;

#define MAX 10

void print(const int list[], int numElem);

int main(){
    int list[MAX], numElem;

    do{
        cout<<"Inserisci il numero di elementi: ";
        cin>>numElem;
    }while(numElem<=0 || numElem>MAX);

    for(int i=0; i<numElem;i++){
        cout<<"Inserire il contenuto per la cella ["<<i+1<<"]: ";
        cin>>list[i];
    }

    print(list,numElem);

    return 0;
}

void print(const int list[], int numElem){
    if(numElem>0){
        cout<<list[numElem-1]<<" ";
        print(list,numElem-=1);    
    }
}

#include<iostream>
#define TAPPO 0
#define DIM_MAX 10
#define LIMIT_MAX 31

using namespace std;

int main (){
    int collega_1[DIM_MAX], collega_2[DIM_MAX], i, giorno=1, j;

    for(i=0;i<DIM_MAX && giorno!=TAPPO;i++){
        cout<<"(1)Scrivi il giorno in qui sei disposibile: ";
        cin>>giorno;
        if(giorno>TAPPO && giorno<=LIMIT_MAX){
            collega_1[i]=giorno;
        }
    }
	
	giorno = 1;
    for(i=0;i<DIM_MAX && giorno!=TAPPO;i++){
        cout<<"(2)Scrivi il giorno in qui sei disposibile: ";
        cin>>giorno;
        if(giorno>TAPPO && giorno<=LIMIT_MAX){
            collega_2[i]=giorno;
        }
    }

    for(i=0;i<DIM_MAX;i++){
        for(j=0;j<DIM_MAX;j++){
            if(collega_1[i] == collega_2[j] && collega_2[j] !=0){
                cout<<"\nIl giorno in comune e': "<<collega_1[i];
            }
        }
    }



    
    return 0;
}


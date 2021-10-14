#include<iostream>
#define DIM_MAX 8

using namespace std; 

int main (){
    char mtr[DIM_MAX][DIM_MAX], color1, color2;
    int i, j;

    
    do{
        cout<<"\n\n\n";
        cout<<"Colori che puoi scegliere: ";
        cout<<"\nb = bianco.";
        cout<<"\nr = rosso.";
        cout<<"\nv = verde.";
        cout<<"\na = azzurro.";
        cout<<"\nn = nero.";
        cout<<"\n\n\n";

        cout<<"Scegliere il primo colore: ";
        cin>>color1;
        cout<<"Scegliere il secondo colore: ";
        cin>>color2;
    } while ((color1 != 'b' && color1 != 'r' && color1 != 'v' && color1 != 'a' && color1 != 'n') || (color2 != 'b' && color2 != 'r' && color2 != 'v' && color2 != 'a' && color2 != 'n') || color1 == color2);

    for(i=0;i<DIM_MAX;i++){
        for(j=0;j<DIM_MAX;j++){
        	if(i%2==0){
        		if((i%2==0 && j%2==0)){
                	mtr[i][j]=color1;
            	} else {
               		mtr[i][j]=color2;
            	}
			} else {
				if(j%2==0){
					mtr[i][j]=color2;
				} else {
					mtr[i][j]=color1;
				}
			}
        }
    }
    
    for(i=0;i<DIM_MAX;i++){
    	for(j=0;j<DIM_MAX;j++){
    		cout<<mtr[i][j]<<"\t";
		}
		cout<<endl;
		
	}
    return 0;
}

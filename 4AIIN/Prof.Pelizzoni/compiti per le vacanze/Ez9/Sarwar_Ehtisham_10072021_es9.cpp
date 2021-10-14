#include<iostream>
#include<fstream>

using namespace std;

#define INPUT "input.txt"
#define N 10

void inizializza(int matrx[][N+1]);
bool riempimento(int matrx[][N+1],int x1, int y1, int x2, int y2);

int main(){
    int matrx[N+1][N+1];
    int x1,x2,y1,y2;
    bool risultato=true;
    
    inizializza(matrx);

    fstream inFile;

    inFile.open(INPUT,ios::in);

    if(!inFile){
        cout<<"Impossibile aprire il file!";
    } else{
        inFile>>x1>>y1>>x2>>y2;
		
        risultato = riempimento(matrx,x1,y1,x2,y2);
		
        while(!inFile.eof() && risultato==true){
            inFile>>x1>>y1>>x2>>y2;

            risultato = riempimento(matrx,x1,y1,x2,y2);
        	
            if(risultato == false){
                cout<<"I rettangoli hanno (almeno) una sovrapposizione\n";
            }
        }

        inFile.close();
    }

    if(risultato == true){
        cout<<"Nessuna sovrapposizione tra i rettangoli\n";
    }
    
    stampaMatrice(matrx);
    
    return 0;
}

void inizializza(int matrx[][N+1]){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            matrx[i][j] = 0;
        }
    }
}

bool riempimento(int matrx[][N+1],int x1, int y1, int x2, int y2){
    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
                if(matrx[i][j]!=0){
                    return false;
                }

                matrx[i][j] = 1;
        }
    }

    return true;
}

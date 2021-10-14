#include<iostream>
#include<fstream>

#define EDIFICIO "edificio.txt"
#define METRI_QUADRATI 10000 
#define METRI_CUBI 1000000

using namespace std;

int main (){
    fstream inFile;

    int numPiani, altezza, numStanze, latoBase1, latoBase2, i, j, volumeTotale = 0, volumeStanza, superficieTotale = 0, superficieStanza;

    inFile.open(EDIFICIO,ios::in);

    if(!inFile){
        cout<<"Impossibile leggere il file!";
        return 1;
    }

    inFile>>numPiani;

    for(i=1;i<=numPiani;i++){
        inFile>>numStanze>>altezza;
        // cout<<numStanze;
        for(j = 1;j<=numStanze;j++){
            inFile>>latoBase1>>latoBase2;

            superficieStanza = latoBase1*latoBase2;
            superficieTotale += superficieStanza;

            volumeStanza = latoBase1*latoBase2*altezza;
            volumeTotale += volumeStanza;
        }
    }

    inFile.close();

    cout<<"Volume Totale dell'edificio e uguale a "<<volumeTotale/METRI_CUBI<<" metri cubi";
    cout<<"\nLA superificie totale dell'edificio e uguale a "<<superficieTotale/METRI_QUADRATI<<" metri quadri";
    return 0;
}
#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>

using namespace std;

#define MAX 200
#define DIM_MAX_STR 15
#define FILENAME "appuntamenti.txt"

enum tipi{MODERNA, PFITZER, ASTRAZENECA, JANSSEN};

struct quantita{
    int numModerna;
    int numPfitzer;
    int numAstrazeneca;
    int numJanssen; 
};

struct dataAppuntamento{
    int giorno;
    int mese;
    int anno;
    int ore;
    int minuti;
};

struct vaccini{
    tipi tipoVaccino;
    dataAppuntamento data;
};

int menu();
int insertAppuntamenti(vaccini appuntamenti[], quantita &quantitaVaccini, int &numAppuntamenti);
void stampaAppuntamenti(vaccini appuntamenti[], quantita &quantitaVaccini, int numAppuntamenti);
void shuffle(vaccini appuntamenti[], int numAppuntamenti);
void sort(vaccini appuntamenti[],int numAppuntamenti);
int dataMinoreUguale(dataAppuntamento data1, dataAppuntamento data2);
void ultimoGiornoPossibile(vaccini appuntamenti[], quantita quantitaVaccini, int vaccinoScelto, int numAppuntamenti);

int main(){
    vaccini appuntamenti[MAX];
    quantita quantitaVaccini;
    int erroreFile;
    int numAppuntamenti = 0;
    int vaccinoScelto;
    int scelta;

    srand(time(NULL));

    do{
        scelta = menu();

        switch(scelta){
            case 1:
                erroreFile = insertAppuntamenti(appuntamenti,quantitaVaccini,numAppuntamenti);

                if(erroreFile)
                    cout<<"\nImpossible aprire il file!\n";
                else  
                    cout<<"\nDati aggiunti senza problemi!\n";
                break;
            case 2:
                stampaAppuntamenti(appuntamenti,quantitaVaccini,numAppuntamenti);
                break;
            case 3:
                shuffle(appuntamenti,numAppuntamenti);
                break;
            case 4:
                sort(appuntamenti,numAppuntamenti);
                break;
            case 5:
                do{
                    cout<<"\nScegliere un vaccino tra i seguenti: \n";
                    cout<<"1. Moderna"<<endl;
                    cout<<"2. Pfitzer"<<endl;
                    cout<<"3. AstraZeneca"<<endl;
                    cout<<"4. Janssen"<<endl;
                    cout<<"Inserire la scelta:\n> ";
                    cin>>vaccinoScelto;
                }while(vaccinoScelto<1 || vaccinoScelto>4);
                vaccinoScelto-=1;

                ultimoGiornoPossibile(appuntamenti,quantitaVaccini,vaccinoScelto,numAppuntamenti);
                break;
        }
    }while(scelta!=0);

    cout<<"\nProgramma terminato!";
    
    return 0;
}

int menu(){
    int scelta;

    do{
        cout<<"\nMENU:"<<endl;
        cout<<"1. Inserimento appuntamenti dal file."<<endl;
        cout<<"2. Stampa appuntamenti."<<endl;
        cout<<"3. Mescolare l'ordine dei appuntamenti."<<endl;
        cout<<"4. Ordinare gli appuntamenti per la data crescente."<<endl;
        cout<<"5. Stampare l'ultimo appuntamento per un certo vaccino."<<endl;
        cout<<"0. Fine lavoro."<<endl;
        cout<<"Scegliere tra le opzioni date:\n> ";
        cin>>scelta;
    }while(scelta<0 || scelta>5);

    return scelta;
}

int insertAppuntamenti(vaccini appuntamenti[], quantita &quantitaVaccini, int &numAppuntamenti){
    char tipo[DIM_MAX_STR], ignore;

    quantitaVaccini.numModerna = 0;
    quantitaVaccini.numPfitzer = 0;
    quantitaVaccini.numAstrazeneca = 0;
    quantitaVaccini.numJanssen = 0;

    fstream fileIn;

    fileIn.open(FILENAME,ios::in);

    if(!fileIn){
        return 1;
    } 
    
    fileIn>>appuntamenti[numAppuntamenti].data.giorno>>ignore;
    fileIn>>appuntamenti[numAppuntamenti].data.mese>>ignore;
    fileIn>>appuntamenti[numAppuntamenti].data.anno;
    fileIn>>appuntamenti[numAppuntamenti].data.ore>>ignore;
    fileIn>>appuntamenti[numAppuntamenti].data.minuti;
    fileIn>>tipo;

    if(tipo[0] == 'M'){
        appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 0;
        quantitaVaccini.numModerna = 1;
    } else if(tipo[0] == 'P'){
        appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 1;
        quantitaVaccini.numPfitzer = 1;
    } else if(tipo[0] == 'A'){
        appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 2;
        quantitaVaccini.numAstrazeneca = 1;
    } else{
        appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 3;
        quantitaVaccini.numJanssen = 1;
    }

    numAppuntamenti++;

    while(!fileIn.eof()){

        fileIn>>appuntamenti[numAppuntamenti].data.giorno>>ignore;
        fileIn>>appuntamenti[numAppuntamenti].data.mese>>ignore;
        fileIn>>appuntamenti[numAppuntamenti].data.anno;
        fileIn>>appuntamenti[numAppuntamenti].data.ore>>ignore;
        fileIn>>appuntamenti[numAppuntamenti].data.minuti;
        fileIn>>tipo;

        if(tipo[0] == 'M'){
            appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 0;
            quantitaVaccini.numModerna++;
        } else if(tipo[0] == 'P'){
            appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 1;
            quantitaVaccini.numPfitzer++;
        } else if(tipo[0] == 'A'){
            appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 2;
            quantitaVaccini.numAstrazeneca++;
        } else{
            appuntamenti[numAppuntamenti].tipoVaccino = (tipi) 3;
            quantitaVaccini.numJanssen++;
        }
        numAppuntamenti++;
    }

    return 0;
}

void stampaAppuntamenti(vaccini appuntamenti[], quantita &quantitaVaccini, int numAppuntamenti){
    cout<<"\n\nSTAMPA APPUNTAMENTI\n";
    cout<<"DATA:\t\tORE:\tTIPO VACCINO:\n";
    for(int i=0;i<numAppuntamenti;i++){
        cout<<appuntamenti[i].data.giorno<<"/";
        cout<<appuntamenti[i].data.mese<<"/";
        cout<<appuntamenti[i].data.anno<<"\t";
        cout<<appuntamenti[i].data.ore<<":";
        cout<<appuntamenti[i].data.minuti<<"\t";

        switch(appuntamenti[i].tipoVaccino){
            case 0: 
                cout<<"Moderna\n";
                break;
            case 1: 
                cout<<"Pfitzer\n";
                break;
            case 2:
                cout<<"AstraZeneca\n";
                break;
            case 3:
                cout<<"Janssen\n";
                break;
        }
    }

    cout<<"\nQuantita vaccini:\n";
    cout<<"Moderna: "<<quantitaVaccini.numModerna<<endl;
    cout<<"Pfitzer: "<<quantitaVaccini.numPfitzer<<endl;
    cout<<"AstraZeneca: "<<quantitaVaccini.numAstrazeneca<<endl;
    cout<<"Janssen: "<<quantitaVaccini.numJanssen<<endl;
}

void shuffle(vaccini appuntamenti[], int numAppuntamenti){
    int num1, num2;
    vaccini temp;

    for(int i=0;i<numAppuntamenti/2;i++){
        do{
            num1=rand()%numAppuntamenti;
            num2=rand()%numAppuntamenti;
        }while(num1==num2);

        temp = appuntamenti[num1];
        appuntamenti[num1] = appuntamenti[num2];
        appuntamenti[num2] = temp;
    }
}

void sort(vaccini appuntamenti[],int numAppuntamenti){
    vaccini temp;
    int min;

    for(int i=0;i<numAppuntamenti-1;i++){
        min = i;
        for(int j=i+1;j<numAppuntamenti;j++){
            if(dataMinoreUguale(appuntamenti[min].data,appuntamenti[j].data)){
                min = j;
            }
        }

        temp = appuntamenti[min];
        appuntamenti[min] = appuntamenti[i];
        appuntamenti[i] = temp;
    }
}

int dataMinoreUguale(dataAppuntamento data1, dataAppuntamento data2){
    if(data1.anno>data2.anno){
        return 1;
    } else if(data1.anno==data2.anno){
        if(data1.mese>data2.mese){
            return 1;
        } else if(data1.mese==data2.mese){
            if(data1.giorno>data2.giorno){
                return 1;
            } else if(data1.giorno==data2.giorno){
                if(data1.ore>data2.ore){
                    return 1;
                } else if(data1.ore==data2.ore){
                    if(data1.minuti>data2.minuti){
                        return 1;
                    }
                }
            }
        }

    }

    return 0;
}

void ultimoGiornoPossibile(vaccini appuntamenti[], quantita quantitaVaccini, int vaccinoScelto, int numAppuntamenti){
    int i;
    int j = 0;

    switch(vaccinoScelto){
        case 0:
            i = quantitaVaccini.numModerna;
            break;
        case 1:
            i = quantitaVaccini.numPfitzer;
            break;
        case 2:
            i = quantitaVaccini.numAstrazeneca;
            break;
        case 3:
            i = quantitaVaccini.numJanssen;
            break;
    }
    
    while(i!=0){
        if(appuntamenti[j].tipoVaccino==vaccinoScelto)
            i--;
        j++;
    }

    cout<<"\nl'ultima data del vaccino scelto e il: ";
    cout<<appuntamenti[j-1].data.giorno<<"/";
    cout<<appuntamenti[j-1].data.mese<<"/";
    cout<<appuntamenti[j-1].data.anno<<" ";
    cout<<appuntamenti[j-1].data.ore<<":";
    cout<<appuntamenti[j-1].data.minuti<<endl;
    
}

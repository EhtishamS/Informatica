#include<iostream>
#include<string.h>
 
#define VEICOLO_NOME 20+1
#define VEICOLO_MARCA 15+1
#define MAX_TEMP 80
#define MAX_MACCHINE 10

using namespace std;

enum motore{BENZINA,DISEL};

typedef struct veicoli{
    char nomeVeicolo[VEICOLO_NOME];
    char marca[VEICOLO_MARCA];
    motore tipoMot;
    int numCilindri;
    int tipoAccessorio; 
}autovettura;

struct car{
    autovettura macchine[MAX_MACCHINE];
    int numMacchine; 
};

void inserimento(car & veicoli);
void stampaMacchina(car & veicoli);

int main(){
    car veicoli;
    do{
        cout<<"Quante macchine vuole inserire: ";
        cin>>veicoli.numMacchine;
    }while(veicoli.numMacchine<=0 || veicoli.numMacchine>MAX_MACCHINE);

    inserimento(veicoli);
    stampaMacchina(veicoli);
}

void inserimento(car & veicoli){
    int i, temp;
    char test[MAX_TEMP];

    for(i=0;i<veicoli.numMacchine;i++){

        do{
            cout<<"\nInserire il nome della macchina(<=20): ";
            cin>>test;
        }while(strlen(test)>VEICOLO_NOME);
        strcpy(veicoli.macchine[i].nomeVeicolo, test);
        
        do{
            cout<<"Inserire la marca del veicolo (<=15): ";
            cin>>test;
        }while(strlen(test)>VEICOLO_MARCA);
        strcpy(veicoli.macchine[i].marca, test);

        do{
            cout<<"Di che tipo di motore ha per il benzina inserisci 1 e per disel inserisci 2: ";
            cin>>temp;
        }while(temp<1 || temp>2);
        temp--;
        veicoli.macchine[i].tipoMot = (motore) temp;

        // if(temp==1){
        //     veicoli.macchine[i].tipoMotore = BENZINA;  
        // } else {
        //      veicoli.macchine[i].tipoMotore = DISEL;
        // }
           
        
        do{
            cout<<"Quanti cilindri ha il suo veicolo (4,6,8): ";
            cin>>temp;
        }while((temp<4 || temp>8) ||(temp == 5 || temp == 7));
        veicoli.macchine[i].numCilindri = temp;
        
        do{
            cout<<"Quanti accessori ha il tuo veicolo (<=50): ";
            cin>>veicoli.macchine[i].tipoAccessorio;
        }while(veicoli.macchine[i].tipoAccessorio<=0 || veicoli.macchine[i].tipoAccessorio>50);
        
    }
    
}

void stampaMacchina(car & veicoli){
    int i;

    for(i=0;i<veicoli.numMacchine;i++){
        cout<<"\n\n";
        cout<<"veicolo: "<<i+1<<endl;
        cout<<"Nome della macchina: "<<veicoli.macchine[i].nomeVeicolo<<endl;
        cout<<"Marca del veicolo: "<<veicoli.macchine[i].marca<<endl;
        if(veicoli.macchine[i].tipoMot == DISEL){
            cout<<"Tipo di motore: Disel"<<endl;
        } else {
            cout<<"Tipo di motore: Benzina"<<endl;
        }
        cout<<"Numero di Cilindri: "<<veicoli.macchine[i].numCilindri<<endl;
        cout<<"Numero di accessori: "<<veicoli.macchine[i].tipoAccessorio<<endl;
    }
}

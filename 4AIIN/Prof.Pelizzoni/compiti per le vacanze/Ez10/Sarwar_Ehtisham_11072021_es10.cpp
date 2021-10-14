#include<iostream>
#include<string.h>

using namespace std;

#define DIM_MAX_STR 30
#define MAX_CITTA 20

struct citta{
    char citta[DIM_MAX_STR];
    bool visitato;
};

void inserimentoCitta(citta city[], int *N);
void inizializza(int distanze[][DIM_MAX_STR], int N);
void inserimentoDistanze(citta city[], int distanze[][DIM_MAX_STR],const int N, int &max);
void stampa(int distanze[][DIM_MAX_STR],int *N);
void cercaPercorsoMigliore(citta city[],const int distanze[][DIM_MAX_STR], const char *nomeCitta, const int N, int max);
int ricercaCitta(citta city[],const char *nomeCitta ,const int N);

int main(){
    int N;
    int distanze[DIM_MAX_STR][DIM_MAX_STR];
    int max;
    char cittaCercare[DIM_MAX_STR];
    
    citta city[MAX_CITTA];

    inserimentoCitta(city,&N);
    inizializza(distanze,N);
    inserimentoDistanze(city,distanze,N,max);
    // stampa(distanze,&N);

    cout<<"\nInserire il nome di una citta: ";
    cin>>cittaCercare;

    cercaPercorsoMigliore(city,distanze,cittaCercare,N,max);


    return 0;
}

void inserimentoCitta(citta city[], int *N){
    do{
        cout<<"Quante citta' vuole inserire: ";
        cin>>*N;
    }while(*N<1);

    cout<<"\nINSERIMENTO CITTA\n";

    for(int i=0;i<*N;i++){
        cout<<"Inserire il nome della citta numero "<<i+1<<": ";
        cin>>city[i].citta;
        city[i].visitato = false;
    }
}

void inizializza(int distanze[][DIM_MAX_STR], int N){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            distanze[i][j] = 0;
        }
    }
}

void inserimentoDistanze(citta city[], int distanze[][DIM_MAX_STR],const int N, int &max){

    cout<<"\nINSERIMENTO DISTANZE\n";
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            do{
                cout<<"Inserire la distanza tra "<<city[i].citta<<" e "<<city[j].citta<<": ";
                cin>>distanze[i][j];
            }while(distanze[i][j]<=0);

            distanze[j][i] = distanze[i][j];

            if(max<distanze[i][j]){
                max = distanze[i][j];
            }
        }
    }

    max++;
}


void stampa(int distanze[][DIM_MAX_STR],int *N){
    cout<<endl;
    for(int i=0;i<*N;i++){
        for(int j=0;j<*N;j++){
            cout<<distanze[i][j]<<" ";
        }
        cout<<endl;
    }
}

void cercaPercorsoMigliore(citta city[],const int distanze[][DIM_MAX_STR], const char *nomeCitta, const int N, int max){
    int indice = ricercaCitta(city,nomeCitta,N);
    int chilometri = 0, indiceTemp;
    int min;

   if(indice!=-1){
        cout<<"\nPERCORSO MIGLIORE:\n";
        cout<<city[indice].citta<<" -> ";

        for(int k=0;k<N-1;k++){
            min = max;
            for(int i=1;i<N;i++){
                for(int j=0;j<i;j++){
                    if(i==indice && !city[j].visitato){
                        if(min>distanze[i][j]){
                            min=distanze[i][j];
                            indiceTemp = j;
                        }
                    }

                    if(j==indice && !city[i].visitato){
                        if(min>distanze[i][j]){
                            min=distanze[i][j];
                            indiceTemp = i;
                        }
                    }
                }
            }

            cout<<city[indiceTemp].citta<<" -> ";

            chilometri+=min;
            city[indice].visitato=true;
            indice = indiceTemp;
        }

        indice = ricercaCitta(city,nomeCitta,N);
        chilometri+=distanze[indice][indiceTemp];

        cout<<city[indice].citta;
        cout<<"\nchilometri da percorre: "<<chilometri;

    } else {
        cout<<"\nCitta non esistente!";
    }
}

int ricercaCitta(citta city[],const char *nomeCitta ,const int N){ // oltre a dire se la citta esiste o no ma mi da anche gli indici del array distanze nella poszione in qui sta!
    int k;
    bool nonEsiste;

    for(int i=0;i<N;i++){
        if(strlen(city[i].citta) == strlen(nomeCitta)){
            if(nomeCitta[0] == city[i].citta[0]){
                k=1;
                nonEsiste=true;
                while(k<strlen(nomeCitta) && nonEsiste){
                    if(city[i].citta[k]!=nomeCitta[k]){
                        nonEsiste = false;
                    }
                    k++;
                }

                if(nonEsiste)
                    return i;
                    
            }
        }
    }

    return -1;
}
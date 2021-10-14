#include<iostream>
#include<string.h>

using namespace std;

#define DIM_STR_UTENTE 20+1 
#define DIM_STR_DOMINIO 20+1 
#define DIM_STR_OGGETTO 20+1 
#define MAX_EMAIL 40
#define MAX_PAROLA 20+1

typedef struct { 
    char utente [DIM_STR_UTENTE]; //es. paolo.pelizzoni 
    char dominio [DIM_STR_DOMINIO]; //es. fermimn.edu.it 
}indirizzo; 

typedef struct { 
    indirizzo from ; 
    indirizzo to; 
    char oggetto [DIM_STR_OGGETTO]; 
} email;

int menu();
int Insert(email vetMail[], int &lunghezzaMail);
void inserimentoMail(email &mail);
void stampaPerDominio(email vetMail[], int lunghezzaMail, char dominio[]);
void stampaMail(email mail);
void stampaPerParola(email vetMail[], int lunghezzaMail, char cercaParola[]);

int main(){
    email vetMail[MAX_EMAIL];
    int lunghezzaMail = 0, scelta;
    char dominio[DIM_STR_DOMINIO], cercaParola[MAX_PAROLA];

    do{
        scelta = menu();

        switch(scelta){
            case 1: 
                int ris;
                ris = Insert(vetMail,lunghezzaMail);

                if(ris){
                    cout<<"\nInserimento andato a buonfile!";
                } else {
                    cout<<"\nInserimento non riuscito!";
                }

                break;
            case 2: 
                cout<<"Inserire il dominio che vuole cercare: ";
                cin>>dominio;
                stampaPerDominio(vetMail,lunghezzaMail,dominio);
                break;
            case 3:
                cout<<"Inserire la parola da cercare: ";
                cin>>cercaParola;
                stampaPerParola(vetMail,lunghezzaMail,cercaParola);
                break;
        }

    }while(scelta!=0);


    return 0;
}

int menu(){
    int scelta;

    do{
        cout<<"\n\n1. Inserimento dati.";
        cout<<"\n2. Stampa delle mail dato il dominio.";
        cout<<"\n3. Stampa della mail dato una parola.";
        cout<<"\n0. Per uscire dal programma";
        cout<<"\n\nInserire una delle scelte elencate: \n> ";
        cin>>scelta;
    }while(scelta<0 || scelta>3);

    return scelta;
}

int Insert(email vetMail[], int &lunghezzaMail){
    if(lunghezzaMail<MAX_EMAIL){
        inserimentoMail(vetMail[lunghezzaMail]);
        lunghezzaMail++;
        return 1;
    } 

    return 0;
}

void inserimentoMail(email &mail){
    cout<<"\nInserimento della sua mail: \n\n";
    cout<<"Inserire il nome utente della mail: \n> ";
    cin>>mail.from.utente;
    cout<<"Inserire il domnio della mail: \n> ";
    cin>>mail.from.dominio;
    cout<<"\nInserimento della mail del destinatario: \n\n";
    cout<<"Inserire il nome utente della mail: \n> ";
    cin>>mail.to.utente;
    cout<<"Inserire il domnio della mail: \n> ";
    cin>>mail.to.dominio;
    cin.ignore(100, '\n');
    cout<<"\nInserire l'oggetto della mail: \n> ";
    cin.getline(mail.oggetto,DIM_STR_OGGETTO);
}

void stampaPerDominio(email vetMail[], int lunghezzaMail, char dominio[]){
    for(int i=0;i<lunghezzaMail;i++){
        if((strcmp(vetMail[i].from.dominio,dominio)==0) || (strcmp(vetMail[i].to.dominio,dominio)==0)){
            stampaMail(vetMail[i]);
        }
    }
}

void stampaMail(email mail){
    cout<<"\nMittente: "<<mail.from.utente<<"@"<<mail.from.dominio;
    cout<<"\nDestinatario: "<<mail.to.utente<<"@"<<mail.to.dominio;
    cout<<"\noggetto della mail: "<<mail.oggetto;
}

void stampaPerParola(email vetMail[], int lunghezzaMail, char cercaParola[]){
    int k, trovato, stop;
    for(int i=0;i<lunghezzaMail;i++){
        k=1;
        trovato = 1;
        stop = 1;
        for(int j=0;vetMail[i].oggetto[j] !='\0' && stop;j++){
            if(vetMail[i].oggetto[j] == cercaParola[0]){
                while(k<strlen(cercaParola)-1 && trovato){
                    if(vetMail[i].oggetto[j+k] != cercaParola[k]){
                        trovato = 0;
                        cout<<vetMail[i].oggetto[j+k];
                    } 
                    k++;
                }
                if(trovato){
                    stampaMail(vetMail[i]);
                    stop = 0;
                }
            }
        }
    }
}

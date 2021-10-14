#include<iostream>
#include<string.h>

#define MAX_STUD 33 
#define DIM_STR 25+1
#define MAX_TEST 80

using namespace std;

enum tipoSport{CALCIO, NUOTO, TENNIS, NESSUNO}; 

struct studente{ 
    char nome[DIM_STR]; 
    tipoSport sport; 
}; 

void insert (studente classe[], int &numStudenti);         //O, O
void stampa (const studente classe[], int numStudenti);   //I, I 


int main(){ 
    studente classe[MAX_STUD]; 
    int numStudenti; 
    
    insert(classe,numStudenti); 
    stampa(classe, numStudenti); 
    return 0; 
}

void insert (studente classe[], int &numStudenti){
    int i, test;
    char temp[MAX_TEST];
    do{ 
        cout<<"Quanti studenti si trovano nella classe: ";
        cin>>numStudenti;
    }while(numStudenti<=0 || numStudenti>MAX_STUD);

    for(i=0;i<numStudenti;i++){
        cout<<"\n\nAlunno: "<<i+1<<endl;
        cin.ignore(100, '\n');
        
        do{
            cout<<"Inserire il nome dell'alunno (<26): ";
            cin.getline(temp, MAX_TEST);
        }while(strlen(temp)>DIM_STR);
        strcpy(classe[i].nome, temp);

        do{
            cout<<"Che sport pratica tra questi CALCIO, NUOTO, TENNIS, NESSUNO (inserire il numero): \n> ";
            cin>>test;
        }while(test<=0 || test>4);
        test--;
        classe[i].sport= (tipoSport) test;    
    }
}

void stampa (const studente classe[], int numStudenti){
    int i;
    
    for(i=0;i<numStudenti;i++){
        cout<<"\n\n";
        cout<<"Studente: "<<i+1<<endl;
        cout<<"Nome studente: "<<classe[i].nome<<endl;
        if(classe[i].sport==CALCIO){
            cout<<"sport: Calcio";    
        } else if(classe[i].sport==NUOTO){
            cout<<"sport: Nuoto";
        } else if(classe[i].sport==TENNIS){
            cout<<"sport: Tennis";
        } else if (classe[i].sport==NESSUNO){
            cout<<"sport: Nessuno";
        }
    }
}

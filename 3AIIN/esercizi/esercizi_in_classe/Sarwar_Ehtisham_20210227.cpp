#include<iostream>

const int M = 5; 
const int P = 3; 
const int MAX_PESO_MENSOLA=30; 

using namespace std;

void inizializza(int espositore[][P]);
int pesoMensola(const int espositore[][P],int m);
int postoLibero(const int espositore[][P],int m);
int inserisci(int espositore[][P],int w);
void liberaPosto(int espositore[][P],int m,int p);
int mensolaScarica(int espositore[][P]);
void stampa(const int espositore[][P]);


int main(){ 
	int espositore[M][P];         
	int scelta; 
	inizializza(espositore);        
	
	do{         
		cout<<"Gestione espositore"<<endl<<endl;         
		cout<<"1 Peso mensola"<<endl;         
		cout<<"2 Posto libero su una mensola"<<endl;         
		cout<<"3 Inserimento oggetto"<<endl;         
		cout<<"4 Libera posto"<<endl;         
		cout<<"5 Mensola piu' scarica"<<endl;         
		cout<<"6 Visualizza espositore"<<endl;         
		cout<<"0 Fine lavoro"<<endl;         
		cout<<"Digita una scelta"<<endl;         
		cin>>scelta;         
		switch(scelta){ 
			case 1:            
				int m;  
				do{       
					cout<<"Inserisci numero mensola"<<endl;           
					cin>>m;      //controllo input           
				}while(m<0 || m>M);
				cout<<"Peso mensola:"<<pesoMensola(espositore,m)<<endl;           
				cout<<endl;           
				break; 
			case 2:   
				do{               
					cout<<"Inserisci numero mensola"<<endl;                  
					cin>>m;      //controllo input                  
				}while(m<0 || m>M);
				cout<<"Posto libero:"<<postoLibero(espositore,m)<<endl;                  
				cout<<endl;                  
				break; 
			case 3:                   
				int w; 
				do{               
					cout<<"Inserisci peso oggetto\n";                  
					cin>>w;      //controllo input                  
				}while(w<1);
				if(inserisci(espositore,w)) 
					cout<<"Oggetto inserito\n";                  
				else 
					cout<<"Oggetto non inserito\n";                   				
				cout<<endl;                    
				break; 
			case 4:                   
				int p;  
				do{              
					cout<<"Inserisci numero mensola\n";                  
					cin>>m;      //controllo input                  
				}while(m<0 || m>M);
				
				do{
					cout<<"Inserisci numero posto\n";                  
					cin>>p; //controllo input
				}while(p<0 || m>P);
				               
				liberaPosto(espositore,m,p);                  
				cout<<endl;                  
				break; 
			case 5:  
				cout<<"La mensola piu' scarica e': "<<mensolaScarica(espositore)<<endl;                  
				cout<<endl; 
				break;         
			case 6:                   
				stampa(espositore);                  
				cout<<endl; 
				break;      
		}    
	}while(scelta!=0);    
	
	return 0; 
}

void inizializza(int espositore[][P]){
	int i, j;
	for(i=0;i<M;i++){
		for(j=0;j<P;j++){
			espositore[i][j]=0;
		}
	}
}

int pesoMensola(const int espositore[][P], int m){
	int pesoTotale=0, i;
	for(i=0;i<P;i++){
		pesoTotale += espositore[m][i];
	}
	return pesoTotale;
}

int postoLibero(const int espositore[][P],int m){
	int i;
	for(i=0;i<P;i++){
		if(!espositore[m][i]){
			return i;
		}
	}
	return -1;
}

void stampa(const int espositore[][P]){
	int i, j;
	cout<<"\n\n";
	for(i=0;i<M;i++){
		for(j=0;j<P;j++){
			cout<<espositore[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

int inserisci(int espositore[][P],int w){
	int i;
	for(i=0;i<M;i++){
		if(postoLibero(espositore,i)!=-1 && pesoMensola(espositore,i)+w<=MAX_PESO_MENSOLA){
			espositore[i][postoLibero(espositore,i)]=w;
			return 1;
		}
	}
	return 0;
}

void liberaPosto(int espositore[][P],int m,int p){
	espositore[m][p]=0;
}

int mensolaScarica(int espositore[][P]){
	int i, piuScarica=0, ris, mensola;
	
	for(i=0;i<M;i++){
		ris = pesoMensola(espositore,i);
		if(ris<piuScarica){
			piuScarica=ris;
			mensola = i;
		}
	}
	return mensola;
}

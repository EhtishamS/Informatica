#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;

const int MAX_STR = 100;
const int MAX_ANNUNCI = 200;
const int MAX_NOMEFILE = 50;

enum tipoCategoria {HOBBY, AUTO, CASA, SPORT};

struct tipoData {
    int giorno;
    int mese;
    int anno;
};

struct tipoAnnuncio {
    tipoCategoria categoria;
    tipoData dataPubblicazione;
    float prezzo;
    char descrizione[MAX_STR];
};

struct archivioAnnunci {
    tipoAnnuncio annunci[MAX_ANNUNCI];
    int numAnnunci;
};

int menu();
int inserireAnnunci(archivioAnnunci *a);
void annuncio(tipoAnnuncio &ad);
float prezzoMedio(const archivioAnnunci* a, tipoCategoria c);
bool piuNumerosa(const archivioAnnunci* a, tipoCategoria* puntCategoria);
void stampa(const archivioAnnunci* a);
int seleziona(const archivioAnnunci* a, const char *stringaCercata, tipoAnnuncio *v);
int stresiste(const char *str1,const char *str2);
void ordinamentoCrescente(archivioAnnunci *a);
int data(tipoData data1, tipoData data2);
bool salva(const archivioAnnunci* a, char nomeFile[]);

int main(){
    archivioAnnunci a;
    tipoCategoria c;
    tipoAnnuncio v[MAX_ANNUNCI];
    a.numAnnunci = 0;

    int scelta;
    int risultato;
    int numCategoria;
    float mediaCategoria;
    bool esiste;
    char stringaCercata[MAX_STR];
    
    int numeroAnnunci=0;
    
    char nomeFile[MAX_NOMEFILE];
    
    cout<<"Inserire il nome del file in qui desidera salvare il contenuto:\n>";
    cin>>nomeFile;

    do{
        scelta = menu();

        switch(scelta){
            case 1:
                risultato = inserireAnnunci(&a);

                if(risultato)
                    cout<<"\nInserimento completato!\n";
                else 
                    cout<<"\nErrore, Inserimento non riuscito!\n";
                break;
            case 2:
                do{
                    cout<<"\nInserire il tipo di categoria: ";
                    cout<<"\n1. Hobby.";
                    cout<<"\n2. Auto.";
                    cout<<"\n3. Casa.";
                    cout<<"\n4. Sport.";
                    cout<<"\nscegliere uno di questi:\n>";
                    cin>>numCategoria;
                }while(numCategoria<1 || numCategoria>4);
                numCategoria-=1;
                c = (tipoCategoria) numCategoria;

                cout<<"\nIl prezzo medio della categoria selezionata e: "<<prezzoMedio(&a,c)<<endl;;
                break;
            case 3:
                esiste = piuNumerosa(&a,&c);

                if(esiste){
                    cout<<"\nla categoria piu' numerosa e la: ";
                    switch (c){
                        case 0:
                            cout<<"Hobby\n";
                            break;
                        case 1:
                            cout<<"Auto\n";
                            break;
                        case 2:
                            cout<<"Casa\n";
                            break;
                        case 3:
                            cout<<"Sport\n";
                            break;
                        
                    }
                } else {
                    cout<<"\nMomentaneamente non ci sono annunci!\n";
                }
                break;
            case 4:
                stampa(&a);
                break;
            case 5:
                cout<<"\nInserire la stringa da cercare: ";
                cin>>stringaCercata;
				
				cout<<"\nIl numero di annunci simili alla ricerca sono "<<seleziona(&a,stringaCercata,v)<<endl;
                break;
        	case 6:
        		ordinamentoCrescente(&a);
				esiste = salva(&a,nomeFile);
				
				if(esiste)
					cout<<"\nSalvataggio completato!\n";
				else
					cout<<"\nSalvataggio non riuscito!\n";
				break;    
        }
    }while(scelta!=0);

    cout<<"\nProgramma terminato!";
    return 0;
}

int menu(){
    int scelta;

    
    cout<<"\nMENU";
    cout<<"\n1. Inserimento annuncio.";
    cout<<"\n2. Trovare il prezzo medio di una categoria.";
    cout<<"\n3. Cercare la categoria piu numerosa.";
    cout<<"\n4. Stampare tutti gli annunci.";
    cout<<"\n5. selezionare annunci.";
    cout<<"\n6. salvare gli annunci.";
    cout<<"\n0. Fine lavoro.";
    cout<<"\nInserire la scelta:\n>";
    cin>>scelta;
    
    return scelta;
}

int inserireAnnunci(archivioAnnunci *a){
    if(a->numAnnunci<MAX_ANNUNCI){
        annuncio(a->annunci[a->numAnnunci]);
        a->numAnnunci++;
        return 1;
    }

    return 0;
}

void annuncio(tipoAnnuncio &ad){
    int numCategoria;

    cout<<"\nINSERIMENTO DATA ANNUNCIO: \n";
    
    cout<<"Inserire il giorno:\n>";
    cin>>ad.dataPubblicazione.giorno;

    cout<<"\nInserire il mese:\n>";
    cin>>ad.dataPubblicazione.mese;

    cout<<"\nInserire l'anno:\n>";
    cin>>ad.dataPubblicazione.anno;

    do{
        cout<<"\nInserire la categoria dell'annuncio tra le seguenti:";
        cout<<"\n1. Hobby.";
        cout<<"\n2. Auto.";
        cout<<"\n3. Casa.";
        cout<<"\n4. Sport.";
        cout<<"\nscegliere uno di questi:\n>";
        cin>>numCategoria;
    }while(numCategoria<1 || numCategoria>4);
    
    ad.categoria = (tipoCategoria) (numCategoria-1);

    cout<<"\nInserire il prezzo per l'annuncio:\n>";
    cin>>ad.prezzo;

    cin.ignore(100, '\n');
    cout<<"\nInserire una descrizione per l'annuncio:\n>";
    cin.getline(ad.descrizione, MAX_STR);
}


float prezzoMedio(const archivioAnnunci* a, tipoCategoria c){
    float sommaPrezzi=0;
    int cont = 0;

    for(int i=0;i<a->numAnnunci;i++){
        if(c==a->annunci[i].categoria){
            sommaPrezzi+=a->annunci[i].prezzo;
            cont++;
        }
    }

    return sommaPrezzi/cont;
}


bool piuNumerosa(const archivioAnnunci* a, tipoCategoria* puntCategoria){
    int contCategoria = 0, max=0;
    
    for(int i=0;i<a->numAnnunci;i++){
        for(int j=i;j<a->numAnnunci;j++){
            if(a->annunci[i].categoria == a->annunci[j].categoria){
                contCategoria++;
            }
        }

        if(contCategoria>max){
            max=contCategoria;
            *puntCategoria = a->annunci[i].categoria;
        }
    }

    if(max>0){
        return true;
    }
    return false;
}

void stampa(const archivioAnnunci* a){
    float media;
    for(int i=0;i<a->numAnnunci;i++){
        media = prezzoMedio(a,a->annunci[i].categoria);
        if(a->annunci[i].prezzo>media)
            cout<<"+ "<<a->annunci[i].prezzo<<" "<<a->annunci[i].descrizione<<endl;
        else if(a->annunci[i].prezzo<media)
            cout<<"- "<<a->annunci[i].prezzo<<" "<<a->annunci[i].descrizione<<endl;
        else
            cout<<"= "<<a->annunci[i].prezzo<<" "<<a->annunci[i].descrizione<<endl;
    }
}

int stresiste(const char *str1,const char *str2){
	int k, nonEsiste;
	
	for(int i=0;str1[i];i++){
		if(str2[0] == str1[i]){
			k = 1;	
			nonEsiste = 1;
			while(k<strlen(str2) && nonEsiste){
				if(str1[k+i] != str2[k]){
					nonEsiste = 0;
				}
				k++;
			}
			
			if(nonEsiste){
				return 1;
			}
		}
	}
	
	return 0;
}

int seleziona(const archivioAnnunci* a, const char *stringaCercata, tipoAnnuncio *v){
	int contV=0;
	
	for(int i=0;i<a->numAnnunci;i++){
		if(stresiste(a->annunci[i].descrizione,stringaCercata)){
			v[contV].categoria = a->annunci[i].categoria;
			v[contV].dataPubblicazione = a->annunci[i].dataPubblicazione;
			strcpy(v[contV].descrizione,a->annunci[i].descrizione);
			v[contV].prezzo = a->annunci[i].prezzo;
			
			contV++;
		}
	}	
	
	return contV;
	
}

void ordinamentoCrescente(archivioAnnunci *a){
	int min;

	for(int i=0;i<a->numAnnunci-1;i++){
		min = i;
		for(int j=i+1;j<a->numAnnunci;j++){
			if(data(a->annunci[j].dataPubblicazione,a->annunci[min].dataPubblicazione)==2){
				min = j;
			}
		}
		tipoAnnuncio temp = a->annunci[min];
		a->annunci[min] = a->annunci[i];
		a->annunci[i] = temp;
	}
}

int data(tipoData data1, tipoData data2){
	if(data1.anno == data2.anno && data1.mese == data2.mese && data1.giorno == data2.giorno){
		return 0;
	} else if(data1.anno>data2.anno){
		return 1;
	} else if(data1.anno == data2.anno && data1.mese>data2.mese){
		return 1;
	} else if(data1.anno == data2.anno && data1.mese == data2.mese && data1.giorno>data2.giorno){
		return 1;
	} 
	
	
	return 2;
}

bool salva(const archivioAnnunci* a, char nomeFile[]){
	fstream outFile;
	
	strcat(nomeFile,".txt");
	
	outFile.open(nomeFile,ios::out);
	
	if(!outFile){
		cout<<"\nImpossibile aprire il file!\n";
		return false;
	}
	
	for(int i=0;i<a->numAnnunci;i++){
		outFile<<a->annunci[i].dataPubblicazione.giorno;
		outFile<<"/";
		outFile<<a->annunci[i].dataPubblicazione.mese;
		outFile<<"/";
		outFile<<a->annunci[i].dataPubblicazione.anno;
		outFile<<" ";
		
		switch(a->annunci[i].categoria){
			case 0:
				outFile<<"hobby ";
				break;
			case 1:
				outFile<<"auto ";
				break;
			case 2:
				outFile<<"casa ";
				break;
			case 3:
				outFile<<"sport ";
				break;
		}
		
		outFile<<a->annunci[i].prezzo;
		outFile<<" ";
		
		outFile<<a->annunci[i].descrizione<<endl;
	}
	
	outFile.close();
	return true;
}

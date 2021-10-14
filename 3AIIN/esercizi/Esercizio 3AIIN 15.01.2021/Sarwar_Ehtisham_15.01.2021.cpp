 /*
    Name: calcolatrice;
    Author: Sarwar Ehtisham;
    Date: 15/01/2021;
    Description: fare un programma come descritto nel PDF del professore pellizoni. 
*/
#include<iostream>
#define CAR '*'

using namespace std;

int main (){
    int mese[]= { 0, 4, 3, 5, 1, 0, 1};
	int numGiorni=sizeof(mese)/sizeof(mese[0]); 
	int scelta, i, j, cont_giorni_pioggia, giorni, percentuale_pioggia, max, giorno_max, min, giorno_min, flag;
	int periodo_pioggia=0, temp_iniz, temp_fine, max_periodo=0, giorno_iniz, giorno_fine;
	double media_pioggia, somma;
	
	do {     
		cout<<"\n\nPROGRAMMA METEO \n\n";     
		cout<<"1  Stampa mese \n";     
		cout<<"2  Stampa giorni pioggia \n";     
		cout<<"3  Conta giorni pioggia \n";     
		cout<<"4  Media giorni pioggia \n";     
		cout<<"5  Percentuale \n";     
		cout<<"6  Min Max \n";     
		cout<<"7  Periodo piu' lungo di pioggia \n";     
		cout<<"8  Ricerca \n";     
		cout<<"9  Stampa istogramma \n";     
		cout<<"0  Fine lavoro \n";     
		cout<<"\nSCELTA: ";     
		cin>>scelta;     
		
		switch (scelta) {    
			case 1: 
					cout<<"\n"<<"GG "<<"mm"<<endl;
					for(i=0;i<numGiorni;i++){
						cout<<i+1<<"  ";
						cout<<mese[i]<<endl;
					}         
					break;    
			case 2:     
					cout<<"\n"<<"GG pioggia "<<"mm"<<endl;
					for(i=0;i<numGiorni;i++){
						if(mese[i]!=0){
							cout<<i+1<<"          ";
							cout<<mese[i]<<endl;
						}
					}     
					break;    
			case 3:    
					cont_giorni_pioggia=0;
					cout<<"\n"<<"GG pioggia"<<endl;
					for(i=0;i<numGiorni;i++){
						if(mese[i] != 0){
							cont_giorni_pioggia++;
						}
					}
					cout<<cont_giorni_pioggia;
					break;    
			case 4: 
					cont_giorni_pioggia=0;      
					cout<<"\n"<<"GG media pioggia"<<endl;
					for(i=0;i<numGiorni;i++){
						if(mese[i]!=0){
							somma+=mese[i];
							cont_giorni_pioggia++;
						}
					}    
					media_pioggia = somma/cont_giorni_pioggia;
					cout<<media_pioggia<<" mm";
					break;            
			case 5:   
					giorni=0;
					cout<<"\n"<<"Percentuale giorni di piogga"<<endl;
					for(i=0;i<numGiorni;i++){
						if(mese[i]!=0){
							giorni++;
						}
					}
					percentuale_pioggia = (giorni*100)/numGiorni;
					cout<<percentuale_pioggia<<"%";
					break;    
			case 6: 
					max=mese[0];
					giorno_max=0;
					giorno_min=0;
					flag=0;
					for(i=0;i<numGiorni&&flag==0;i++){
						if(mese[i]!=0){
							min = mese[i];
							flag=1;
						}
					}
					for(i=0;i<numGiorni;i++){
						if(mese[i]>max && mese[i]!=0){
							max=mese[i];
							giorno_max=i+1;
						} 
						
						if(min>mese[i] && mese[i]!=0){
							min=mese[i];
							giorno_min=i+1;
						}
					}
					cout<<"Giorno max: "<<giorno_max<<" mm max: "<<max<<"\n"<<"Giorno min: "<<giorno_min<<" mm min: "<<min;
					break;    
			case 7:     
					flag=0;
					max_periodo=0;
					for(i=0;i<numGiorni;i++){
						if(mese[i]!=0){
							if(flag==0){
								temp_iniz=i;
								flag=1;
							}
							
						} else {
							periodo_pioggia=-1;
							flag=0;
						}
						periodo_pioggia++;
						
						if(periodo_pioggia>max_periodo){
							max_periodo=periodo_pioggia;
							giorno_iniz=temp_iniz+1;
							giorno_fine=temp_iniz+periodo_pioggia;
						}
					}
					cout<<"Il massimo periodo di pioggia e': "<<max_periodo<<endl;
					cout<<"Giorno d'inizio: "<<giorno_iniz<<endl;
					cout<<"Giorno di fine: "<<giorno_fine;
					break;  
					
					break;  
			case 8: 
					
					cout<<"\n";
					do{
						cout<<"Di quale giorno vuole sapere i dati: ";
						cin>>giorni;
					}while(giorni>numGiorni);
					giorni--;
					cout<<"Il "<<giorni+1<<" e' piovuto "<<mese[giorni]<<" mm di pioggia!";
					break;    
			case 9:           
					cout<<"GG "<<"Pioggia"<<" Istogramma"<<endl;
					for(i=0;i<numGiorni;i++){
						cout<<i+1<<"  "<<mese[i]<<" 	   ";
						for(j=0;j<mese[i];j++){
							cout<<CAR;
						}
						cout<<"\n";
					}  
					break;       
		}    
	}while(scelta!=0);    

	return 0;
}

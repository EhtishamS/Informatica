/*
    Author: Ehtisham Sarwar
    Date: 20/03/2021 19:40:45
    Description: vedere il file "Esercizio 3AIIN 19.03.2021";
*/

#include<iostream>

#define MAX_SEGMENTI 6 
#define MAX 5

using namespace std;

typedef struct{
    double x;
    double y;
}punto;

struct segmento{
    punto p1;
    punto p2;
};

void insertSegmenti(struct segmento v[MAX_SEGMENTI], int &numSegmenti); // direzionalità di output
void stampaSegmenti(const struct segmento v[MAX_SEGMENTI], int numSegmenti); // direzionalità di input
int maxSegmenti(const struct segmento v[], int numSegmenti);
int quadranteSegmento(const struct segmento v[],int  posiz);
int quadrantePunto(int p1, int p2);

int main(){
    struct segmento v[MAX_SEGMENTI];
    int numSegmenti, quadrante;

    insertSegmenti(v,numSegmenti);
    stampaSegmenti(v,numSegmenti);
    quadrante = maxSegmenti(v, numSegmenti);
     
    cout<<"\nAl quadrante a cui appartengono maggior parte dei segmenti e il seguente: "<<quadrante;
    return 0;
}

void insertSegmenti(struct segmento v[], int &numSegmenti){
    int i;

    do{
        cout<<"Quanti segmenti vuole inserire: ";
        cin>>numSegmenti;
    }while(numSegmenti<=0 || numSegmenti>MAX_SEGMENTI);

    for(i=0;i<numSegmenti;i++){
        cout<<"segmento: "<<i+1<<endl;
        cout<<"Cooridinate primo punto: "<<endl;
        cin>>v[i].p1.x>>v[i].p1.y;
        cout<<"Cooridinate secondo punto: "<<endl;
        cin>>v[i].p2.x>>v[i].p2.y;
    }
}

void stampaSegmenti(const struct segmento v[MAX_SEGMENTI], int numSegmenti){
    int i;
    for(i=0;i<numSegmenti;i++){
        cout<<"\nSegmento: "<<i+1;
        cout<<"\n("<<v[i].p1.x<<", "<<v[i].p1.y<<")";
        cout<<"\n("<<v[i].p2.x<<", "<<v[i].p2.y<<")";
    }
}

int maxSegmenti(const struct segmento v[], int numSegmenti){
    int i, conta_seg[MAX]={0,0,0,0,0}, max=0, quadrante;

    for(i=0;i<numSegmenti;i++){
        conta_seg[quadranteSegmento(v, i)]++;
    }

    quadrante = 1;
    max = conta_seg[1];

    for(i=2;i<MAX;i++){
        if(max<conta_seg[i]){
            max=conta_seg[i];
            quadrante = i;
        }
    }
    return quadrante;
}

int quadranteSegmento(const struct &segmento v[],int  posiz){
    int quadrante1, quadrante2;

    quadrante1 = quadrantePunto(v[posiz].p1.x, v[posiz].p1.y);
    quadrante2 = quadrantePunto(v[posiz].p2.x, v[posiz].p2.y);

    if(quadrante1 == quadrante2){
        return quadrante1;
    } else {
        return 0;
    }
}

int quadrantePunto(int x, int y){

    if(x>0){
        if(y>0){
            return 1;
        } else {
            return 4;
        }
    } else {
        if(y>0){
            return 2;
        } else{
            return 3;
        }
    }
    
}
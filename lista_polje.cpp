#include<iostream>
#include<cstring>
using namespace std;
typedef int el;

struct lista{
char mat_broj[15];
char ime_prezime[40];
int godina;       
};

struct cursor{
       lista polje[1000];
       int en; 
}a;

int FirstL(lista *Lista){
return 0;    
}

int LocateL(char b[], el pozicija, lista *Lista){
    if(pozicija>1){
    for(int i=0; i<a.en; i++){
            if(strcmp(a.polje[i-1].mat_broj,b)==0)
            return 0;
            }               
    }
    else 
    return 1;
}

int InsertL(char br[], int god, char ime_pre[], el pozicija, lista *Lista){
if((pozicija>=0) && (pozicija<1000)){
                 strcpy(a.polje[pozicija].mat_broj, br);
                 strcpy(a.polje[pozicija].ime_prezime, ime_pre);
                 a.polje[pozicija].godina=god;
                 a.en++;
                 return 1;
                 }
else{
     if(pozicija>=1000)
     cout<<"Polje je puno!"<<endl;
     return 0;
                 
     }
}

int RetriveL(el pozicija, lista *Lista){
    lista pomocna;
    bool zamjena;
    zamjena=true;
    for(int i=pozicija-1; i>0; i--){
            zamjena=false;
            for(int j=0; j<i; j++){
                    if(strcmp(a.polje[j].mat_broj,a.polje[j+1].mat_broj)==1){
                    memcpy(&pomocna,&a.polje[j], sizeof(lista));
                    a.polje[j]=a.polje[j+1];
                    a.polje[j+1]=pomocna;
                    zamjena=true;                                              
                    }}
            }
    for(int i=0; i<pozicija; i++)
    cout<<a.polje[i].mat_broj<<"\t\t"<<a.polje[i].ime_prezime<<"\t\t"<<a.polje[i].godina<<endl;
}

int RetriveL_MladjiOd18(el pozicija, lista *Lista){
    lista pomocna;
    bool zamjena;
    zamjena=true;
    for(int i=pozicija-1; i>0; i--){
            zamjena=false;
            for(int j=0; j<i; j++){
                    if(strcmp(a.polje[j].mat_broj,a.polje[j+1].mat_broj)==1){
                    memcpy(&pomocna,&a.polje[j], sizeof(lista));
                    a.polje[j]=a.polje[j+1];
                    a.polje[j+1]=pomocna;
                    zamjena=true;                                              
                    }}
            }
    for(int i=0; i<pozicija; i++){
    if(a.polje[i].godina<18){
    cout<<a.polje[i].mat_broj<<"\t\t"<<a.polje[i].ime_prezime<<"\t\t"<<a.polje[i].godina<<endl;
}
}
}

int DeleteL(el pozicija, char maticni[], lista *Lista){
if((pozicija<1000) && (pozicija>=0)){
   for(int i=0; i<pozicija; i++){
           if(strcmp(a.polje[i].mat_broj, maticni)==0){
           while(i<=pozicija){
           memcpy(&a.polje[i],&a.polje[i+1], sizeof(lista));
           i++;}
           a.en--;                        }
           }
           
           cout<<"Element je izbrisan."<<endl;
           for(int i=0; i<a.en; i++)
           cout<<a.polje[i].mat_broj<<"\t\t"<<a.polje[i].ime_prezime<<"\t\t"<<a.polje[i].godina<<endl;
           return 0;
           }
   else{
        cout<<"Elemnt ne postoji u listi."<<endl;
        return 1;
        }
    
}

int EndL(lista *Lista){
    return (a.en);
    
}


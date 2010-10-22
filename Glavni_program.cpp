#include<iostream>
#include "lista_polje.h"
using namespace std;
int pozicija=0;

void unos(lista *Lista){
char ponovo;
do{
char broj[15];
cout<<"Unesi mat_br: ";
cin>>broj;
if(LocateL(broj,pozicija,Lista)==0){
cout<<"Taj pacijent vec postoji."<<endl;
break;
}
char ime_prezime[40];
cout<<"Ime i prezime: ";
cin.ignore();
cin.getline(ime_prezime, 40);
int godina;
cout<<"Broj godina: ";
cin>>godina;
InsertL(broj, godina, ime_prezime, pozicija, Lista);
pozicija++;
cout<<"Ponovo unijeti? (d/n): ";
cin>>ponovo;
}while(ponovo=='d');
     
}

void ispis(lista *Lista){
     cout<<"Sortirani ispis po maticnom broju."<<endl;
     cout<<"Mat_br\t\tIme_prezime\t\tBroj_godina"<<endl;
     FirstL(Lista);
     RetriveL(pozicija, Lista);
}

void ispis_18(lista *Lista){
     cout<<"Osobe mladje od 18."<<endl;
     cout<<"Mat_br\t\tIme_prezime\t\tBroj_godina"<<endl;
     RetriveL_MladjiOd18(pozicija, Lista);
}

void brisi(lista *Lista){
     cout<<"Mat_br pacijenta kojeg zelite brisati: ";
     char mat_broj[15];
     cin>>mat_broj;
     DeleteL(pozicija,mat_broj,Lista);
}

int main(){
int izbor;
lista *Lista2= new lista;
do{
cout<<"1. Unos."<<endl;
cout<<"2. Ispis-sortirano po maticnom br."<<endl;
cout<<"3. Osobe mladje od 18."<<endl;
cout<<"4. Brisanje pacijenata."<<endl;
cout<<"9. Izlaz."<<endl;
cin>>izbor;
switch(izbor){
case 1: unos(Lista2);break;
case 2: ispis(Lista2);break;
case 3: ispis_18(Lista2);break;
case 4: brisi(Lista2);break;
case 9: break;
default: cout<<"Pogresan broj."<<endl;              
}      
}while(izbor!=9);
system("pause");
return 0;    

}

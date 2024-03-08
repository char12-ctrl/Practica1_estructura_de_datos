#include<iostream>
#include<stdexcept>
#include"Estudiant.h"
#include"Professor.h"

using namespace std;


void afegir_persona(int &i, int &j);
void resum_persones(int i, int j);

int main(void){
    
    int opcio,i,j;
    //podriem fer servir un vector però fem servir un array de strings
    string arr_options[] = {"Sortir", "Afegir persona", "Resum persones"};
    i=0;
    j=0;
    //fem servir les variables i,j per ser els contadors dels estudiants i professors respectivament
    do{
      cout << "Hola, que vols fer? \n1. "<<arr_options[0]<<"\n2. "<<arr_options[1]<<"\n3. "<<arr_options[2]<< "\n";
      cin >> opcio;
      //Fem un switch
      switch(opcio){
        case 1:
         cout <<"Fins a la propera"; 
         return 0;
        case 2:
         //Cridem a la funció afegir persona
         afegir_persona(i,j);
         break;
        case 3:
         //Cridem a la funció resum persones 
         resum_persones(i,j);
        }

    
    }while(opcio!=1);
    return 0;
    
}
void afegir_persona(int &i,int &j){
    string nom;
    char tipus;
    int naixement, n_assignatures;
    //fem try i catch ja que el constructor d'estudiant i professor pot llançar un error si el naixement és incorrecte
    try{
        cout << "Prem 'E' per crear un estudiant o 'P' per crear un professor\n";
        cin >> tipus;
        //cas estudiant
        if(tipus=='E' || tipus=='e'){
            i=i+1;
            cout << "Estudiant: "<< i <<"\n";
            cout << "Nom? ";
            cin >>nom;
            cout <<"Any de naixement? ";
            cin >> naixement;
            cout <<"Assignatures? ";
            cin >> n_assignatures;
            Estudiant alumne(nom, naixement, n_assignatures);
            //cridem al metode print de la clase
            alumne.print();
        }
        //cas professor
        else if(tipus=='P' || tipus=='p'){
            j=j+1;
            cout << "Professor: "<< j <<"\n";
            cout << "Nom? ";
            cin >>nom;
            cout <<"Any de naixement? ";
            cin >> naixement;
            Professor profe(nom,naixement);
            //cridem al metode print de la classe professor
            profe.print();
        }
        return;
    }
    //cas d'errada
    catch(const std::invalid_argument &ex){
        cout<<"Any de naixement incorrecte\n\n";
        //corretgim el nombre de professors i alumnes creats
        if(tipus=='E' || tipus=='e') j=j-1;
        else if(tipus=='P' || tipus=='p') i=i-1;
        return;
    }
}
void resum_persones(int i, int j){
        cout <<"Estudiants creats: "<< i <<", professors creats: " << j << "\n";
        return;
}

#include<iostream>
#include<stdexcept>
#include"Estudiant.h"

using namespace std;


void informar_estudiant(int &i);

int main(void){
    
    int opcio,i;
    //fem servir un array de strings però podriem utilitzar un vector com a l'exercici 2
    string arr_options[] = {"Sortir", "Informar estudiant"};
    i=0;
    do{
      cout << "Hola, que vols fer? \n1. "<<arr_options[0]<<"\n2. "<<arr_options[1]<<"\n";
      cin >> opcio;
      //Fem un switch
      switch(opcio){
        case 1:
         cout <<"Fins a la propera"; 
         return 0;
        case 2:
         //Cridem a la funció informar estudiant
         informar_estudiant(i);
         break;
        
        }

    
    }while(opcio!=1);
    return 0;
    
}
void informar_estudiant(int &i){
    string nom;
    int naixement, n_assignatures;
    //utilitzem un try i un catch per veure el constructor de la classe estudiant llança errors
    try{
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
        return;
    }
    catch(const std::invalid_argument &ex){
        //Corretgim el nombre d'estudiants i fem salta l'error.
        i=i-1;
        cout<<"Any de naixement incorrecte\n\n";
        return;
    }
}

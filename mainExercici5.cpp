#include<iostream>
#include<string>
#include<stdexcept>
#include<fstream>
#include"Estudiante.h"
#include"Professor.h"

using namespace std;


void afegir_persona(int &i, int &j);
void resum_persones(int i, int j);
void llegir_fitxer(int &i, int &j);

int main(void){
    
    int opcio,i,j,naixement,n_assignatures;
    char tipus;
    string nom;
    string arr_options[] = {"Sortir", "Afegir persona", "Llegir fitxer","Resum persones"};
    i=0;
    j=0;
    
    do{
      cout << "Hola, que vols fer? \n1. "<<arr_options[0]<<"\n2. "<<arr_options[1]<<"\n3. "<<arr_options[2]<< "\n4. "<<arr_options[3]<<"\n";
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
        //Cridem a la funció Llegir fitxer
         llegir_fitxer(i,j);
         break; 
        case 4:
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
    //el mateix try i catch de l'exercici 4
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
                //cridem al metode print de la classe,li passem el parametre 1 perquè el print si ha rebut les dades desde el fitxer es diferent al d'afegir alumne
                alumne.print(1);
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
                //cridem al metode print de la classe professor,li passem el parametre 1 pel mateix raonament
                profe.print(1);
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

void llegir_fitxer(int &i, int &j){
    string fitxer,data1;
    char tipus;
    int data2,data3;
    cout << "Ruta arxiu:\n";
    cin.ignore();
    getline(cin,fitxer);
    cout << "Processant " << fitxer <<"...\n";
    ifstream Elmeufitxer(fitxer);
    //La funcio is_open hem retorna true si el fitxer s'ha obert correctament i sino hem retorna false 
    if(Elmeufitxer.is_open()){
        //la funcio .eof() la feig servir per veure si hi ha contingut al fitxer
        while(!Elmeufitxer.eof()){
            try{
                //Escullo el cas
                Elmeufitxer>>tipus;
                //cas estudiant
                if(tipus=='E' || tipus=='e'){
                    //Faig una lectura de les dades del fitxer
                    Elmeufitxer>>data1;
                    Elmeufitxer>>data2;
                    Elmeufitxer>>data3;
                    i=i+1;
                    Estudiant alumne(data1, data2, data3);
                    //cridem al metode print de la clase,li passem el parametre 2 perquè el print si ha rebut les dades desde el fitxer es diferent al d'afegir alumne
                    alumne.print(2);
                }
                //cas professor
                else if(tipus=='P' || tipus=='p'){
                    j=j+1;
                    //Faig la lectura de dades del fitxer
                    Elmeufitxer>>data1;
                    Elmeufitxer>>data2;
                    Professor profe(data1,data2);
                    //cridem al metode print de la classe professor,li passem el parametre 2 pel mateix raonament
                    profe.print(2);
                }

            }

            //cas d'errada
            catch(const std::invalid_argument &ex){
                cout<<"Any de naixement incorrecte\n";
                //corretgim el nombre de professors i alumnes creats
                if(tipus=='E' || tipus=='e') j=j-1;
                else if(tipus=='P' || tipus=='p') i=i-1;
                cout << "Error en el fitxer en l'any de naixement";
                Elmeufitxer.close();
                return;
            }
        }
    }
    else{
        cout<<"No s'ha pogut obrir el fitxer\n";
    }    
    Elmeufitxer.close();
    return;
}

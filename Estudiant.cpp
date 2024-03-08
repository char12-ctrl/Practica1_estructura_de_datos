#include<iostream>
#include<stdexcept>
#include"Estudiant.h"

using namespace std;




Estudiant::Estudiant(string nom, int naixement, int assig){
            //fem servir el this per refernciar l'atribut de la classe
            this->nom=nom;
            this->naixement=naixement;
            //podriem fer servir el this però com el parametre l'he dit diferent no fa falta
            n_assignatures=assig;
            if(naixement<=0 || naixement > 2024){
                throw std::invalid_argument("received wrong value");
            }
            }
    //calculem edat
int Estudiant::getedat(){
        return 2024-naixement;
    }
    //escribim per pantalla
void Estudiant::print(){
        cout << "Estudiant(Nom ==> "<< nom <<", Naixement ==> "<< naixement<<", Assignatures ==> "<< n_assignatures << ")\n";
        cout << "Edat del nou estudiant: " << getedat() << "\n\n";
    }

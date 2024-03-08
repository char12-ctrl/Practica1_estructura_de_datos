#include<iostream>
#include<stdexcept>
#include"Estudiant.h"

using namespace std;




Estudiant::Estudiant(string frase, int any, int assig){
            //podriem fer servir this-> pero com els parametres es diuen diferent no fa falta
            nom=frase;
            naixement=any;
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

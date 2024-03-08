#include<iostream>
#include<stdexcept>
#include"Professor.h"

using namespace std;




Professor::Professor(string frase, int any){
            //podriem fer servir this-> pero com els parametres es diuen diferent no fa falta
            nom=frase;
            naixement=any;
            if(naixement<=0 || naixement > 2024){
                throw std::invalid_argument("received wrong value");
            }
            }
    //calculem edat
int Professor::getedat(){
        return 2024-naixement;
    }
    //escribim per pantalla
void Professor::print(){
        cout << "Estudiant(Nom ==> "<< nom <<", Naixement ==> "<< naixement<< ")\n";
        cout << "Edat del nou professor: " << getedat() << "\n\n";
    }

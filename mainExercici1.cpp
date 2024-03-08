#include <iostream>

using namespace std;

int main(void){
    string nom;
    int opcio,i;
    string arr_options[] = {"Sortir", "Benvinguda"};
    cout << "Hola, com et dius?";
    cin >> nom;
    do{
      cout << "Hola " << nom << ", que vols fer?\n";
      //mostrem les opcions per pantalla
      for(i=0;i<2;i++){
        cout << i+1 <<". " << arr_options[i] << "\n";
        }
      do{
        cin >> opcio;
        //considerem el cas que l'opcio escollida sigui incorrecte
        if(opcio != 1 && opcio !=2) cout << "Hola " << nom <<" has escollit una opcio incorrecte, que vols fer?\n";
      }while(opcio!= 1 && opcio != 2);    
      
      if(opcio==1){
        cout <<"Fins a la propera " << nom; 
        return 0;
        }
      cout << "Benvingut/da a l\'assignatura d\'estructura de dades " << nom << "\n";
    
    }while(opcio!=1);
    return 0;
    
}

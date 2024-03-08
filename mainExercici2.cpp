#include <iostream>
#include <vector>
//hem d'incloure la biblioteca vector per tractar amb vectors i no arrays

using namespace std;

int opcio_escollida(vector<string> &v, string nom);

int main(void){
    string nom;
    int opcio,i;
    vector<string> arr_options = {"Sortir", "Benvinguda", "Redifinir nom"};
    cout << "Hola, com et dius?";
    cin >> nom;
    do{
      cout << "Hola " << nom << ", que vols fer?\n";

      opcio=opcio_escollida(arr_options,nom);
      switch(opcio){
        case 1:
         cout <<"Fins a la propera " << nom; 
         return 0;
        case 2:
         cout << "Benvingut/da a l\'assignatura d\'estructura de dades " << nom << "\n";
         break;
        case 3:
         cout << "Hola, com et dius?";
         cin >> nom;
         break;
        }
    
    }while(opcio!=1);
    return 0;
}

int opcio_escollida(vector<string> &v, string nom){
    int i,opcio;
    //mostra les possibles opcions
    for(i=0;i<v.size();i++){
        cout << i+1 <<". " << v[i] << "\n";
        }
      do{
        cin >> opcio;
        //considerem el cas d'opcio incorrecte
        if(opcio != 1 && opcio !=2 && opcio !=3) cout << "Hola " << nom <<" has escollit una opcio incorrecte, que vols fer?\n";
      }while(opcio!= 1 && opcio != 2 && opcio !=3);
    return opcio;  
}

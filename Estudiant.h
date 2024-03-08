#include<iostream>
#include<stdexcept>

using namespace std;

class Estudiant{
    private:
    // demanem informació
    string nom;
    int naixement, n_assignatures;
    public:
    Estudiant(string, int,int);
    //retorna edat
    int getedat();
    //escribim per pantalla
    void print();
};

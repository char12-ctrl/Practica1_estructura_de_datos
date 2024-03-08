#include<iostream>
#include<stdexcept>

using namespace std;

class Professor{
    private:
    // demanem informació
    string nom;
    int naixement;
    public:
    Professor(string, int);
    //calculem edat
    int getedat();
    //escribim per pantalla
    void print(int);
};

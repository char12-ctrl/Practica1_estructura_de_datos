#include<iostream>


using namespace std;

class Song{
    private:
    // demanem informació
    string name;
    int songld,artistld,duration;
    float rating;
    public:
    Song(int, int, string, int, float);
    //getters
    string getname();
    int getsongld();
    int getartistld();
    int getduration();
    float getrating();
    //escribim per pantalla
    void print();
};

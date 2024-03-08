#include<iostream>
#include<vector>
#include"Song.h"

using namespace std;

class Artist{
    private:
    // demanem informació
    string name,gender,country,styles;
    int playcount,artistld;
    vector<Song> songs;
    public:
    Artist(int, string, string, string, string, int);
    //getters
    int getArtistld();
    string getName();
    string getGender();
    string getCountry();
    string getStyles();
    int getPlaycount();
    //escribim per pantalla
    void print();
    //afegim i eliminem cançons
    void addSong(int, int, string, int, float);
    void removeSong(int);
    void printSongs();

};

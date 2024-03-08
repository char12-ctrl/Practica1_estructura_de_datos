#include<iostream>
#include<stdexcept>
#include"Song.h"

using namespace std;


Song::Song( int song, int artist, string nom, int duracio, float aprobacio){
    name=nom;
    songld=song;
    artistld=artist;
    duration=duracio;
    rating=aprobacio;
}
//Definim els getters

string Song::getname(){
    return name;
}
int Song::getartistld(){
    return artistld;
}
int Song::getduration(){
    return duration;
}
int Song::getsongld(){
    return songld;
}
float Song::getrating(){
    return rating;
}

//Metode print:

void Song::print(){
    cout << "Nom cançó: " << getname() <<"\n";
    cout << "Duracio cançó: "<<getduration()<<"\n";
    cout<<"Identificador de la cançó: "<<getsongld()<<"\n";
    cout<<"Aprobació de la cançó: "<<getrating()<<"\n";
    return;
}

#include<iostream>
#include<vector>
#include"Artist.h"

using namespace std;

Artist::Artist(int artistld, string name, string gender, string country, string styles, int playcount){
        this->name=name;
        this->artistld=artistld;
        this->gender=gender;
        this->country=country;
        this->styles=styles;
        this->playcount=playcount;
}

//Getters

int Artist::getArtistld(){
    return artistld;
}
string Artist::getName(){
    return name;
}
string Artist::getGender(){
    return gender;
}
string Artist::getCountry(){
    return country;
}
string Artist::getStyles(){
    return styles;
}
int Artist::getPlaycount(){
    return playcount;
}
//Resta de metodes:
void Artist::print(){
    cout << "Identificador artista: " << getArtistld() <<"\n";
    cout << "Nom artista: " << getName()<<"\n";
    cout << "Genere "<< getGender()<<"\n";
    cout << "Pais:" << getCountry()<<"\n";
    cout <<"Estil:"<<getStyles()<<"\n";
    cout <<"Reproduccions: "<<getPlaycount()<<"\n\n";
    return;
}
void Artist::addSong(int id_song, int id_artist, string nom_canco, int temps, float acceptacio){
    //comprobem si la canço ja existeix i aleshores llança un error i no l'afegim
    for(int i=0;i<songs.size();i++){
        if(songs[i].getsongld()==id_song){
            throw std::invalid_argument("La canço ja existeix");
            return;
        }
    }
    Song canco(id_song,id_artist,nom_canco,temps,acceptacio);
    songs.push_back(canco);
    return;
}
void Artist::removeSong(int id){
    for(int i=0;i< songs.size();i++){
        if(songs[i].getsongld()==id){
            songs.erase(songs.begin()+i);
            return;
        }
    }
    throw std::invalid_argument("La canço no existeix");
    return;
}
void Artist::printSongs(){
    if(songs.size()>=1){
        for(int i=0;i< songs.size();i++){
            songs[i].print();
        }
    }
    else cout << "No té cap canço\n";    
    return;
}

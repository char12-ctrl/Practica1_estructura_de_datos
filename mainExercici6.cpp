#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
#include"Artist.h"

using namespace std;

int opcio_escollida(vector<string> &v);
void afegir_artista(vector<Artist> &a);
void eliminar_artista(vector<Artist> &a, int id);
void afegir_canco(vector<Artist> &a);
void eliminar_canco_artista(vector<Artist> &a);
void imprimir_artistes(vector<Artist> &a);
void imprimir_cancons_art(vector<Artist> &a);



int main(void){
    
    int opcio,i,id;
    vector<string> arr_options = {"Afegir artista", "Eliminar artista", "Afegir canço a un artista","Eliminar canço d'un artista","Imprimir artistes SpotUBy","Imprimir les cançons d'un artista","Sortir"};
    vector<Artist> artistes;
    i=0;
    do{
      opcio=opcio_escollida(arr_options);
      //Fem un switch
      switch(opcio){
        case 0:
            cout <<"Fins a la propera \n";
            return 0;
        case 1:
            afegir_artista(artistes); 
            break;
        case 2:
            cout << "Quin es l'artistId de l'artista que vols eliminar?\n";
            cin >> id;
            eliminar_artista(artistes,id);
         break;
        case 3:
            afegir_canco(artistes);
            break;
        case 4: 
            eliminar_canco_artista(artistes);
            break;
        case 5:
            imprimir_artistes(artistes);
            break;
        case 6:
            imprimir_cancons_art(artistes);
            break;            
        
        }

    
    }while(opcio!=0);
    return 0;
    
}

int opcio_escollida(vector<string> &v){
    int i,opcio;
    //mostra les possinles opcions
    for(i=0;i<v.size()-1;i++){
        cout << i+1 <<". " << v[i] << "\n";
        }
    cout << 0 <<". "<<v[v.size()-1]<<"\n";
    do{
       cin >> opcio;
       //considerem el cas d'opcio incorrecte
       if(opcio != 0 && opcio != 1 && opcio !=2 && opcio !=3 && opcio != 4 && opcio != 5 && opcio != 6) cout << "Hola has escollit una opcio incorrecte, que vols fer?\n";
    }while(opcio != 0 && opcio != 1 && opcio !=2 && opcio !=3 && opcio != 4 && opcio != 5 && opcio != 6);
    return opcio;  
}

void afegir_artista(vector<Artist> &a){
    int ident,playercount,j=0,i,k;
    string name,gender,country,styles,opcio;
    //Demanem dades:
    cout << "Nom de l'artista?\n";
    cin >> name;
    cout << "Genere de l'artsita?\n";
    cin >> gender;
    cout << "Pais de l'artista?\n";
    cin >> country;
    cout << "Estil de l'artista?\n";
    cin >> styles;
    cout << "Identificador de l'artista?\n";
    cin >> ident;
    cout << "Reproduccions de l'artista?\n";
    cin >> playercount;
    Artist music(ident, name, gender, country, styles, playercount);
    //Observem si el artista ja esta afegit
    for(i=0;i<a.size();i++){
        if(a[i].getArtistld()==music.getArtistld()){
            cout <<"L'artista ja esta afegit \n";
            return;
        }
    }
    //Si es segueix executant la funcio es que l'artista no existeix
    a.push_back(music);
    cout << "Vol afegir una canço?\n";
    cin >> opcio;
    if( opcio == "si" || opcio == "Si"){
            afegir_canco(a);
    }
    return;
    
        
}

void eliminar_artista(vector<Artist> &a, int id){
    int i;
    for(i=0;i<a.size();i++){
        if(a[i].getArtistld()==id){
            a.erase(a.begin()+i);
            return;
        }
    }
    //Si es segueix executant l'artista no existeix
    cout << "L'artista amb identificador " << id <<" no esta afegit\n";
    return;
}

void afegir_canco(vector<Artist> &a){
    int id,iden,temps;
    float rate;
    string nam;
    cout << "Quin es l'identificador de l'artista al qual vols afegir una canco?\n";
    cin >> id;
    //Demanem les dades de la canço
    cout << "Quin es el nom de la canço?\n";
    //utilizamos getline por si el titulo de la cancion tiene espacios
    cin.ignore();
    getline(cin,nam);
    cout<<"Quin es l'identificador de la canço?\n";
    cin >> iden;
    cout<<"Quina es la durada de la canço?\n";
    cin>>temps;
    cout<<"Quina es l'aprobacio de la canço?\n";
    cin >> rate;
    //Observem si l'artista existeix, amb el try i catch fem referncia a que addSong pot llençar un error si la canço ja existeix
    try{
        for(int i=0;i<a.size();i++){
            if(a[i].getArtistld()==id){
                a[i].addSong(iden, id, nam, temps, rate);
                return;
            }
        }
        //Si es segueix executan la funció es que l'artista no existeix
        cout << "L'artista no existeix, afegeix primer l'artista(opcio 1)\n";
    }catch(const std::invalid_argument &ex){    
        //Si no existeix es segueix executant la funcio:
        cout << "La cançó ja esta afegida\n";
    }
    return;
}
//try y catch si no existeix artista o canço
void eliminar_canco_artista(vector<Artist> &a){
    int id_art,id_can,j,k=0;
    cout << "Dona'm l'identificador de l'artista\n";
    cin >> id_art;
    cout << "Dona'm l'identificador de la canço\n";
    cin>>id_can;
    //Amb try i catch fem referencia a que la funció removeSong llença un error si la canço no existeix
    try{
    for(int i=0;i<a.size();i++){
        if(a[i].getArtistld()==id_art){
                k=1;
                a[i].removeSong(id_can);
        }
    }
    }catch(const std::invalid_argument &ex){
        cout <<"La canço no existeix\n";
    }
    //Fem servir la variable k que si val 0 és que no ha entrat al primer if i per tant l'artista no existeix
    if(k==0) cout << "L'artista no existeix\n";
    
    return;
    }


void imprimir_artistes(vector<Artist> &a){
    int i;
    if(a.size()>=1){
        for(int i=0;i<a.size();i++){
            a[i].print();
        }
    }
    else{
        cout << "No hi ha cap artista afegit";
    }    
    return;    
}

void imprimir_cancons_art(vector<Artist> &a){
    int i,id;
    cout << "Digues l'artista id del qual vols imprimir les cançons\n";
    cin >> id;
    for(int i=0;i<a.size();i++){
        if(a[i].getArtistld()==id){
            a[i].printSongs();
            return;
        }
    }
    cout << "La id de l'artista donada no existeix, afegeix l'artista(opcio 1)\n";
    return;        
}

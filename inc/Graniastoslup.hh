#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
#include "Bryly.hh"
class Graniastoslup : public Bryla{ //dziedziczenie
public:
    Graniastoslup(Wektor3D srodek,double promien, string nazwa_pliku, string nazwa_pliku_do_zapisu);
};

Graniastoslup::Graniastoslup(Wektor3D srodek,double promien,string nazwa_pliku, string nazwa_pliku_do_zapisu){
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    katOX = 0;
    katOY = 0;
    katOZ = 0;
    Wektor3D tmp;
    for(int i=0; i<=300; i+=60){
        tmp[0]=srodek[0];
        tmp[1]=srodek[1]+promien*sin(i*M_PI/180);
        tmp[2]=srodek[2]+promien*cos(i*M_PI/180);
        wierzcholki.push_back(tmp);
        tmp[0]=srodek[0]+5;
        tmp[1]=srodek[1]+promien*sin(i*M_PI/180);
        tmp[2]=srodek[2]+promien*cos(i*M_PI/180);
        wierzcholki.push_back(tmp);
    }

    wierzcholki.push_back(wierzcholki[0]);
    wierzcholki.push_back(wierzcholki[1]);
    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<wierzcholki[i]<<endl;
    }
    plik.close();
    zapis();
}

#endif
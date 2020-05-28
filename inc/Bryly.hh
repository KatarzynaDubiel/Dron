#ifndef BRYLY_HH
#define BRYLY_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Bryla
{
    protected:
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow

    vector<Wektor3D> wierzcholki;
    Wektor3D Przesuniecie;
    Wektor3D srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    public:
    void zapis();
    void translacja();
    void set_Przesuniecie(Wektor3D droga){
        Przesuniecie=Przesuniecie+OZ(katOZ)*(OX(katOX)* (OY(katOY)*droga));
    }
    void set_katOX(double kat){katOX+=kat;}
    void set_katOZ(double kat){katOZ+=kat;}
    void set_katOY(double kat){katOY=kat;}
    Wektor3D &operator [](int i){return wierzcholki[i];}
      Wektor3D operator [](int i)const {return wierzcholki[i];}
};

void Bryla::translacja(){
    ifstream plik;
    plik.open(nazwa_pliku);

for(int i=0; i<(int)wierzcholki.size(); i++){//rzutowanie wierzcholkow na int
       plik>> wierzcholki[i];
    }
    plik.close();
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        wierzcholki[i]=OZ(katOZ)*(OX(katOX)*(wierzcholki[i]-srodek))+srodek+Przesuniecie;
    }
}
void Bryla::zapis(){
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<wierzcholki[i]<<endl;//robie enter co 2 linie
    }
    plik.close();
}

#endif
#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "Wektor3D.hh"
#include "Macierz3x3.hh"
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Plaszczyzna{
    protected:
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow

    vector<Wektor3D> wierzcholki;
    Wektor3D Przesuniecie;
    Wektor3D srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    int k=0;// ilosc punktów na prostej
    public:
    Plaszczyzna(double dlugosc, double szeroksc,double glebokosc, double fala, string nazwa_pliku, string nazwa_pliku_do_zapisu){
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    katOX = 0;
    katOY = 0;
    katOZ = 0;
    Wektor3D tmp;
    int m=0;
    k=0;
    for(int i=-dlugosc/2; i<=dlugosc/2; i+=10){
       for(int j=-szeroksc/2; j<=szeroksc/2; j+=10){
                tmp[0]=i;
                tmp[1]=j;
                if(m%2==0)
                tmp[2]=glebokosc;
                else
                tmp[2]=glebokosc+fala;

                wierzcholki.push_back(tmp);
                m++;
        }
        k++;
    }
    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)wierzcholki.size(); i++){
        if(i%k==0)
        plik<<endl;
        plik<<wierzcholki[i]<<endl;
    }
    plik.close();
}
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
void  Plaszczyzna::translacja(){
    ifstream plik;
    plik.open(nazwa_pliku);

for(int i=0; i<(int)wierzcholki.size(); i++){
       plik>> wierzcholki[i];
    }
    plik.close();
    for(int i=0; i<(int)wierzcholki.size(); i++){

        wierzcholki[i]=OZ(katOZ)*(OX(katOX)*(wierzcholki[i]-srodek))+srodek+Przesuniecie;
    }
}
void Plaszczyzna::zapis(){
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)wierzcholki.size(); i++)
    {
        if(i%k==0)
        plik<<endl;
        plik<<wierzcholki[i]<<endl;
    }
    plik.close();
}

#endif
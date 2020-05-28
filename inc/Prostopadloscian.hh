#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "Bryly.hh"
class Prostopadloscian : public Bryla{
public:
    Prostopadloscian(double dlugosc, double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);
};

Prostopadloscian::Prostopadloscian(double dlugosc, double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu)
{
    this->nazwa_pliku = nazwa_pliku;
    this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    katOX = 0;
    katOY = 0;
    katOZ = 0;
    Wektor3D tmp;
    tmp[0] = -dlugosc / 2;
    tmp[1] = -szerokosc / 2;
    tmp[2] = -wysokosc / 2;
    wierzcholki.push_back(tmp);
    tmp[0] = wierzcholki[0][0] + dlugosc;
    wierzcholki.push_back(tmp);
    tmp[0] = wierzcholki[0][0];
    tmp[1] = wierzcholki[0][1] + szerokosc;
    wierzcholki.push_back(tmp);
    tmp[0] = wierzcholki[0][0] + dlugosc;
    tmp[1] = wierzcholki[0][1] + szerokosc;
    wierzcholki.push_back(tmp);

    tmp[0] = wierzcholki[0][0];
    tmp[1] = wierzcholki[0][1] + szerokosc;
    tmp[2] = wierzcholki[0][2] + wysokosc;
    wierzcholki.push_back(tmp);
    tmp[0] = wierzcholki[0][0] + dlugosc;
    tmp[1] = wierzcholki[0][1] + szerokosc;
    tmp[2] = wierzcholki[0][2] + wysokosc;
    wierzcholki.push_back(tmp);

    tmp[0] = wierzcholki[0][0];
    tmp[1] = wierzcholki[0][1];
    tmp[2] = wierzcholki[0][2] + wysokosc;
    wierzcholki.push_back(tmp);
    tmp[0] = wierzcholki[0][0] + dlugosc;
    tmp[1] = wierzcholki[0][1];
    tmp[2] = wierzcholki[0][2] + wysokosc;
    wierzcholki.push_back(tmp);

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
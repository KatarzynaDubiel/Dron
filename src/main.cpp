#include <iostream>
#include <iomanip>
#include <vector>
#include "lacze_do_gnuplota.hh"

#include "Wektor.hh"

using namespace std;

//typename std::vector <Wektor3D> Tab;
//Tab.push_back();

int main()
{
  cout<<"\n \t Prosze spojrzec do pliku src/Dron.cpp - a nuz cos sie nada na punktacje"<<endl;
  int FWektor();
    PzG::LaczeDoGNUPlota  Lacze;
    char c;

    //Wektor<double,3> Wektor3D;

    Lacze.DodajNazwePliku("bryly/plaszczyzna_dol.dat");
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

    Lacze.UstawZakresX(-40, 100);
    Lacze.UstawZakresY(-90, 90);
    Lacze.UstawZakresZ(-20, 90);


    Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
    cout << "\n \t A tutaj scena ... " << flush;
    Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                          // z rysunkiem, o ile istnieje plik "prostopadloscian1.dat"
    //cout << "Nacisnij ENTER, aby zobaczyc drona ... " << flush;
    //cin >> noskipws >> c;

    //Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku("bryly/prostopadloscian.dat");
    Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                          // z rysunkiem, o ile istnieje plik "prostopadloscian2.dat"

    //cout << "Nacisnij ENTER, aby zobaczyc powierzchnie wody ... " << flush;
    //cin >> noskipws >> c;

    //Lacze.UsunWszystkieNazwyPlikow();
    Lacze.DodajNazwePliku("bryly/plaszczyzna_gora.dat");
    Lacze.Rysuj();        // Teraz powinno pojawic sie okienko gnuplota
                          // z rysunkiem, o ile istnieje plik "prostopadloscian3.dat"*/

  cout << "\n \n \t Nacisnij ENTER, aby zakonczyc ... " << flush;
   cin >> noskipws >> c;
      return 0;
  
}

#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>//potrzebne do usleep
#include "lacze_do_gnuplota.hh"
#include "Dron.hh"
#include "Plaszczyzna.hh"
using namespace std;

int main(){

 Dron korpus;

    PzG::LaczeDoGNUPlota  Lacze;
    Plaszczyzna dno(60,60,-30,0,"bryly/dno.dat","bryly/dno2.dat");
    dno.zapis();
    Plaszczyzna fale(60,60,50,10,"bryly/fala.dat","bryly/fala2.dat");
     fale.zapis();
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.

    Lacze.UstawZakresX(-90, 100);
    Lacze.UstawZakresY(-60, 90);
    Lacze.UstawZakresZ(-50, 90);


    Lacze.UstawRotacjeXZ(68,42); // Tutaj ustawiany jest widok 40, 40
      Lacze.DodajNazwePliku("bryly/fala2.dat");
       Lacze.DodajNazwePliku("bryly/dno2.dat");
    Lacze.DodajNazwePliku("bryly/korp2.dat");
       Lacze.DodajNazwePliku("bryly/s1_2.dat");
         Lacze.DodajNazwePliku("bryly/s2_2.dat");
    Lacze.Rysuj();

  char opcja;
  double kat, droga;
  cout<<endl<<"r - zadaj ruch na wprost"<<endl<<"o- zadaj zmiane orientacji"<<endl<<"m - wyswietl menu"<<endl<<endl<<"k - koniec dzialania programu"<<endl<<endl<<"Twoj wybor, m - menu> ";
  while(1)
  {
    cin>>opcja;
    switch (opcja){
    case 'r':
    cout<<"Podaj wartosc kata (wznoszenia/opadania) w stopniach."<<endl<<"Wartosc kata> ";
    cin>>kat;
    cout<<"Podaj wartosc odleglosci, na ktora ma sie przemiescic dron."<<endl<<"Wartosc odleglosci> ";
    cin>>droga;
      for(int i=0; i<droga; i++){
        korpus.sterowanie(1,kat,0);
        Lacze.Rysuj();
        usleep(200000);
      }
        cout<<"Aktualna ilosc obiektow Wektor3D: "<< SWektor<double,3>::get_aktualne() <<endl<<"Laczna ilosc obiektow Wektor3D: "<<SWektor<double,3>::get_wszystkie()<<endl<<endl<<"Twoj wybor, m - menu> ";
      break;
        case 'o':
      cout<<"Podaj wartosc kata obrotu w stopniach."<<endl<<"Wartosc kata> ";
      cin>>kat;
      for(int i=0; i<kat; i++)
      {
        korpus.sterowanie(0,0,1);
        Lacze.Rysuj();
        //usleep(200000);
      }
      cout<<"Aktualna ilosc obiektow Wektor3D: "<< SWektor<double,3>::get_aktualne() <<endl<<"Laczna ilosc obiektow Wektor3D: "<<SWektor<double,3>::get_wszystkie()<<endl<<endl<<"Twoj wybor, m - menu> ";
      break;
      case 'm':
        cout<<endl<<"r - zadaj ruch na wprost"<<endl<<"o- zadaj zmiane orientacji"<<endl<<"m - wyswietl menu"<<endl<<endl<<"k - koniec dzialania programu"<<endl<<endl<<"Twoj wybor, m - menu> ";
      break;
      case 'k':
      cout<<"Koniec programu"<<endl<<endl;
      cout<<"Aktualna ilosc obiektow Wektor3D: "<< SWektor<double,3>::get_aktualne() <<endl<<"Laczna ilosc obiektow Wektor3D: "<<SWektor<double,3>::get_wszystkie()<<endl<<endl<<"Twoj wybor, m - menu> ";
      return 0;
      break;
    default:
      break;
    }
  }
      return 0;

}

#include<iostream>
#include<fstream>
#include<vector>
#include "Wektor.hh"

using namespace std;

int FWektor(){

    using Wektor3D=SWektor<double,3>;
    Wektor3D Punkt;
    ifstream Wczytane;
    Wczytane.open("prostopadloscian.dat");
    Wczytane>>Punkt;
    if(cin.fail()){
        cout<<"Cos plik nie halo"<<endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cout<<Punkt;

    vector<Wektor3D> Lamana;
    Lamana.push_back(Punkt);
    cout<<Lamana[0];

    return 0;
}
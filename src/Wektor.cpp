//zabawa z vectorem - zapis z vectora do pliku:
// miec dane poczatkowe (scenę), przeliczac vector, potem nowe dane nadpisywac
//zczytac z pliku i zapisac do pliku; do vectora od vectora
#include <iostream>
#include <vector>
#include <fstream>

int main(){
    std::string linia;
     std::vector<double> Wektor;
    std::fstream plik; //dowolna nazwa - okreslenie pliku
    plik.open("zapisane.txt",std::ios::in);//in - z pliku do programu
    if(plik.good()==false){
        std::cout<<"Blad - plik nie istnieje :(";
        exit(0);
    }

/////
 int licznik=0;
    while(!plik.eof()){
        std::getline(plik, linia);
        Wektor.push_back(atoi(linia.c_str()));
        licznik++;
    }
    plik.close();//important!

    //plik.close();//important!
    plik.open("zapisane.txt",std::ios::out);
    for(int i=0; i<licznik-1; i++){
        std::cout<<Wektor[i]<<std::endl;
        Wektor[i]+=3;//DZIANIE SIE Z WEKTOREM
        Wektor.push_back(Wektor[i]);
        plik<<Wektor[i]<<std::endl;//DE SEI W PLIKULACZEGO NE ZAPISUJ
    }
    plik.close();
    for(int i=0; i<licznik-1; i++){
        std::cout<<Wektor[i]<<std::endl;
    }


    return 0;
}
#include <iostream>
#include <string>
#include <math.h>
#include <vector>


    std::string Nazwa;

    class FiguraGeometryczna{
            public:
            virtual double obliczPolePowierzchni(std::string Figura, double Bok1, double Bok2, double promien){
                double Pole;
                if(Figura=="P"){
                    Pole=Bok1*Bok2;
                }
                else{
                    Pole=M_PI*promien*promien;
                }
                std::cout<<Pole;
                return Pole;
            }
            virtual double zwrocNazwe(std::string Nazwa){
                return 0;
            }

            class Prostokat:public FiguraGeometryczna{
                double Bok11=3;
                double Bok22=4;
                obliczPolePowierzchni("P", Bok11, Bok22, 0);
            }

            class Kolo:public FiguraGeometryczna{
            std::cout<<":)";
            return 0;
            }

            return 0;
    };
// std::vector<Prostokat> WP;
// std::vector<Kolo> WP;

int main(){
FiguraGeometryczna();
}
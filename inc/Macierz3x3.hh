#ifndef MACIERZ3X3_HH
#define MACIERZ3X3_HH

#include "Macierz.hh"
#include <cmath>

typedef SMacierz<double, 3> Macierz3x3;

//macierze obrotow

Macierz3x3 OX(double kat){
    Macierz3x3 tmp;
    tmp[0][0] = 1;
    tmp[0][1] = 0;
    tmp[1][2] = 0;
    tmp[1][0] = 0;
    tmp[1][1] = cos(kat * M_PI / 180);
    tmp[1][2] = -sin(kat * M_PI / 180);
    tmp[2][0] = 0;
    tmp[2][1] = sin(kat * M_PI / 180);
    tmp[2][2] = cos(kat * M_PI / 180);
    return tmp;
}

Macierz3x3 OY(double kat){
    Macierz3x3 tmp;
    tmp[0][0] = cos(kat * M_PI / 180);
    tmp[0][1] = 0;
    tmp[1][2] = sin(kat * M_PI / 180);
    tmp[1][0] = 0;
    tmp[1][1] = 1;
    tmp[1][2] = 0;
    tmp[2][0] = -sin(kat * M_PI / 180);
    tmp[2][1] = 0;
    tmp[2][2] = cos(kat * M_PI / 180);
    return tmp;
}

Macierz3x3 OZ(double kat){
    Macierz3x3 tmp;
    tmp[0][0] = cos(kat * M_PI / 180);
    tmp[0][1] = -sin(kat * M_PI / 180);
    tmp[0][2] = 0;
    tmp[1][0] = sin(kat * M_PI / 180);
    tmp[1][1] = cos(kat * M_PI / 180);
    tmp[1][2] = 0;
    tmp[2][0] = 0;
    tmp[2][1] = 0;
    tmp[2][2] = 1;
    return tmp;
}

#endif
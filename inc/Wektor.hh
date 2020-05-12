#ifndef WEKTOR_HH
#define WEKTOR_HH

//dziedziczenie
//pamiętaj, ze istnieje przelanianie :)

class Wektor3D{
    double x=0;
}

class FiguraGeometryczna: public Wektor3D{
    double y=0;
}

class Graniastoslup: FiguraGeometryczna{
    double z=0
}

class Dron: Graniastoslup{
    double k=0;
}

class Scena: Dron{
    double m=0;
}


#endif
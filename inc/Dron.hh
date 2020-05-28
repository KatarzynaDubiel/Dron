#ifndef DRON_HH
#define DRON_HH
#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
class Dron
{
    Prostopadloscian *korpus;
    Graniastoslup *smiglo1;
    Graniastoslup *smiglo2;
    public:
    Dron()
    {
          korpus = new Prostopadloscian(10,10,10,"bryly/korp.dat","bryly/korp2.dat");
          smiglo1 = new Graniastoslup((*korpus)[0],6,"bryly/s1.dat","bryly/s1_2.dat");
          smiglo2 = new Graniastoslup((*korpus)[2],6,"bryly/s2.dat","bryly/s2_2.dat");
    }
    void sterowanie(double droga,double OY,double OZ)
    {
        Wektor3D tmp;
        tmp[0]=droga;
        smiglo1->set_katOZ(OZ);
        smiglo1->set_katOY(OY);
        smiglo1->set_katOX(3);
        smiglo1->set_Przesuniecie(tmp);
                smiglo2->set_katOZ(OZ);
        smiglo2->set_katOY(OY);
        smiglo2->set_katOX(3);
        smiglo2->set_Przesuniecie(tmp);
        korpus->set_katOY(OY);
        korpus->set_katOZ(OZ);
        korpus->set_Przesuniecie(tmp);
        korpus->translacja();
         korpus->zapis();
                 smiglo1->translacja();
         smiglo1->zapis();
                 smiglo2->translacja();
         smiglo2->zapis();
    }

};


#endif 
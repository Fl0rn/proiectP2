#ifndef OFERTE_H
#define OFERTE_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
class Oferte
{protected:
    std::string nume;
    int pret;
    int durata;

public:
    Oferte(std::string,int,int);
    Oferte();
    virtual ~Oferte();
    void setNume(std::string);
    void setDurata(int);
    void setPret(int);
    void afisare_oferte();
    void afisare_ecran_oferta();
    friend std::ostream & operator << (std::ostream &, const Oferte &);
    std::string getNume();
    int getPret();
    int getDurata();
    class Oferte& operator=(const Oferte&);

};

#endif // OFERTE_H

#ifndef PROGRAMARI_H
#define PROGRAMARI_H
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <Oferte.h>


class Programari : public Oferte
{
public:
    Programari(Oferte,int,std::string,std::string,int);
    Programari();
    void setOferte(Oferte);
    void setIndice(int);
    void setZi(int);
    void setPrenume(std::string);
    void setStatus(std::string);
    virtual ~Programari();
    Oferte getOferte();
    int getIndice();
    std::string getPrenume();
    std::string getStatus();
    int getZi();
     class Programari& operator=(const Programari&);

protected:
    Oferte oferte2;
    int indice_orar;
    std::string prenume;
    std::string status;
    int zi;

private:
};

#endif // PROGRAMARI_H

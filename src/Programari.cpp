#include "Programari.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <Oferte.h>
using namespace std;


Programari::Programari(Oferte oferte2,int indice_orar,string prenume,string status,int zi)
{
    this->oferte2=oferte2;
    this->indice_orar=indice_orar;
    this->prenume=prenume;
    this->status=status;
    this->zi=zi;
}
Programari::Programari()
{
    this->setOferte(Oferte());
    this->setIndice(0);
    this->setNume("");
    this->status=status;

}
Oferte Programari:: getOferte()
{
    return this->oferte2;
}
int Programari::getIndice()
{
    return this->indice_orar;
}
string Programari::getPrenume()
{
    return this->prenume;

}
string Programari::getStatus()
{
    return this->status;
}
int Programari::getZi()
{
    return this->zi;
}
Programari::~Programari()
{
}
void Programari::setOferte(Oferte)
{this->oferte2=oferte2;

}
void Programari::setIndice(int)
{
    this->indice_orar=indice_orar;

}
void Programari::setPrenume(string)
{
    this->prenume=prenume;
}
void Programari::setStatus(string)
{
    this->status=status;
}
Programari& Programari ::operator=(const Programari&x){
  if (&x == this) return *this;
  this->oferte2 = x.oferte2;
  this->prenume = x.prenume;
  this->indice_orar=x.indice_orar;
  this->status=x.status;
  this->zi=x.zi;
  return * this;
}
void Programari::setZi(int)
{
    this->zi=zi;

}


#include "Oferte.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

ifstream rin("oferte");
ofstream rout("programari1");

Oferte::Oferte(string nume,int pret,int durata)
{
    this->nume=nume;
    this->pret=pret;
    this->durata=durata;

}
Oferte::Oferte()
{
    this->setNume("");
    this->setPret(0);
    this->setDurata(0);

}
Oferte::~Oferte()
{
}

ostream & operator << (ostream &st, const Oferte &x){
  st << x.nume<<" "<< x.pret <<" "<<x.durata;
  return st;
}


void Oferte::afisare_oferte()
{
    rout<<"Nume oferta: "<<this->nume<<" "<<"pret: "<<this->pret<<" "<<"durata: "<<this->durata;
}
void Oferte::afisare_ecran_oferta()
{
    cout<<"Nume oferta: "<<this->nume<<" "<<"pret: "<<this->pret<<" "<<"durata: "<<this->durata;
    cout<<endl;

}
Oferte& Oferte ::operator=(const Oferte&x){
  if (&x == this) return *this;
  this->nume = x.nume;
  this->pret = x.pret;
  this->durata=x.durata;
  return * this;
}

int Oferte::getPret()
{
    return this->pret;
}
int Oferte::getDurata()
{
    return this->durata;
}

void Oferte:: setNume(string)
{
    this->nume=nume;
}
void Oferte:: setPret(int)
{
    this->pret=pret;

}
void Oferte::setDurata(int)
{
    this->durata=durata;
}
string Oferte::getNume()
{
    return this->nume;
}


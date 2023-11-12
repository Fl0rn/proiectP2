#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <Oferte.h>
#include <Programari.h>
#include <windows.h>
#define GREEN 2
#define BLUE 3
#define RED 12
#define YELLOW 14
#define WHITE 15

void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}
using namespace std;


vector<Oferte> vect_oferte;
vector<Programari> vector_programari;
int conversie(int ora,int minut)
{
    int x,y;
    if(x>21)
        return 0;
    else
    {
        x=(ora-10)*4;
        if(minut==0)
            y=0;
        if(minut==15)
            y=1;
        if(minut==30)
            y=2;
        if(minut==45)
            y=3;
        return x+y;
    }
}

conversie2(int x)
{
    int y;

    if(x==15)
        y=1;
    if(x==30)
        y=2;
    if(x==45)
        y=3;
    return y;
}

void afisare_istoric(vector<Programari>vector_programari,string nume)
{
    for(vector<Programari>::iterator it= vector_programari.begin(); it != vector_programari.end(); it++)
        if((*it).getPrenume()==nume)
            cout<<(*it).getPrenume()<<" "<<(*it).getIndice()<<" "<<(*it).getStatus()<<" "<<(*it).getOferte().getNume()<<" "<<(*it).getZi()<<endl;

}
Oferte cautare_vector(vector<Oferte>vect_oferte,string nume_oferta)
{
    for(vector<Oferte>::iterator it= vect_oferte.begin(); it != vect_oferte.end(); it++)
        if((*it).getNume()==nume_oferta)
            return *it;

}

int main()
{
    ifstream fin("oferte.txt");
    string nume,nume_oferta;
    int ora,minut,indice,zi;
    int pret,durata;
    int nr_oferte,nr_oferte2,nr_programari,nr_programari2;
    fin>>nr_oferte;
    nr_oferte2=nr_oferte;
    while(nr_oferte2)
    {
        fin>>nume;
        fin>>pret;
        fin>>durata;
        Oferte o(nume,pret,durata);
        vect_oferte.push_back(o);
        nr_oferte2--;
    }
    fin.close();

    ifstream gin("programari1.txt");

    gin>>nr_programari;

    nr_programari2=nr_programari;
    while(nr_programari2)
    {
        int zi;
        string prenume,status;
        gin>>prenume;
        gin>>indice;
        gin>>status;
        gin>>nume;
        Oferte x=cautare_vector(vect_oferte,nume);
        gin>>zi;
        Programari prog(x,indice,prenume,status,zi);
        vector_programari.push_back(prog);
        nr_programari2--;
    }

    gin.close();
goback:

    int variante;set_color(RED);
    cout<<"     MENIU\n";
    cout<<"1)";
    set_color(WHITE);
           cout<<"Vizualizare catalog oferte\n";
           set_color(RED);

    cout<<"2)";
    set_color(WHITE);
    cout<<"Programeaza o sedinta\n";
    set_color(RED);

    cout<<"3)";
    set_color(WHITE);
   cout<<"Vezi istoric\n";
   set_color(RED);
    cout<<"4)";
    set_color(WHITE);
    cout<<"STOP\n";
    do
    {
        cout<<("Alege: ");
        cin>>variante;
    }
    while((variante<0)||(variante>4));
    if(variante==1)
    {
        system("CLS");
        for(vector<Oferte>::iterator it= vect_oferte.begin(); it != vect_oferte.end(); it++)
            cout<<*it<<endl;
            system("PAUSE");
            system("CLS");
            goto goback;

    }


    if(variante==2)
    { set_color(YELLOW);
        system("CLS");
        cout<<"Introduceti numele: ";
        cin>>nume;
        system("CLS");
        cout<<"Ce serviciu ati dorii: ";
        cin>>nume_oferta;
        system("CLS");
        cout<<"In ce zi v-ati dorii: ";
        cin>>zi;
        system("CLS");
        cout<<"De la ce ora ati dorii: "<<endl;
        cout<<"Ora: ";
        cin>>ora;
        system("CLS");
        cout<<"minutul: ";
        cin>>minut;
set_color(WHITE);
        indice=conversie(ora,minut);
        Oferte x=cautare_vector(vect_oferte,nume_oferta);

        Programari p(x,indice,nume,"pending",zi);

        vector_programari.push_back(p);
        nr_programari++;
        system("PAUSE");
        system("CLS");
        goto goback;
    }
    ofstream fout("programari1.txt");
    fout<<nr_programari<<endl;
    for(int i=0; i<nr_programari; i++)
    {
        fout<<vector_programari[i].getPrenume()<<'\n';
        fout<<vector_programari[i].getIndice()<<'\n';
        fout<<vector_programari[i].getStatus()<<'\n';
        fout<<vector_programari[i].getOferte().getNume()<<'\n';
        fout<<vector_programari[i].getZi()<<'\n';


    }
    fout.close();

    if(variante==3)
    {set_color(GREEN);

        string nume2;
        system("CLS");
        cout<<"Introduceti-va numele: ";
        cin>>nume2;
        system("CLS");
        afisare_istoric(vector_programari,nume2);
        system("PAUSE");
        system("CLS");
        goto goback;

    }

    return 0;
}

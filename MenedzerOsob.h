#ifndef MENEDZEROSOB_H
#define MENEDZEROSOB_H

#include "Osoba.h"
#include "PlikiZOsobami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class MenedzerOsob
{
    Osoba osoba;
    PlikiZOsobami plikiZOsobami;

    vector <Osoba> osoby;
    string podaneImie;
    string podaneNazwisko;

    void wyswietlDaneAdresata(Osoba osoba);
    string wyswietlaniePoImieniu(Osoba osoba, string podaneImie);
    string wyswietlaniePoNazwisku(Osoba osoba, string podaneNazwisko);

public:
    MenedzerOsob()
    {
     osoby=plikiZOsobami.wczytajOsobyZPliku();
    };

    Osoba dodajOsobe();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkieOsoby();
};

#endif

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
    vector <string> linieOsob;
    string podaneImie;
    string podaneNazwisko;

    void wyswietlDaneAdresata(Osoba osoba);
    string wyswietlaniePoImieniu(Osoba osoba, string podaneImie);
    string wyswietlaniePoNazwisku(Osoba osoba, string podaneNazwisko);

public:
    MenedzerOsob()
    {
     osoby=plikiZOsobami.wczytajOsobyZPliku();
     linieOsob=plikiZOsobami.wczytajLinieZPlikuDoWektora();
    };

    Osoba dodajOsobe();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkieOsoby();
    void usunOsobe();
    void edytujOsobe();
    string edycjaDanych(Osoba osoba, string trescDoEdycji, string zmianaDanych, char wybor);
    void wyswietlOsobe(Osoba osoba);


};

#endif

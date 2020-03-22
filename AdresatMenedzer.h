#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "Adresat.h"
#include "PlikiZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer
{
    Adresat adresat;
    PlikiZAdresatami plikiZAdresatami;

    vector <Adresat> adresaci;
    vector <string> linieAdresatow;
    string podaneImie;
    string podaneNazwisko;

    void wyswietlDaneAdresata(Adresat adresat);
    string wyswietlaniePoImieniu(Adresat adresat, string podaneImie);
    string wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko);

public:
    AdresatMenedzer()
    {
     adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
     linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    };

    Adresat dodajAdresata();
    void wyszukajPoImieniu();
    void wyszukajPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edytujAdresata();
    string edycjaDanych(Adresat adresat, string trescDoEdycji, string zmianaDanych, char wybor);
    void wyswietlAdresata(Adresat adresat);
};

#endif

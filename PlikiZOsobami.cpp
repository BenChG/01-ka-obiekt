#include "PlikiZOsobami.h"

vector <Osoba> PlikiZOsobami::wczytajOsobyZPliku()
{
    vector <Osoba> osoby;
    Osoba osoba;

    string imie, nazwisko, numerTelefonu, email, adres;
    int id;

    string linia;
    int nr_linii = 1;
    int iloscOsob = 0;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);
    if (plik.good() == true)
    {
        while (getline(plik,linia))
        {
            switch (nr_linii)
            {
            case 1:
                id = atoi(linia.c_str());
                break;
            case 2:
                imie = linia;
                break;
            case 3:
                nazwisko = linia;
                break;
            case 4:
                numerTelefonu = linia;
                break;
            case 5:
                email = linia;
                break;
            case 6:
                adres = linia;
                break;
            }
            osoba.ustawId(id);
            osoba.ustawImie(imie);
            osoba.ustawNazwisko(nazwisko);
            osoba.ustawNumerTelefonu(numerTelefonu);
            osoba.ustawEmail(email);
            osoba.ustawAdres(adres);

            if (nr_linii >= 6)
            {
                osoby.push_back(osoba);
                nr_linii = 1;
            }
            else
            {
                nr_linii++;
            }
        }
        plik.close();
    }
    return osoby;
}

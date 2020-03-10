#ifndef OSOBA_H
#define OSOBA_H

#include <iostream>

using namespace std;

class Osoba
{
    int id;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

public:

    void ustawId(int noweId);
    void ustawImie (string noweNazwisko);
    void ustawNazwisko (string noweNazwisko);
    void ustawNumerTelefonu (string nowyNumerTelefonu);
    void ustawEmail(string nowyEmail);
    void ustawAdres (string nowyAdres);

    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzNumerTelefonu();
    string pobierzEmail();
    string pobierzAdres();

    Osoba (int=0, string imie="", string nazwisko="", string numerTelefonu="", string email="", string adres="")
    {
        this->id = id;
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->numerTelefonu = numerTelefonu;
        this->email = email;
        this->adres = adres;
    }
};

#endif

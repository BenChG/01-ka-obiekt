#include "Osoba.h"

void Osoba::ustawId(int noweId)
{
    if (noweId >= 0)
        id = noweId;
}
void Osoba::ustawImie (string noweImie)
{
    imie = noweImie;
}
void Osoba::ustawNazwisko (string noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Osoba::ustawNumerTelefonu (string nowyNumerTelefonu)
{
    numerTelefonu = nowyNumerTelefonu;
}

void Osoba::ustawEmail (string nowyEmail)
{
    email = nowyEmail;
}

void Osoba::ustawAdres(string nowyAdres)
{
    adres = nowyAdres;
}

int Osoba::pobierzId()
{
    return id;
}

string Osoba::pobierzImie()
{
    return imie;
}

string Osoba::pobierzNazwisko()
{
    return nazwisko;
}

string Osoba::pobierzNumerTelefonu()
{
    return numerTelefonu;
}

string Osoba::pobierzEmail()
{
    return email;
}

string Osoba::pobierzAdres()
{
    return adres;
}

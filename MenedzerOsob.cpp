#include "MenedzerOsob.h"

Osoba MenedzerOsob::dodajOsobe()
{
    Osoba osoba;
    MetodyPomocnicze metodyPomocnicze;
    string imie, nazwisko, numerTelefonu, email, adres;
    int id;
    cout << "Podaj imie: ";
    imie = metodyPomocnicze.wczytajLinie();
    cout << "Podaj nazwisko: ";
    nazwisko = metodyPomocnicze.wczytajLinie();
    cout << "Podaj numer telefonu: ";
    numerTelefonu = metodyPomocnicze.wczytajLinie();
    cout << "Podaj email: ";
    email = metodyPomocnicze.wczytajLinie();
    cout << "Podaj adres: ";
    adres = metodyPomocnicze.wczytajLinie();
    id = osoby.size()+1;

    osoba.ustawId(id);
    osoba.ustawImie(imie);
    osoba.ustawNazwisko(nazwisko);
    osoba.ustawNumerTelefonu(numerTelefonu);
    osoba.ustawEmail(email);
    osoba.ustawAdres(adres);

    osoby.push_back(osoba);

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << osoba.pobierzId() << endl;
        plik << osoba.pobierzImie() << endl;
        plik << osoba.pobierzNazwisko() << endl;
        plik << osoba.pobierzNumerTelefonu() << endl;
        plik << osoba.pobierzEmail() << endl;
        plik << osoba.pobierzAdres() << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    cout << endl << "Osoba zostala dodana" << endl;
    system("pause");

    cout << "Wielkosc wektora osoby: " << osoby.size() << endl;
    system("pause");

    return osoba;
}

void MenedzerOsob::wyswietlDaneAdresata(Osoba osoba)
{
    cout << "Id:         " << osoba.pobierzId() << endl;
    cout << "Imie:               " << osoba.pobierzImie() << endl;
    cout << "Nazwisko:           " << osoba.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << osoba.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << osoba.pobierzEmail() << endl;
    cout << "Adres:              " << osoba.pobierzAdres() << endl;
}

void MenedzerOsob::wyswietlWszystkieOsoby()
{
    system("cls");

    if (!osoby.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void MenedzerOsob::wyszukajPoImieniu()
{
    Osoba osoba;
    MetodyPomocnicze metodyPomocnicze;
    string czyZnalezionoImie="NIE";

    string podaneImie = metodyPomocnicze.podajImie();

    for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
    {
        if (wyswietlaniePoImieniu(*itr, podaneImie)=="TAK")
        {
            czyZnalezionoImie="TAK";
        }

    }
    if (czyZnalezionoImie!="TAK")
    {
        cout << "Brak osoby o podanym imieniu w ksiazce adresowej." << endl;
        system("pause");
    }
    else system("pause");
}

string MenedzerOsob::wyswietlaniePoImieniu (Osoba osoba, string podaneImie)
{
    if (osoba.pobierzImie() == podaneImie)
    {
        cout << endl;
        cout << "ID: " << osoba.pobierzId()<< endl;
        cout << osoba.pobierzImie() << " " << osoba.pobierzNazwisko() << endl;
        cout << "Telefon: " <<osoba.pobierzNumerTelefonu() << endl;
        cout << "Email: " << osoba.pobierzEmail() << endl;
        cout << "Adres: " << osoba.pobierzAdres() << endl;
        cout << endl;
        string czyZnalezionoImie = "TAK";
        return czyZnalezionoImie;
    }
    else
    {
        string czyZnalezionoNazwisko = "NIE";
        return czyZnalezionoNazwisko;
    }
}

void MenedzerOsob::wyszukajPoNazwisku()
{
    Osoba osoba;
    MetodyPomocnicze metodyPomocnicze;
    string czyZnalezionoNazwisko = "NIE";

    string podaneNazwisko = metodyPomocnicze.podajNazwisko();

    for (vector <Osoba> :: iterator itr = osoby.begin(); itr != osoby.end(); itr++)
    {
        if (wyswietlaniePoNazwisku(*itr, podaneNazwisko)=="TAK")
        {
            czyZnalezionoNazwisko="TAK";
        }
    }
    if (czyZnalezionoNazwisko!="TAK")
    {
        cout << "Brak osoby o podanym nazwisku w ksiazce adresowej." << endl;
        system("pause");
    }
    else system("pause");
}

string MenedzerOsob::wyswietlaniePoNazwisku(Osoba osoba, string podaneNazwisko)
{
    if (osoba.pobierzNazwisko() == podaneNazwisko)
    {
        cout << endl;
        cout << "ID: " << osoba.pobierzId()<< endl;
        cout << osoba.pobierzImie() << " " << osoba.pobierzNazwisko() << endl;
        cout << "Telefon: " <<osoba.pobierzNumerTelefonu() << endl;
        cout << "Email: " << osoba.pobierzEmail() << endl;
        cout << "Adres: " << osoba.pobierzAdres() << endl;
        cout << endl;
        string czyZnalezionoNazwisko = "TAK";
        return czyZnalezionoNazwisko;
    }
    else
    {
        string czyZnalezionoNazwisko = "NIE";
        return czyZnalezionoNazwisko;
    }
}

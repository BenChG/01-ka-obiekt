#include "MenedzerOsob.h"

Osoba MenedzerOsob::dodajOsobe()
{
    Osoba osoba;
    MetodyPomocnicze metodyPomocnicze;
    string imie, nazwisko, numerTelefonu, email, adres;
    int id=1;
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

    if (linieOsob.size()>=1)
    {
        int ostatniElement=linieOsob.size()-1;
        id=atoi(linieOsob[ostatniElement].c_str())+1;
    }


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
        plik << osoba.pobierzId();
        plik <<"|";
        plik << osoba.pobierzImie();
        plik <<"|";
        plik << osoba.pobierzNazwisko();
        plik <<"|";
        plik << osoba.pobierzNumerTelefonu();
        plik <<"|";
        plik << osoba.pobierzEmail();
        plik <<"|";
        plik << osoba.pobierzAdres();
        plik <<"|";
        plik <<endl;
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

    linieOsob=plikiZOsobami.wczytajLinieZPlikuDoWektora();
    return osoba;
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
    else
        system("pause");
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
    else
        system("pause");
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

void MenedzerOsob::wyswietlDaneAdresata(Osoba osoba)
{
    cout << "Id:         "         << osoba.pobierzId() << endl;
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
            cout<<endl;
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void MenedzerOsob::usunOsobe()
{
    system("cls");

    int ileOsob=linieOsob.size();

    if (!osoby.empty())
    {
        int osobaDoUsuniecia;
        char czyPotwierdzono;
        cout << "Podaj nr ID adresata, ktory ma zostac usuniety: " << endl;
        cin>>osobaDoUsuniecia;
        cout << "Nacisnij 't', aby potwierdzic usunecie adresata o nr ID: "<<osobaDoUsuniecia<<endl;
        cin>>czyPotwierdzono;
        if (czyPotwierdzono=='t')
        {
            fstream plik;
            plik.open("KsiazkaAdresowa.txt",ios::out);

            for (int i=0; i<=ileOsob-1; i++)
            {
                int id=atoi(linieOsob[i].c_str());

                if (id!=osobaDoUsuniecia)
                {
                    plik<<linieOsob[i]<<endl;
                }
                else
                {
                    cout << "Adresat o nr ID: " << osobaDoUsuniecia << " zostal usuniety." << endl<<endl;
                }
            }
            plik.close();

            osoby=plikiZOsobami.wczytajOsobyZPliku();
            linieOsob=plikiZOsobami.wczytajLinieZPlikuDoWektora();
        }

        else
        {
            cout << "Z powodu braku potwierdzenia adresat nie zostal usuniety."<<endl;
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

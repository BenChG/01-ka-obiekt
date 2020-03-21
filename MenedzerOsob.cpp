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
        plik << "|";
        plik << osoba.pobierzImie();
        plik << "|";
        plik << osoba.pobierzNazwisko();
        plik << "|";
        plik << osoba.pobierzNumerTelefonu();
        plik << "|";
        plik << osoba.pobierzEmail();
        plik << "|";
        plik << osoba.pobierzAdres();
        plik << "|";
        plik << endl;
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

    int ileOsob=linieOsob.size()-1;

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

            for (int i=0; i<=ileOsob; i++)
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


string MenedzerOsob::edycjaDanych(Osoba osoba, string linia, string zmianaDanych, char wybor)
{
    int dlugoscLinii=linia.length();

    string id;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;
    int ostatniZnak[6];
    string nowyWyraz;
    int k=0, start=0;

    for (int i=0; i<dlugoscLinii; i++)
    {
        if(linia[i]==124)
        {
            ostatniZnak[k]=i;
            k++;
        }
    }
    nowyWyraz=linia.substr(start,ostatniZnak[0]-start);
    id=nowyWyraz;
    start=ostatniZnak[0]+1;

    nowyWyraz=linia.substr(start,ostatniZnak[1]-start);
    imie=nowyWyraz;
    start=ostatniZnak[1]+1;

    nowyWyraz=linia.substr(start,ostatniZnak[2]-start);
    nazwisko=nowyWyraz;
    start=ostatniZnak[2]+1;

    nowyWyraz=linia.substr(start,ostatniZnak[3]-start);
    numerTelefonu=nowyWyraz;
    start=ostatniZnak[3]+1;

    nowyWyraz=linia.substr(start,ostatniZnak[4]-start);
    email=nowyWyraz;
    start=ostatniZnak[4]+1;

    nowyWyraz=linia.substr(start,ostatniZnak[5]-start);
    adres=nowyWyraz;

    if (wybor == '1')
    {
        imie=zmianaDanych;
    }
    else if (wybor == '2')
    {
        nazwisko=zmianaDanych;
    }
    else if (wybor == '3')
    {
        numerTelefonu=zmianaDanych;
    }
    else if (wybor == '4')
    {
        email=zmianaDanych;
    }
    else if (wybor == '5')
    {
        adres=zmianaDanych;
    }

    linia=id+"|"+imie+"|"+nazwisko+"|"+numerTelefonu+"|"+email+"|"+adres+"|";
    return linia;
}

void MenedzerOsob::edytujOsobe()
{
    Osoba osoba;
    int ileOsob=linieOsob.size()-1;
    char wybor;
    int osobaDoEdycji;
    string zmianaDanych="";
    string czyZnaleziono="NIE";

    cout << "Podaj ID osoby, ktorej dane chcesz edytowac: " << endl;
    cin >> osobaDoEdycji;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out);

    for (int itr = 0; itr <= ileOsob; itr++)
    {
        int id=atoi(linieOsob[itr].c_str());
        if (id==osobaDoEdycji)
        {
            cout << "Wybierz z Menu dana, ktora chcesz edytowac: " << endl << endl;

            cout << "--------------Edycja Osoby----------------" << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Numer telefonu." << endl;
            cout << "4. E-mail." << endl;
            cout << "5. Adres." << endl;
            cout << "6. Powrot do menu" << endl;
            cout <<"-----------------------------------------"<< endl;
            cin >> wybor;

              if (wybor == '6')
            {
                exit (0);
            }

            else
            {
            cout << "Podaj nowa tresc wybranej danej: " << endl;
            cin >> zmianaDanych;

            string trescDoEdycji=linieOsob[itr];

            plik << edycjaDanych(osoba, trescDoEdycji, zmianaDanych, wybor) << endl;

            czyZnaleziono="TAK";
            }
        }
        else
        {
            plik << linieOsob[itr] << endl;
        }
    }
    plik.close();

    if (czyZnaleziono=="TAK")
    {
        cout << "Dane osoby o ID nr: " << osobaDoEdycji << " zostaly zmienione." << endl;
        system("pause");
    }
    else
    {
        cout << "Brak osoby w ksiazce adresowej o nr ID: " << osobaDoEdycji << endl;
        system("pause");
    }

    osoby=plikiZOsobami.wczytajOsobyZPliku();
    linieOsob=plikiZOsobami.wczytajLinieZPlikuDoWektora();
}

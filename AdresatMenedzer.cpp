#include "AdresatMenedzer.h"

Adresat AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;
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

    if (linieAdresatow.size()>=1)
    {
        int ostatniElement=linieAdresatow.size()-1;
        id=atoi(linieAdresatow[ostatniElement].c_str())+1;
    }


    adresat.ustawId(id);
    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    adresaci.push_back(adresat);

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::out | ios::app);

    if (plik.good() == true)
    {
        plik << adresat.pobierzId();
        plik << "|";
        plik << adresat.pobierzImie();
        plik << "|";
        plik << adresat.pobierzNazwisko();
        plik << "|";
        plik << adresat.pobierzNumerTelefonu();
        plik << "|";
        plik << adresat.pobierzEmail();
        plik << "|";
        plik << adresat.pobierzAdres();
        plik << "|";
        plik << endl;
        plik.close();
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
    cout << endl << "Adresat zostal dodany." << endl;
    system("pause");

    cout << "Wielkosc wektora adresaci: " << adresaci.size() << endl;
    system("pause");

    linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    return adresat;
}

void AdresatMenedzer::wyszukajPoImieniu()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;
    string czyZnalezionoImie="NIE";

    string podaneImie = metodyPomocnicze.podajImie();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoImieniu(*itr, podaneImie)=="TAK")
        {
            czyZnalezionoImie="TAK";
        }

    }
    if (czyZnalezionoImie!="TAK")
    {
        cout << "Brak adresata o podanym imieniu w ksiazce adresowej." << endl;
        system("pause");
    }
    else
        system("pause");
}

string AdresatMenedzer::wyswietlaniePoImieniu (Adresat adresat, string podaneImie)
{
    if (adresat.pobierzImie() == podaneImie)
    {
        cout << endl;
        cout << "ID: " << adresat.pobierzId()<< endl;
        cout << adresat.pobierzImie() << " " << adresat.pobierzNazwisko() << endl;
        cout << "Telefon: " <<adresat.pobierzNumerTelefonu() << endl;
        cout << "Email: " << adresat.pobierzEmail() << endl;
        cout << "Adres: " << adresat.pobierzAdres() << endl;
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

void AdresatMenedzer::wyszukajPoNazwisku()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;
    string czyZnalezionoNazwisko = "NIE";

    string podaneNazwisko = metodyPomocnicze.podajNazwisko();

    for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (wyswietlaniePoNazwisku(*itr, podaneNazwisko)=="TAK")
        {
            czyZnalezionoNazwisko="TAK";
        }
    }
    if (czyZnalezionoNazwisko!="TAK")
    {
        cout << "Brak adresata o podanym nazwisku w ksiazce adresowej." << endl;
        system("pause");
    }
    else
        system("pause");
}

string AdresatMenedzer::wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko)
{
    if (adresat.pobierzNazwisko() == podaneNazwisko)
    {
        cout << endl;
        cout << "ID: " << adresat.pobierzId()<< endl;
        cout << adresat.pobierzImie() << " " << adresat.pobierzNazwisko() << endl;
        cout << "Telefon: " <<adresat.pobierzNumerTelefonu() << endl;
        cout << "Email: " << adresat.pobierzEmail() << endl;
        cout << "Adres: " << adresat.pobierzAdres() << endl;
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

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << "Id:         "         << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");

    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
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

void AdresatMenedzer::usunAdresata()
{
    system("cls");

    int ileAdresatow=linieAdresatow.size()-1;

    if (!adresaci.empty())
    {
        int adresatDoUsuniecia;
        char czyPotwierdzono;
        cout << "Podaj nr ID adresata, ktory ma zostac usuniety: " << endl;
        cin>>adresatDoUsuniecia;
        cout << "Nacisnij 't', aby potwierdzic usunecie adresata o nr ID: "<<adresatDoUsuniecia<<endl;
        cin>>czyPotwierdzono;
        if (czyPotwierdzono=='t')
        {
            fstream plik;
            plik.open("KsiazkaAdresowa.txt",ios::out);

            for (int i=0; i<=ileAdresatow; i++)
            {
                int id=atoi(linieAdresatow[i].c_str());

                if (id!=adresatDoUsuniecia)
                {
                    plik<<linieAdresatow[i]<<endl;
                }
                else
                {
                    cout << "Adresat o nr ID: " << adresatDoUsuniecia << " zostal usuniety." << endl<<endl;
                }
            }
            plik.close();

            adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
            linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
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


string AdresatMenedzer::edycjaDanych(Adresat adresat, string linia, string zmianaDanych, char wybor)
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

void AdresatMenedzer::edytujAdresata()
{
    Adresat adresat;
    int ileAdresatow=linieAdresatow.size()-1;
    char wybor;
    int adresatDoEdycji;
    string zmianaDanych="";
    string czyZnaleziono="NIE";

    cout << "Podaj ID adresata, ktorej dane chcesz edytowac: " << endl;
    cin >> adresatDoEdycji;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt", ios::out);

    for (int itr = 0; itr <= ileAdresatow; itr++)
    {
        int id=atoi(linieAdresatow[itr].c_str());
        if (id==adresatDoEdycji)
        {
            cout << "Wybierz z Menu dana, ktora chcesz edytowac: " << endl << endl;

            cout << "--------------Edycja Adresata----------------" << endl;
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

            string trescDoEdycji=linieAdresatow[itr];

            plik << edycjaDanych(adresat, trescDoEdycji, zmianaDanych, wybor) << endl;

            czyZnaleziono="TAK";
            }
        }
        else
        {
            plik << linieAdresatow[itr] << endl;
        }
    }
    plik.close();

    if (czyZnaleziono=="TAK")
    {
        cout << "Dane adresata o ID nr: " << adresatDoEdycji << " zostaly zmienione." << endl;
        system("pause");
    }
    else
    {
        cout << "Brak adresata w ksiazce adresowej o nr ID: " << adresatDoEdycji << endl;
        system("pause");
    }

    adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
    linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
}

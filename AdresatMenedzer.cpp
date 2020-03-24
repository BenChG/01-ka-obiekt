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

    cout << endl << "Adresat zostal dodany." << endl;
    cout << "Wielkosc wektora adresaci: " << adresaci.size() << endl << endl;
    }

    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl << endl;
    }

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
    if (czyZnalezionoImie=="NIE")
    {
        cout << "Brak adresata o podanym imieniu w ksiazce adresowej." << endl << endl;
    }
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

    if (czyZnalezionoNazwisko=="NIE")
    {
        cout << "Brak adresata o podanym nazwisku w ksiazce adresowej." << endl << endl;
    }
        system("pause");
}

string AdresatMenedzer::wyswietlaniePoNazwisku(Adresat adresat, string podaneNazwisko)
{
    if (adresat.pobierzNazwisko() == podaneNazwisko)
    {
        cout << endl;
        cout << "ID: " << adresat.pobierzId()<< endl;
        cout << adresat.pobierzImie() << " " << adresat.pobierzNazwisko() << endl;
        cout << "Telefon: " << adresat.pobierzNumerTelefonu() << endl;
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
            cout << endl;
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

    int liczbaAdresatow=linieAdresatow.size()-1;

    int adresatDoUsuniecia;
    char czyPotwierdzono;
    string czyZnalezionoAdresata="NIE";

    cout << "Podaj nr ID adresata, ktory ma zostac usuniety: " << endl;
    cin >> adresatDoUsuniecia;

    cout << "Nacisnij 't', aby potwierdzic usunecie adresata o nr ID: " << adresatDoUsuniecia << endl;
    cin >> czyPotwierdzono;

    if (czyPotwierdzono=='t')
    {
        fstream plik;
        plik.open("KsiazkaAdresowa.txt",ios::out);

        if (plik.good() == true)
        {

            for (int i=0; i<=liczbaAdresatow; i++)

            {
                int id=atoi(linieAdresatow[i].c_str());

                if (id!=adresatDoUsuniecia)
                {
                    plik << linieAdresatow[i] << endl;
                }

                else
                {
                    czyZnalezionoAdresata="TAK";
                }
            }
            plik.close();
        }

        if (czyZnalezionoAdresata=="TAK")
        {
            cout << "Adresat o ID nr: " << adresatDoUsuniecia << " zostal usuniety." << endl << endl;
        }

        else
        {
            cout << "Brak adresata o nr ID: " << adresatDoUsuniecia << " w ksiazce adresowej." << endl << endl;
        }

        adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
        linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
    }

    else
    {
        cout << "Z powodu braku potwierdzenia adresat nie zostal usuniety." << endl << endl;
    }

    system("pause");
}

string AdresatMenedzer::edytujAdresata(Adresat adresat, string linia, string zmianaDanych, char wybor)
{
    int dlugoscLinii=linia.length();
    int ostatniZnak[6];
    int k=0;
    int pierwszyZnak=0;

    string id;
    string imie;
    string nazwisko;
    string numerTelefonu;
    string email;
    string adres;

    string nowyWyraz;

    for (int znak=0; znak<dlugoscLinii; znak++)
    {
        if(linia[znak]==124)
        {
            ostatniZnak[k]=znak;
            k++;
        }
    }
    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
    id=nowyWyraz;
    pierwszyZnak=ostatniZnak[0]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[1]-pierwszyZnak);
    imie=nowyWyraz;
    pierwszyZnak=ostatniZnak[1]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[2]-pierwszyZnak);
    nazwisko=nowyWyraz;
    pierwszyZnak=ostatniZnak[2]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[3]-pierwszyZnak);
    numerTelefonu=nowyWyraz;
    pierwszyZnak=ostatniZnak[3]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[4]-pierwszyZnak);
    email=nowyWyraz;
    pierwszyZnak=ostatniZnak[4]+1;

    nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[5]-pierwszyZnak);
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

void AdresatMenedzer::wyszukajAdresataDoEdycji()
{
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;

    if (!adresaci.empty())
    {
        int ileAdresatow=linieAdresatow.size()-1;
        int adresatDoEdycji;
        char wybor;
        string zmianaDanych="";
        string czyZnalezionoAdresata="NIE";

        cout << "Podaj ID adresata, ktorej dane chcesz edytowac: " << endl;
        cin >> adresatDoEdycji;

        fstream plik;
        plik.open("KsiazkaAdresowa.txt", ios::out);

        if (plik.good() == true)
        {
            for (int itr = 0; itr <= ileAdresatow; itr++)
            {
                int id=atoi(linieAdresatow[itr].c_str());
                if (id==adresatDoEdycji)
                {
                    wybor=metodyPomocnicze.wybierzDanaDoEdycji();

                    if (wybor == '6')
                    {
                        exit (0);
                    }

                    else
                    {
                        cout << "Podaj nowa tresc wybranej danej: " << endl;
                        cin >> zmianaDanych;

                        string trescDoEdycji=linieAdresatow[itr];

                        plik << edytujAdresata(adresat, trescDoEdycji, zmianaDanych, wybor) << endl;

                        czyZnalezionoAdresata="TAK";
                    }
                }

                else
                {
                    plik << linieAdresatow[itr] << endl;
                }
            }
            plik.close();

            if (czyZnalezionoAdresata=="TAK")
            {
                cout << "Dane adresata o ID nr: " << adresatDoEdycji << " zostaly zmienione." << endl << endl;
            }

            else
            {
                cout << "Brak adresata o nr ID: " << adresatDoEdycji << " w ksiazce adresowej." << endl << endl;
            }
            system("pause");

            adresaci=plikiZAdresatami.wczytajAdresatowZPliku();
            linieAdresatow=plikiZAdresatami.wczytajLinieZPlikuDoWektora();
        }
    }

    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
}

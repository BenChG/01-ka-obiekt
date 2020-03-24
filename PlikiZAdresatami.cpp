#include "PlikiZAdresatami.h"

vector <Adresat> PlikiZAdresatami::wczytajAdresatowZPliku()
{
    vector <Adresat> adresaci;
    Adresat adresat;
    adresaci.clear();

    string imie, nazwisko, numerTelefonu, email, adres;
    int id;
    int ostatniZnak[6];
    string nowyWyraz;
    string linia;

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);

    if (plik.good() == true)
    {
        while(getline(plik,linia))
        {
            int k=0, pierwszyZnak=0, dlugoscLinii=linia.length();

            for (int i=0; i<dlugoscLinii; i++)
            {
                if(linia[i]==124)
                {
                    ostatniZnak[k]=i;
                    k++;
                }
            }

            nowyWyraz=linia.substr(pierwszyZnak,ostatniZnak[0]-pierwszyZnak);
            id=atoi(linia.c_str());
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

            adresat.ustawId(id);
            adresat.ustawImie(imie);
            adresat.ustawNazwisko(nazwisko);
            adresat.ustawNumerTelefonu(numerTelefonu);
            adresat.ustawEmail(email);
            adresat.ustawAdres(adres);

            adresaci.push_back(adresat);
        }
        plik.close();
    }
    return adresaci;
}

vector <string> PlikiZAdresatami::wczytajLinieZPlikuDoWektora ()
{
    vector <string> linieAdresatow;
    string linia;
    linieAdresatow.clear();

    fstream plik;
    plik.open("KsiazkaAdresowa.txt",ios::in);

    if (plik.good()==true)
    {
        while(getline(plik,linia))
        {
            linieAdresatow.push_back(linia);
        }
        plik.close();
    }

    return linieAdresatow;
}

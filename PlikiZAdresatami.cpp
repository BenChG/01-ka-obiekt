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
        int k=0, start=0, dlugoscLinii=linia.length();

        for (int i=0; i<dlugoscLinii; i++)
        {
            if(linia[i]==124)
            {
                ostatniZnak[k]=i;
                k++;
            }
        }

        nowyWyraz=linia.substr(start,ostatniZnak[0]-start);
        id=atoi(linia.c_str());
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
    fstream plik;
    linieAdresatow.clear();

    plik.open("KsiazkaAdresowa.txt",ios::in);

    if (plik.good()==false)
    {
        ofstream plik("KsiazkaAdresowa.txt");
        plik.open("KsiazkaAdresowa.txt",ios::in);
    }

    while(getline(plik,linia))
    {
        linieAdresatow.push_back(linia);
    }
    plik.close();

    return linieAdresatow;
}
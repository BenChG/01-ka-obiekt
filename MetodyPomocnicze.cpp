#include "MetodyPomocnicze.h"

char MetodyPomocnicze::wybierzOpcjeZMenuGlownego()
{
    char wybor;
    AdresatMenedzer adresatMenedzer;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl wszystkich adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "9. Zakoncz program" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = wczytajZnak();
    return wybor;
}

char MetodyPomocnicze::wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
    }
    return znak;
}

string MetodyPomocnicze::wczytajLinie()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string MetodyPomocnicze::podajImie()
{
    string imie;
    cout << "Podaj imie adresata, ktorego chcesz wyszukac: ";
    imie = wczytajLinie();
    return imie;
}

string MetodyPomocnicze::podajNazwisko()
{
    string nazwisko;
    cout << "Podaj nazwisko adresata, ktorego chcesz wyszukac: ";
    nazwisko = wczytajLinie();
    return nazwisko;
}

char MetodyPomocnicze::wybierzDanaDoEdycji()
{
    char wybor;

    cout << "Wybierz z Menu dana, ktora chcesz edytowac: " << endl << endl;

    system("cls");
    cout << "--------------Edycja Adresata----------------" << endl;
    cout << "1. Imie." << endl;
    cout << "2. Nazwisko." << endl;
    cout << "3. Numer telefonu." << endl;
    cout << "4. E-mail." << endl;
    cout << "5. Adres." << endl;
    cout << "6. Powrot do menu." << endl;
    cout <<"-----------------------------------------"<< endl;
    cout << "Twoj wybor: ";

    wybor = wczytajZnak();
    return wybor;
}

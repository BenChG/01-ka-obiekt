#include "MetodyPomocnicze.h"

char MetodyPomocnicze::wybierzOpcjeZMenuGlownego()
{
    char wybor;
    MenedzerOsob menedzerOsob;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj osobe" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl wszystkie osoby" << endl;
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
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
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
    cout << "Podaj imie osoby jaka mamy wyszukac: ";
    imie = wczytajLinie();
    return imie;
}

string MetodyPomocnicze::podajNazwisko()
{
    string nazwisko;
    cout << "Podaj nazwisko osoby jaka mamy wyszukac: ";
    nazwisko = wczytajLinie();
    return nazwisko;
}

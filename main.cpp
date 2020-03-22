#include "MetodyPomocnicze.h"
#include "AdresatMenedzer.h"

using namespace std;

int main()
{
    MetodyPomocnicze metodyPomocnicze;
    AdresatMenedzer adresatMenedzer;

    char wybor;
    while (true)
    {
        wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

        switch (wybor)
        {
        case '1':
            adresatMenedzer.dodajAdresata();
            break;
        case '2':
            adresatMenedzer.wyszukajPoImieniu();
            break;
        case '3':
            adresatMenedzer.wyszukajPoNazwisku();
            break;
        case '4':
            adresatMenedzer.wyswietlWszystkichAdresatow();
            break;
        case '5':
            adresatMenedzer.usunAdresata();
            break;
        case '6':
            adresatMenedzer.edytujAdresata();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    }
    return 0;
}

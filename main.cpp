#include "MetodyPomocnicze.h"
#include "MenedzerOsob.h"

using namespace std;

int main()
{
    MetodyPomocnicze metodyPomocnicze;
    MenedzerOsob menedzerOsob;

    char wybor;
    while (true)
    {
        wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

        switch (wybor)
        {
        case '1':
            menedzerOsob.dodajOsobe();
            break;
        case '2':
            menedzerOsob.wyszukajPoImieniu();
            break;
        case '3':
            menedzerOsob.wyszukajPoNazwisku();
            break;
        case '4':
            menedzerOsob.wyswietlWszystkieOsoby();
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

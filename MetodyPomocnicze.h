#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include "MenedzerOsob.h"

using namespace std;

class MetodyPomocnicze
{
    char wczytajZnak();

public:
    char wybierzOpcjeZMenuGlownego();
    string wczytajLinie();
    string podajImie();
    string podajNazwisko();
};

#endif

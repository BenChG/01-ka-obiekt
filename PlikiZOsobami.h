#ifndef PLIKIZOSOBAMI_H
#define PLIKIZOSOBAMI_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Osoba.h"

using namespace std;

class PlikiZOsobami
{
    vector <Osoba> osoby;
    Osoba osoba;

public:
    vector <Osoba> wczytajOsobyZPliku();
};

#endif

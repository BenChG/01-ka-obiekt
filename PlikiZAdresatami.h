#ifndef PLIKIZADRESATAMI_H
#define PLIKIZADRESATAMI_H

#include <fstream>
#include <vector>
#include <stdlib.h>
#include "Adresat.h"

using namespace std;

class PlikiZAdresatami
{
    vector <Adresat> adresaci;
    vector <string> linieAdresatow;
    Adresat adresat;

public:
    vector <Adresat> wczytajAdresatowZPliku();
    vector <string> wczytajLinieZPlikuDoWektora();
};

#endif

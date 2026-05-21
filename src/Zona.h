#ifndef ZONA_H
#define ZONA_H

#include <vector>
#include <string>
#include "ElementoInteractivo.h"

using namespace std;

class Zona {
private:
    
    string nombre;
    vector <ElementoInteractivo*> elementos;
    
public:
    Zona(string nombre)
    void agragarElemento(ElememtoInteractivo* elemento);
    }
};

#endif

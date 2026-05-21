#ifndef ELELMENTOINTERACTIVO_H
#define ELELMENTOINTERACTIVO_H

#include <unordered_map>
#include <string>
#include "Zona.h"

using namespace std;

class Explorador;

class ElementoInteractivos {
    public:
        virtual void interactuar(Explorador* explorador = 0);
    virtual ~ElementosInteractivo (){}
    }
};

#endif

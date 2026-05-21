#ifndef ELELMENTOINTERACTIVO_H
#define ELELMENTOINTERACTIVO_H

#include <unoerdered_map>
#include <string>
#include "Zona.h"

using namespace std;

class Explorador;

class ElementosInteractivos {
    public:
        virtual void interactuar(Explorador* explorador = 0);
    virtual ~ElementosInteractivo (){}
    }
};

#endif

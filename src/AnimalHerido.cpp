#ifndef ANIMALHERIDO_H
#define ANIMALHERIDO_H

#include "ElementoInteractivo.h"

using namespace std;

class AnimalHerido : public ElementoInteractivo {
    
public:
    void interactuar(Explorador* explorador) override;
};

#endif


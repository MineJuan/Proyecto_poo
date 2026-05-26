#ifndef PLANTAMEDICINAL_H
#define PLANTAMEDICINAL_H

#include "ElementoInteractivo.h"

class PlantaMedicinal : public ElementoInteractivo{
    public:
        PlantaMedicinal();
        void interactuar(Explorador* explorador)override;
};


#endif

#ifndef PORTALRUTA_H
#define PORTALRUTA_H
#include "ElementoInteractivo.h"
#include "Zona.h"

class PortalRuta : public ElementoInteractivo{
    private:
        Zona* destino;

    public:
        PortalRuta(Zona* destino);
        void interactuar(Explorador* explorador) override;
};


#endif

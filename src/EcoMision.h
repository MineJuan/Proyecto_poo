#ifndef ECOMISION_H
#define ECOMISION_H

#include "Reserva.h"
#include "Explorador.h"
#include "Zona.h"

using namespace std;

class EcoMision {
private:

    Reserva* reserva;
    Explorador* explorador;

public:
    EcoMision();
    void iniciar();
    void mostrarRecorrido();
    void ejecutarInteracciones();
};

#endif

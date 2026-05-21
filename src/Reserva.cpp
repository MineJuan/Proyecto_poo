#include "Reserva.h"
#include <iostream>

using namespace std;

Reserva::Reserva() { }

void Reserva::agregarZona(string codigo, Zona *zona) {
    zonas[codigo] = zona;
};

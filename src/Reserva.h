#ifndef RESERVA_H
#define RESERVA_H

#include <unordered_map>
#include <string>
#include "Zona.h"

using namespace std;

class Reserva {
private:
    
    unordered_map <string, Zona*> zonas;
    
public:
    Reserva();
    void agregarZona(string codigo, Zona* zona);
    void mostrarZonas();
};

#endif

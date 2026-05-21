#ifndef RESERVA_H
#define RESERVA_H

#include <unoerdered_map>
#include <string>
#include "Zona.h"

using namespace std;

class Reserva {
private:
    
    unordered_map <string, Zona*> zonas;
    
public:
    Reserva()
    void agragarZona(strnig codigo, Zona* zona);
    }
};

#endif

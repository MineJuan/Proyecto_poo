#ifndef EXPLORADOR_H
#define EXPLORADOR_H

#include <string>
#include "Zona.h"

using namespace std;

class Explorador {
private:
    
    string nombre;
    int energia;
    int puntajeAmbiental;
    Zona* zonaActual;
    
public:
    Explorador(string nombre)
    void cambiarZona(Zona* nuevaZona);
    }
};

#endif


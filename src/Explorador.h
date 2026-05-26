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
    Explorador(string nombre);
    void cambiarZona(Zona* nuevaZona);
    void modificarEnergia(int valor);
    void aumentarPuntaje(int puntos);
    string getNombre();
    int getEnergia();
    int getPuntajeAmbiental();
    Zona* getZonaActual();
 };


#endif

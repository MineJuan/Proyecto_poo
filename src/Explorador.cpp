#include "Explorador.h"
#include <iostream>

using namespace std;

Explorador::Explorador (string nombre){
    this -> nombre = nombre;
    energia = 100;
    puntajeAmbiental = 0;
    zonaActual = nullptr;
};

void Explorador::cambiarZona(Zona* nuevaZona){
    zonaActual = nuevaZona;
};


#ifndef ZONA_H
#define ZONA_H

#include <vector>
#include <string>
#include "ElementoInteractivo.h"

using namespace std;
class Explorador;
class Zona {
private:

    string nombre;
    vector <ElementoInteractivo*> elementos;

public:
    Zona(string nombre);
    void agregarElemento(ElementoInteractivo* elemento);
    void mostrarElementos();
    void interactuarConElemento(int indice, Explorador* explorador);
    void interactuarConElemento(string nombre, Explorador* explorador);
    string getNombre();
};


#endif


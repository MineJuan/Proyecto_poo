#include "zona.h"
#include <iostream>

using namespace std;

Zona::Zona(string nombre) {
  this->nombre = nombre;
}

void Zona::agregarElemento(ElementoInteractivo* elemento){
    elementos.push_back(elemento);
}

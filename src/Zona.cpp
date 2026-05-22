#include "zona.h"
#include <iostream>

using namespace std;

Zona::Zona(string nombre) {
  this->nombre = nombre;
}

string Zona::getNombre(){
    return nombre;
}

void Zona::agregarElemento(ElementoInteractivo* elemento){
    elementos.push_back(elemento);
}

void Zona::mostrarElementos(){
    for (int i = 0; i < elementos.size(); i++){
        cout << "Elemento " << i + 1 << "." << elementos[i]->getNombre() << endl;
    }
}

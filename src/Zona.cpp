#include "Explorador.h"
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
        cout << "Elemento " << i + 1 << ". " << elementos[i]->getNombre() << endl;
    }
}
void Zona::interactuarConElemento(int indice, Explorador* explorador) {

    elementos[indice]->interactuar(explorador);
}
void Zona::interactuarConElemento(string nombre, Explorador* explorador) {

    for(int i = 0; i < elementos.size(); i++) {
        if(elementos[i]->getNombre() == nombre) {
            elementos[i]->interactuar(explorador);
        }
    }
}

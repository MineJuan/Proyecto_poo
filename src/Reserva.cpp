#include "Reserva.h"
#include "Zona.h"
#include <iostream>

using namespace std;

Reserva::Reserva() { }

void Reserva::agregarZona(string codigo, Zona *zona) {
    zonas[codigo] = zona;
};
Zona* Reserva::buscarZona(string codigoZona){
    return zonas[codigoZona];
}
void Reserva::mostrarZonas(){
    for(auto zona : zonas){
        cout << zona.first << endl;
    }
}

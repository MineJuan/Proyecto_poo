#include "Ecomision.h"
#include <iostream>

using namespace std;

EcoMision::EcoMision() {
    reserva = new Reserva();
    explorador = new Explorador("Juan");
}

void EcoMision::iniciar(){
    Zona* pantano = new Zona("Pantano");
    explorador->cambiarZona(pantano);
    cout << "Ecomision iniciada" << endl;

    mostrarRecorrido();
};

void EcoMision::mostrarRecorrido(){
    cout << "-- Iniciar Recorrido --" << endl;
    cout << "Explorador: " << explorador->getNombre() << endl;
    cout << "Energia: " << explorador->getEnergia() << endl;
    cout << "Puntaje Ambiental: " << explorador->getPuntajeAmbiental() << endl;
    cout << "Zona Actual: " << explorador->getZonaActual()->getNombre() << endl;
    cout << "Elementos Disponibles: " << endl;
    explorador -> getZonaActual() -> mostrarElementos();
};

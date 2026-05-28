#include "EcoMision.h"
#include "AnimalHerido.h"
#include "PlantaMedicinal.h"
#include "PortalRuta.h"
#include <iostream>

using namespace std;

EcoMision::EcoMision() {
    reserva = new Reserva();
    explorador = new Explorador("Juan");
}

void EcoMision::iniciar() {

    //creamos zonas
    Zona* pantano = new Zona("Pantano");
    Zona* bosque = new Zona("Bosque");

    //registramos las zonas en la reserva

    reserva->agregarZona("pantano", pantano);
    reserva->agregarZona("bosque", bosque);

    //agregamos los elementos al pantano

    pantano->agregarElemento(new AnimalHerido());

    pantano->agregarElemento(new PlantaMedicinal());

    pantano->agregarElemento(new PortalRuta(bosque));

    //agregamos los elementos al bosque
    bosque->agregarElemento(new PlantaMedicinal());

    //ubicamos al explorador

    explorador->cambiarZona(pantano);
    
    //iniciamos la mision
    cout << "EcoMision iniciada: " << endl;

    cout << endl;

    //mostramos el estado inicial de todo
    mostrarRecorrido();

    cout << endl;

    //aqui se realizan las interacciones
    cout << "Interacciones:" << endl;

    explorador->getZonaActual() ->interactuarConElemento(0, explorador); //interactuamos con el animal herido
    explorador->getZonaActual() ->interactuarConElemento(1, explorador); //interactuamos con la planta medicinal
    explorador->getZonaActual() ->interactuarConElemento(2, explorador); //interactuamos con el portal de ruta

    cout << endl;

    //mostramos estado final
    mostrarRecorrido();
}

void EcoMision::mostrarRecorrido(){
    cout << "Recorrido hecho: " << endl;
    cout << "Explorador: " << explorador->getNombre() << endl;
    cout << "Energia: " << explorador->getEnergia() << endl;
    cout << "Puntaje Ambiental: " << explorador->getPuntajeAmbiental() << endl;
    cout << "Zona Actual: " << explorador->getZonaActual()->getNombre() << endl;
    cout << "Elementos Disponibles: " << endl;
    explorador -> getZonaActual() -> mostrarElementos();
};

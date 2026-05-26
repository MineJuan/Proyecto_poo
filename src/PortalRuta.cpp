#include "PortalRuta.h"
#include "ElementoInteractivo.h"
#include "Explorador.h"

#include <iostream>

using namespace std;

PortalRuta::PortalRuta(Zona* destino):ElementoInteractivo("Portal de Ruta"){
    this ->destino = destino;
}

void PortalRuta::interactuar(Explorador* explorador){
    cout << "Cambiaste de zona" << endl;
    explorador -> cambiarZona(destino);
}


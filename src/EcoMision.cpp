#include "Ecomision.h"
#include <iostream>

using namespace std;

EcoMision::EcoMision(){
    reserva = new Reserva();
    explorador = new Explorador("Juan");
};

void Ecomision::iniciar(){
    Zona* pantano = new Zona("Pantano");
    explorador->CambiarZona(pantano);
    cout << "Ecomision iniciada" << endl;
};

#include "AnimalHerido.h"
#include "ElementoInteractivo.h"
#include "Explorador.h"

#include <iostream>

using namespace std;

AnimalHerido::AnimalHerido():ElementoInteractivo("Animal Herido"){

}

void AnimalHerido::interactuar(Explorador* explorador){
    cout << "Ayudaste a un animal herido" << endl;
    explorador ->aumentarPuntaje(20);
    explorador ->modificarEnergia(-10);
}

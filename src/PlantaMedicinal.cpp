#include "PlantaMedicinal.h"
#include "AnimalHerido.h"
#include "ElementoInteractivo.h"
#include "Explorador.h"

#include <iostream>

using namespace std;

PlantaMedicinal::PlantaMedicinal(): ElementoInteractivo("Planta Medicinal"){


}

void PlantaMedicinal::interactuar(Explorador* explorador){
    cout << "Has recogido una planta medicinal." << endl;
    explorador ->modificarEnergia(20);
}


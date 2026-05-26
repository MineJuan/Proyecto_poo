#ifndef ELELMENTOINTERACTIVO_H
#define ELELMENTOINTERACTIVO_H

#include <unordered_map>
#include <string>

using namespace std;

class Explorador;

class ElementoInteractivo{
    protected:
        string nombre;
    public:
        ElementoInteractivo(string nombre);
        virtual void interactuar(Explorador* explorador) = 0;
        virtual ~ElementoInteractivo (){};
        string getNombre();
};


#endif

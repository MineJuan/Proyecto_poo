#include "Explorador.h"
#include <iostream>

using namespace std;

Explorador::Explorador (string nombre){
    this -> nombre = nombre;
    energia = 100;
    puntajeAmbiental = 0;
    zonaActual = nullptr;
};


void Explorador::cambiarZona(Zona* nuevaZona){
    zonaActual = nuevaZona;
}
string Explorador::getNombre(){
    return nombre;
}
int Explorador::getEnergia(){
    return energia;
}
int Explorador::getPuntajeAmbiental(){
    return puntajeAmbiental;
}
Zona* Explorador::getZonaActual(){
    return zonaActual;
}
void Explorador::modificarEnergia(int valor){
    energia+=valor;
}
void Explorador::aumentarPuntaje(int puntos){
    puntajeAmbiental+=puntos;
}



#include <iostream>
#include <cstring>
#include <string>


#include "Vehiculo.h"
using namespace std;


// Setter para _patente
void Vehiculo::setPatente(const char* patente) {
    strcpy(_patente, patente);

}

// Setter para _tipoVehiculo
void Vehiculo::setTipo(int tipoVehiculo) {
    _tipoVehiculo = tipoVehiculo;
}

// Getter para _patente
const char* Vehiculo::getPatente() const {
    return _patente;
}

// Getter para _tipoVehiculo
int Vehiculo::getTipo() const {
    return _tipoVehiculo;
}


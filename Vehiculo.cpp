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



void Vehiculo :: setFechaHoraIngreso(std::time_t fechaHora) {
        _fechaHoraIngreso = fechaHora;
    }

std::time_t Vehiculo:: getFechaHoraIngreso() const {
        return _fechaHoraIngreso;
    }


 std::string Vehiculo::getFechaHoraIngresoFormato() const {
        char buffer[30];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&_fechaHoraIngreso));
        return std::string(buffer);
    }


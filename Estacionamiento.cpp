#include "Estacionamiento.h"
#include <cstring>


// Getter para nombre
const char* Estacionamiento::getNombre() const {
    return nombre;
}

// Getter para CUIT
const char* Estacionamiento::getCuit() const {
    return cuit;
}

// Getter para lugares disponibles
int Estacionamiento::getLugaresDisponibles() const {
    return lugaresDisponibles;
}

// Setter para nombre
void Estacionamiento::setNombre(const char* nombre) {
    strncpy(this->nombre, nombre, sizeof(this->nombre) - 1);
    this->nombre[sizeof(this->nombre) - 1] = '\0';  // Asegurar terminador nulo
}

// Setter para CUIT
void Estacionamiento::setCuit(const char* cuit) {
    strncpy(this->cuit, cuit, sizeof(this->cuit) - 1);
    this->cuit[sizeof(this->cuit) - 1] = '\0';  // Asegurar terminador nulo
}

// Setter para lugares disponibles
void Estacionamiento::setLugaresDisponibles(int lugares) {
    lugaresDisponibles = lugares;
}

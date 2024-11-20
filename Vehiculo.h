#pragma once
#include <string>

class Vehiculo
{
private:
    char _patente [30];
    int _tipoVehiculo;

public:
    void setPatente(const char* patente);
    void setTipo (int tipoVehiculo);


    const char* getPatente() const;
    int getTipo() const;
};

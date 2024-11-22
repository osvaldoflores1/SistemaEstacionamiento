#pragma once
#include <string>
#include <ctime>


class Vehiculo
{
private:
    char _patente [30];
    int _tipoVehiculo;
    std::time_t _fechaHoraIngreso;
public:
    void setPatente(const char* patente);
    void setTipo (int tipoVehiculo);


    const char* getPatente() const;
    int getTipo() const;

     void setFechaHoraIngreso(std::time_t fechaHora);
     std::time_t getFechaHoraIngreso() const;
    std::string getFechaHoraIngresoFormato() const ;
};

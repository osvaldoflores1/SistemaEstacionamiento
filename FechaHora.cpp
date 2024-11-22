#ifndef FECHAHORA_H
#define FECHAHORA_H

#include <iostream>
#include <ctime>
#include <iomanip>
#include "FechaHora.h"
class FechaHora {
private:
    int _dia, _mes, _anio, _hora, _minuto, _segundo;

public:
    FechaHora() {
        // Inicializar con la fecha y hora actual
        std::time_t t = std::time(nullptr);
        std::tm* now = std::localtime(&t);
        _dia = now->tm_mday;
        _mes = now->tm_mon + 1;  // Los meses comienzan en 0
        _anio = now->tm_year + 1900;  // Años desde 1900
        _hora = now->tm_hour;
        _minuto = now->tm_min;
        _segundo = now->tm_sec;
    }

    void mostrar() const {
        std::cout << std::setfill('0') << std::setw(2) << _dia << "/"
                  << std::setw(2) << _mes << "/" << _anio << " "
                  << std::setw(2) << _hora << ":"
                  << std::setw(2) << _minuto << ":"
                  << std::setw(2) << _segundo << std::endl;
    }

    // Métodos de acceso
    int getDia() const { return _dia; }
    int getMes() const { return _mes; }
    int getAnio() const { return _anio; }
    int getHora() const { return _hora; }
    int getMinuto() const { return _minuto; }
    int getSegundo() const { return _segundo; }

    // Sobrecarga para guardar en archivos binarios
    friend std::ostream& operator<<(std::ostream& os, const FechaHora& fechaHora) {
        os << fechaHora._dia << " " << fechaHora._mes << " " << fechaHora._anio << " "
           << fechaHora._hora << " " << fechaHora._minuto << " " << fechaHora._segundo;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, FechaHora& fechaHora) {
        is >> fechaHora._dia >> fechaHora._mes >> fechaHora._anio
           >> fechaHora._hora >> fechaHora._minuto >> fechaHora._segundo;
        return is;
    }
};

#endif

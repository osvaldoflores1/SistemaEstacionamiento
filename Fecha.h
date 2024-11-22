#ifndef FECHAHORA_H
#define FECHAHORA_H

#include <iostream>
#include <ctime>
#include <iomanip>

class FechaHora {
private:
    int _dia, _mes, _anio, _hora, _minuto, _segundo;

public:
    // Constructor que inicializa con la fecha y hora actuales
    FechaHora();

    // Métodos para mostrar la fecha y hora
    void mostrar() const;

    // Métodos de acceso
    int getDia() const;
    int getMes() const;
    int getAnio() const;
    int getHora() const;
    int getMinuto() const;
    int getSegundo() const;

    // Sobrecarga de operadores para archivos
    friend std::ostream& operator<<(std::ostream& os, const FechaHora& fechaHora);
    friend std::istream& operator>>(std::istream& is, FechaHora& fechaHora);
};

#endif // FECHAHORA_H

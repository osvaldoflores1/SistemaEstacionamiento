#pragma once
#include <string>

class fecha
{
  private:
  int _dia, _mes, _anio;

  public:
    fecha(int dia, int mes, int anio);
    fecha();
    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void mostrar();
    std::string toString();

};

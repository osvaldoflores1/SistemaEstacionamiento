#pragma once
#include <string>

class hora
{
  private:
    int _hora, _minuto;

  public:
    hora(int Hora, int minuto);
    hora();
    int getHora();
    int getMinuto();
    void setHora(int Hora);
    void setMinuto(int minuto);
    void mostrar();
    std::string toString();
};



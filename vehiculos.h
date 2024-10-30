#pragma once
#include <string>
#include "hora.h"

class vehiculos
{
  private:
  char _patente[50];
  int _tipoVehiculo;
  hora _horaIngreso;
  hora _horaSalida;
  bool _eliminado;
  public:

  void Cargar();
  void Mostrar();

  void setPatente(std::string patente);
  void setTipoVehiculo(int tipoVehiculo);
  void setHoraIngreso(hora horaingreso);
  void setHoraSalida(hora horasalida);
  void setEliminado(bool eliminado);

  std::string getPatente()const;
  int getTipoVehiculo();
  hora getHoraIngreso();
  hora getHoraSalida();
  bool getEliminado();

};


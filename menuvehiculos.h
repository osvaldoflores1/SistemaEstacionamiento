
#ifndef MENUVEHICULOS_H
#define MENUVEHICULOS_H
#include "vehiculos.h"
#include "tipovehiculos.h"
#include "archivos.h"

class menuvehiculos
{
  private:
    archivos _archivoVehiculos = archivos ("vehiculos.dat");
    archivos _archivoTipodeV = archivos ("tipodevehiculos.dat");
  public:

  void IngresoVehiculo ();
  void EgresoVehiculo();
  void mostrarVehiculos(vehiculos reg);

  void CargarTipoVehiculo();
  void ModificarTipoVehiculo();
  void MostrarTipoVehiculos(tipoVehiculos reg);

  void mostrar();
};

#endif // MENUVEHICULOS_H

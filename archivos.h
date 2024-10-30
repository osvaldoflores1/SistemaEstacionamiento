#pragma once
#include "vehiculos.h"
#include "tipovehiculos.h"
#include <string>

class archivos
{
  private:
    std::string _nombreArchivo;
  public:
    // vehiculos
    archivos (std::string nombrearchivo);
    bool GuardarVehiculo (vehiculos reg);
    bool GuardarVehiculo (vehiculos reg, int nroreg);
    vehiculos leerVehiculos (int nroreg);
    int BuscarVehiculo (std::string patente);

    int contarRegistros();

   // tipo de vehiculos
   bool guardarTipoV ( tipoVehiculos reg);
   int BuscarTipoV  ( int idvehiculo );
   bool GuardarTipoV (tipoVehiculos reg, int nroreg); // para modificar algun dato
   tipoVehiculos leerTipoVehiculo ( int nroreg);


  };


#pragma once

#include "Estacionamiento.h"
#include "Precio.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include "Vehiculo.h"

class ArchivosManager {
private:
    char _nombreArchivo[70];

public:
    // Constructor
    ArchivosManager(const char *n) ;

    // Métodos para guardar y leer Estacionamiento
    bool guardarEstacionamiento(Estacionamiento estacionamiento);
    Estacionamiento leerEstacionamiento(int pos);

    ///Metodos para guardar, leer y modificar precios.
     bool guardarPrecio(Precio precio);
     Precio leerPrecio(int pos);

    /// METODO PARA MODIFICAR PRECIOS
    bool modificarPrecio(int pos, int nuevoPrecio);


    bool guardarVehiculo(Vehiculo reg);


    /// METODO PARA BUSCAR POR PATENTE
    bool buscarVehiculoPorPatente(const char* patente, Vehiculo& vehiculoEncontrado);

    bool eliminarVehiculoPorPatente(const char* patente);


};

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

    ///Metodos para guardar, leer precios.
     bool guardarPrecio(Precio precio);
     bool leerPrecios(float precios[]);

    /// METODO PARA MODIFICAR PRECIOS
    bool modificarPrecio(int pos, float nuevoPrecio);


    bool guardarVehiculo(Vehiculo reg);


    /// METODO PARA BUSCAR POR PATENTE
    bool buscarVehiculoPorPatente(const char* patente, Vehiculo& vehiculoEncontrado);

    bool eliminarVehiculoPorPatente(const char* patente);
    bool actualizarEstacionamiento(int pos, const Estacionamiento& nuevoEstado);

};

#pragma once

#include "Estacionamiento.h"
#include "Precio.h"
#include <iostream>
#include <cstring>
#include <cstdio>

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
    void modificarPrecio(int indice, int nuevoPrecio);
};

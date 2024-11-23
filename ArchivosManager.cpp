#include "ArchivosManager.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include "Estacionamiento.h"
#include "Precio.h"
#include <fstream>
using namespace std;

// Constructor
ArchivosManager::ArchivosManager(const char* n) {
    strcpy(_nombreArchivo, n);
}

// Método para guardar un objeto Estacionamiento en el archivo
bool ArchivosManager::guardarEstacionamiento(Estacionamiento reg){
        FILE *p;
        p=fopen(_nombreArchivo, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }



// Método para leer un objeto Estacionamiento desde el archivo
Estacionamiento ArchivosManager::leerEstacionamiento(int pos) {
    Estacionamiento reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {

        return reg;
    }
    fseek(p, pos * sizeof reg, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

bool ArchivosManager::actualizarEstacionamiento(int pos, const Estacionamiento& nuevoEstado) {
    FILE *p = fopen(_nombreArchivo, "rb+");
    if (p == NULL) {
        return false;
    }
    fseek(p, pos * sizeof nuevoEstado, 0);
    fwrite(&nuevoEstado, sizeof nuevoEstado, 1, p);
    fclose(p);
    return true;
}



// Método para guardar un objeto Precio en el archivo
bool ArchivosManager::guardarPrecio(Precio reg){
        FILE *p;
        p=fopen(_nombreArchivo, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }


// Método para leer un objeto Precio desde el archivo
bool ArchivosManager::leerPrecios(float precios[]) {
    std::ifstream file(_nombreArchivo, std::ios::binary);
    if (!file) return false;

    for (int i = 0; i < 3; ++i) {
        file.read(reinterpret_cast<char*>(&precios[i]), sizeof(float));
        if (!file) return false; // Error en la lectura
    }

    file.close();
    return true;
}

bool ArchivosManager::modificarPrecio(int campo, float nuevoValor) {

    FILE* p = fopen(_nombreArchivo, "rb+");
    if (p == NULL) {
        return false;
    }

    Precio precio;
    if (fread(&precio, sizeof(Precio), 1, p) != 1) {
        fclose(p);
        return false;
    }

    // Modificar el campo especificado
    switch (campo) {
        case 0: precio.setPrecioHoraAuto(nuevoValor); break;
        case 1: precio.setPrecioDiaAuto(nuevoValor); break;
        case 2: precio.setPrecioHoraCamioneta(nuevoValor); break;
        case 3: precio.setPrecioDiaCamioneta(nuevoValor); break;
        default:
            fclose(p);
            return false;
    }

    fseek(p, 0, SEEK_SET);
    if (fwrite(&precio, sizeof(Precio), 1, p) != 1) {
        fclose(p);
        return false;
    }

    fclose(p);
    return true;

}


///METODO PARA GUARDAR UN VEHICULO QUE INGRESÓ

bool ArchivosManager::guardarVehiculo(Vehiculo reg){
        FILE *p;
        p=fopen(_nombreArchivo, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }



///METODO PARA BUSCAR  POR PATENTE
bool ArchivosManager::buscarVehiculoPorPatente(const char* patente, Vehiculo& vehiculoEncontrado) {
    ifstream file(_nombreArchivo, std::ios::binary);
    if (!file) return false;

    Vehiculo vehiculo;
    while (file.read(reinterpret_cast<char*>(&vehiculo), sizeof(Vehiculo))) {
        if (strcmp(vehiculo.getPatente(), patente) == 0) {
            vehiculoEncontrado = vehiculo;
            return true;
        }
    }
    return false;
}
bool ArchivosManager::eliminarVehiculoPorPatente(const char* patente) {
    std::ifstream file(_nombreArchivo, std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir el archivo: " << _nombreArchivo << std::endl;
        return false;
    }

    std::ofstream tempFile("temp.bin", std::ios::binary);
    if (!tempFile) {
        std::cerr << "Error al crear archivo temporal." << std::endl;
        return false;
    }

    Vehiculo vehiculo;
    bool encontrado = false;

    while (file.read(reinterpret_cast<char*>(&vehiculo), sizeof(Vehiculo))) {
        if (strcmp(vehiculo.getPatente(), patente) != 0) {
            tempFile.write(reinterpret_cast<const char*>(&vehiculo), sizeof(Vehiculo));
        } else {
            encontrado = true;
        }
    }

    file.close();
    tempFile.close();

    if (encontrado) {
        remove(_nombreArchivo);
        rename("temp.bin", _nombreArchivo);
    } else {
        remove("temp.bin");
    }

    return encontrado;
}


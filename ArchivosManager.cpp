#include "ArchivosManager.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include "Estacionamiento.h"
#include "Precio.h"
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
Precio ArchivosManager::leerPrecio(int pos) {
    Precio reg;
    FILE *p = fopen(_nombreArchivo, "rb");
    if (p == NULL) {

        return reg;
    }
    fseek(p, pos * sizeof reg, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

//// Metodo para modificar un precio
bool ArchivosManager::modificarPrecio(int campo, int nuevoValor) {

    FILE* p = fopen(_nombreArchivo, "rb+"); // Modo de lectura y escritura
    if (p == NULL) {
        return false;
    }

    Precio precio;
    if (fread(&precio, sizeof(Precio), 1, p) != 1) { // Leer el primer registro
        fclose(p);
        return false;
    }

    // Modificar el campo especificado
    switch (campo) {
        case 0: precio.setPrecioHoraAuto(nuevoValor); break;
        case 1: precio.setPrecioDiaAuto(nuevoValor); break;
        case 2: precio.setPrecioMesAuto(nuevoValor); break;
        case 3: precio.setPrecioHoraCamioneta(nuevoValor); break;
        case 4: precio.setPrecioDiaCamioneta(nuevoValor); break;
        case 5: precio.setPrecioMesCamioneta(nuevoValor); break;
        default:
            fclose(p);
            return false; // Campo no válido
    }

    fseek(p, 0, SEEK_SET); // Mover el puntero al inicio del archivo
    if (fwrite(&precio, sizeof(Precio), 1, p) != 1) { // Sobrescribir el registro
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

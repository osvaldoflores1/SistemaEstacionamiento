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
void ArchivosManager::modificarPrecio(int indice, int nuevoPrecio) {
    Precio reg;
    FILE* p = fopen(_nombreArchivo, "rb+"); // Abrir archivo en modo lectura/escritura
    if (p == NULL) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    // Desplazar al registro indicado por el índice
    fseek(p, indice * sizeof(Precio), SEEK_SET);

    // Leer el registro actual
    fread(&reg, sizeof(Precio), 1, p);

    // Actualizar el valor del precio correspondiente
    switch (indice) {
        case 0: reg.setPrecioHoraAuto(nuevoPrecio); break;
        case 1: reg.setPrecioDiaAuto(nuevoPrecio); break;
        case 2: reg.setPrecioMesAuto(nuevoPrecio); break;
        case 3: reg.setPrecioHoraCamioneta(nuevoPrecio); break;
        case 4: reg.setPrecioDiaCamioneta(nuevoPrecio); break;
        case 5: reg.setPrecioMesCamioneta(nuevoPrecio); break;
        default:
            cout << "Índice no válido." << endl;
            fclose(p);
            return;
    }

    // Volver al inicio del registro para sobrescribir
    fseek(p, indice * sizeof(Precio), SEEK_SET);
    fwrite(&reg, sizeof(Precio), 1, p);

    fclose(p);
    cout << "Precio actualizado correctamente." << endl;
}



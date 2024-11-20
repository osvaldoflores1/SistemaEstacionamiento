#ifndef ESTACIONAMIENTO_H
#define ESTACIONAMIENTO_H

class Estacionamiento {
private:
    char nombre[70];
    char cuit[40];
    int lugaresDisponibles;

public:

    const char* getNombre() const;
    const char* getCuit() const;
    int getLugaresDisponibles() const;

    // Setters
    void setNombre(const char* nombre);
    void setCuit(const char* cuit);
    void setLugaresDisponibles(int lugares);
};

#endif // ESTACIONAMIENTO_H

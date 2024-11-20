#include <iostream>
#include <cstring>
#include <string>


#include "Precio.h"
using namespace std;


////GETTERS DE AUTO
int Precio::getPrecioHoraAuto() const {
    return _precioHoraAuto;
}
int Precio::getPrecioDiaAuto() const {
    return _precioDiaAuto;
}
int Precio::getPrecioMesAuto() const {
    return _precioMesAuto;
}

///// GETTERS DE  CAMIONETA
int Precio::getPrecioHoraCamioneta() const {
    return _precioHoraCamioneta;
}
int Precio::getPrecioDiaCamioneta() const {
    return _precioDiaCamioneta;
}
int Precio::getPrecioMesCamioneta() const {
    return _precioMesCamioneta;
}




////SETTERS DE AUTO
void Precio::setPrecioHoraAuto(int precioHoraAuto) {
    _precioHoraAuto = precioHoraAuto;
}

void Precio::setPrecioDiaAuto(int precioDiaAuto) {
    _precioDiaAuto = precioDiaAuto;
}
void Precio::setPrecioMesAuto(int precioMesAuto) {
    _precioMesAuto = precioMesAuto;
}



//// SETTERS DE CAMIONETA

void Precio::setPrecioHoraCamioneta(int precioHoraCamioneta) {
    _precioHoraCamioneta = precioHoraCamioneta;
}

void Precio::setPrecioDiaCamioneta(int precioDiaCamioneta) {
    _precioDiaCamioneta = precioDiaCamioneta;
}
void Precio::setPrecioMesCamioneta(int precioMesCamioneta) {
    _precioMesCamioneta = precioMesCamioneta;
}




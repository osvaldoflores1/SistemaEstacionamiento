#include <iostream>
#include <cstring>
#include <string>


#include "Precio.h"
using namespace std;


////GETTERS DE AUTO
float Precio::getPrecioHoraAuto() const {
    return _precioHoraAuto;
}
float Precio::getPrecioDiaAuto() const {
    return _precioDiaAuto;
}
float Precio::getPrecioMesAuto() const {
    return _precioMesAuto;
}

///// GETTERS DE  CAMIONETA
float Precio::getPrecioHoraCamioneta() const {
    return _precioHoraCamioneta;
}
float Precio::getPrecioDiaCamioneta() const {
    return _precioDiaCamioneta;
}
float Precio::getPrecioMesCamioneta() const {
    return _precioMesCamioneta;
}




////SETTERS DE AUTO
void Precio::setPrecioHoraAuto(float precioHoraAuto) {
    _precioHoraAuto = precioHoraAuto;
}

void Precio::setPrecioDiaAuto(float precioDiaAuto) {
    _precioDiaAuto = precioDiaAuto;
}
void Precio::setPrecioMesAuto(float precioMesAuto) {
    _precioMesAuto = precioMesAuto;
}



//// SETTERS DE CAMIONETA

void Precio::setPrecioHoraCamioneta(float precioHoraCamioneta) {
    _precioHoraCamioneta = precioHoraCamioneta;
}

void Precio::setPrecioDiaCamioneta(float precioDiaCamioneta) {
    _precioDiaCamioneta = precioDiaCamioneta;
}
void Precio::setPrecioMesCamioneta(float precioMesCamioneta) {
    _precioMesCamioneta = precioMesCamioneta;
}




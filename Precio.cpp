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



///// GETTERS DE  CAMIONETA
float Precio::getPrecioHoraCamioneta() const {
    return _precioHoraCamioneta;
}
float Precio::getPrecioDiaCamioneta() const {
    return _precioDiaCamioneta;
}




////SETTERS DE AUTO
void Precio::setPrecioHoraAuto(float precioHoraAuto) {
    _precioHoraAuto = precioHoraAuto;
}

void Precio::setPrecioDiaAuto(float precioDiaAuto) {
    _precioDiaAuto = precioDiaAuto;
}



//// SETTERS DE CAMIONETA

void Precio::setPrecioHoraCamioneta(float precioHoraCamioneta) {
    _precioHoraCamioneta = precioHoraCamioneta;
}

void Precio::setPrecioDiaCamioneta(float precioDiaCamioneta) {
    _precioDiaCamioneta = precioDiaCamioneta;
}




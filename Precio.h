#pragma once
#include <string>

class Precio{

private:
    float _precioHoraAuto;
    float _precioDiaAuto;


    float _precioHoraCamioneta;
    float _precioDiaCamioneta;


public:
    void setPrecioHoraAuto(float precioHoraAuto);
    void setPrecioDiaAuto (float precioDiaAuto);


    void setPrecioHoraCamioneta(float precioHoraCamioneta);
    void setPrecioDiaCamioneta (float precioDiaCamioneta);


    float getPrecioHoraAuto() const;
    float getPrecioDiaAuto() const;

    float getPrecioHoraCamioneta() const;
    float getPrecioDiaCamioneta() const;
};

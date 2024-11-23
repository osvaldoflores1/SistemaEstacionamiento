#pragma once
#include <string>

class Precio{

private:
    float _precioHoraAuto;
    float _precioDiaAuto;
    float _precioMesAuto;

    float _precioHoraCamioneta;
    float _precioDiaCamioneta;
    float _precioMesCamioneta;

public:
    void setPrecioHoraAuto(float precioHoraAuto);
    void setPrecioDiaAuto (float precioDiaAuto);
    void setPrecioMesAuto(float precioMesAuto);


    void setPrecioHoraCamioneta(float precioHoraCamioneta);
    void setPrecioDiaCamioneta (float precioDiaCamioneta);
    void setPrecioMesCamioneta(float precioMesCamioneta);


    float getPrecioHoraAuto() const;
    float getPrecioDiaAuto() const;
    float getPrecioMesAuto() const;

    float getPrecioHoraCamioneta() const;
    float getPrecioDiaCamioneta() const;
    float getPrecioMesCamioneta() const;
};

#pragma once
#include <string>

class Precio{

private:
    int _precioHoraAuto;
    int _precioDiaAuto;
    int _precioMesAuto;

    int _precioHoraCamioneta;
    int _precioDiaCamioneta;
    int _precioMesCamioneta;

public:
    void setPrecioHoraAuto(int precioHoraAuto);
    void setPrecioDiaAuto (int precioDiaAuto);
    void setPrecioMesAuto(int precioMesAuto);


    void setPrecioHoraCamioneta(int precioHoraCamioneta);
    void setPrecioDiaCamioneta (int precioDiaCamioneta);
    void setPrecioMesCamioneta(int precioMesCamioneta);


    int getPrecioHoraAuto() const;
    int getPrecioDiaAuto() const;
    int getPrecioMesAuto() const;

    int getPrecioHoraCamioneta() const;
    int getPrecioDiaCamioneta() const;
    int getPrecioMesCamioneta() const;
};

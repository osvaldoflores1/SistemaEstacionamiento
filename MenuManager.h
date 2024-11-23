#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include <string>
#include "Vehiculo.h"


class MenuManager
{
public:
    void menuPrincipal();
    void menuAltaEstacionamiento();
    void lugaresDisponibles();
    void menuIngresoVehiculos();
    void menuEgresoVehiculos();
    void menuModificacionPrecios();
    void listadoVehiculos();
    void menuReportesFacturacion();

};

#endif

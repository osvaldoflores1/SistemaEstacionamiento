#include "MenuManager.h"
#include <iostream>
#include "Vehiculo.h"
#include "Estacionamiento.h"
#include "ArchivosManager.h"
#include "Precio.h"
#include <cstring>
#include <fstream>
using namespace std;

void MenuManager::menuPrincipal() {
    int seleccion;
    bool finDeMenu = false;

    while (!finDeMenu) {
        system("cls");
        cout << "SISTEMA DE GESTION ESTACIONAMIENTO VEHICULAR" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1. ALTA ESTACIONAMIENTO" << endl;
        cout << "2. DISPONIBILIDAD DE LUGARES" << endl;
        cout << "3. INGRESO DE VEHICULOS" << endl;
        cout << "4. EGRESO DE VEHICULOS" << endl;
        cout << "5. MODIFICACION DE PRECIOS" << endl;
        cout << "6. LISTADO DE VEHICULOS INGRESADOS" << endl;
        cout << "0. SALIR" << endl;
        cout << "Seleccione una opcion: ";
        cin >> seleccion;

        switch (seleccion) {
            case 1:
             menuAltaEstacionamiento();
                break;
            case 2:
                lugaresDisponibles();
                break;
            case 3:
                menuIngresoVehiculos();
                break;

            case 4:
                menuEgresoVehiculos();
                break;
            case 5:
                menuModificacionPrecios();
                break;

            case 6:
                listadoVehiculos();
                break;

            case 0:
                finDeMenu = true;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                system("pause");
                break;
        }
    }
}

void MenuManager::menuAltaEstacionamiento() {
     ArchivosManager archivoManager("estacionamientos");
     ArchivosManager archivoPrecios("precios");
    Estacionamiento estacionamiento;
    Precio precio;
    char nombre[50];
    char cuit[15];
    int lugares;
    int precioHoraAuto;
    int precioDiaAuto;
    int precioHoraCamioneta;
    int precioDiaCamioneta;

    cout << "Ingrese nombre del estacionamiento: ";
    cin.ignore();
    cin.getline(nombre, 50);
    cout << "Ingrese CUIT del estacionamiento: ";
    cin.getline(cuit, 15);
    cout << "Ingrese lugares disponibles: ";
    cin >> lugares;
     cout << "Ingrese la tarifa de la hora de auto:  ";
    cin >> precioHoraAuto;
    cout << "Ingrese la tarifa del dia de auto:  ";
    cin >> precioDiaAuto;


    cout << "Ingrese la tarifa de la hora de camioneta:  ";
    cin >> precioHoraCamioneta;
    cout << "Ingrese la tarifa del dia de camioneta:  ";
    cin >> precioDiaCamioneta;


    estacionamiento.setNombre(nombre);
    estacionamiento.setCuit(cuit);
    estacionamiento.setLugaresDisponibles(lugares);
    precio.setPrecioDiaAuto(precioDiaAuto);
    precio.setPrecioHoraAuto(precioHoraAuto);

    precio.setPrecioDiaCamioneta(precioDiaCamioneta);
    precio.setPrecioHoraCamioneta(precioHoraCamioneta);

    if (archivoManager.guardarEstacionamiento(estacionamiento) && archivoPrecios.guardarPrecio(precio)) {
        cout << "Estacionamiento guardado con �xito.\n";
    } else {
        cout << "Error al guardar el estacionamiento.\n";
    }
}
void MenuManager::lugaresDisponibles() {
    ArchivosManager estacionamientos("estacionamientos");
    Estacionamiento lectura = estacionamientos.leerEstacionamiento(0);

    cout << "Cantidad total de lugares disponibles: " << lectura.getLugaresDisponibles() << endl;
        system("pause");

}
void MenuManager::menuIngresoVehiculos() {

    ArchivosManager archivoEstacionamiento("estacionamientos");
    Estacionamiento estadoActual = archivoEstacionamiento.leerEstacionamiento(0);
    ArchivosManager archivoVehiculosIngresados("vehiculosingresados");
    Vehiculo nuevoVehiculo;
    cout << "INGRESO DE VEHICULOS" << endl;
    cout << "--------------------"<< endl;
    char patente[30];
    int tipoVehiculo;

    cout << "Ingrese la patente del vehiculo: ";
    cin.ignore();
    cin.getline(patente, 30);
    cout << "Ingrese el tipo de veh�culo (1=Auto, 2=Camioneta): ";
    cin >> tipoVehiculo;


    nuevoVehiculo.setPatente(patente);
    nuevoVehiculo.setTipo(tipoVehiculo);
    time_t fechaHoraActual = time(nullptr); // Obtiene la fecha y hora actual
    nuevoVehiculo.setFechaHoraIngreso(fechaHoraActual);

     if (archivoVehiculosIngresados.guardarVehiculo(nuevoVehiculo)) {
        estadoActual.setLugaresDisponibles(estadoActual.getLugaresDisponibles() -1);
        archivoEstacionamiento.actualizarEstacionamiento(0, estadoActual);
        cout << "Estacionamiento guardado con exito.\n";
    } else {
        cout << "Error al guardar el estacionamiento.\n";
    }
}


void MenuManager::menuEgresoVehiculos() {
    ArchivosManager archivoEstacionamiento("estacionamientos");
    Estacionamiento estadoActual = archivoEstacionamiento.leerEstacionamiento(0);


     system("cls");
    cout << "EGRESO DE VEHICULOS" << endl;
    cout << "--------------------" << endl;

    char patente[30];
    cout << "Ingrese la patente del vehiculo a egresar: ";
    cin >> patente;

    ArchivosManager archivoVehiculos("vehiculosingresados");
    Vehiculo vehiculoEncontrado;

    if (!archivoVehiculos.buscarVehiculoPorPatente(patente, vehiculoEncontrado)) {
        cout << "Vehiculo no encontrado." << endl;
        system("pause");
        return;
    }


    time_t fechaEgreso = time(nullptr);
    double horasEstacionado = difftime(fechaEgreso, vehiculoEncontrado.getFechaHoraIngreso()) / 3600;
    int tipoVehiculo = vehiculoEncontrado.getTipo();
    // Leer precios del archivo
    ArchivosManager archivoPrecios("precios");
    float precios[4];
    if (!archivoPrecios.leerPrecios(precios)) {
        cout << "Error al leer los precios." << endl;
        system("pause");
        return;
    }
    int indicePrecioHora = (tipoVehiculo == 1) ? 0 : 2;  // Auto o Camioneta (por hora)
    int indicePrecioEstadia = (tipoVehiculo == 1) ? 1 : 3;  // Auto o Camioneta (por estad�a)

    float precioFinal = 0.0;

    if (horasEstacionado <= 12) {
        precioFinal = horasEstacionado * precios[indicePrecioHora];
        cout << "Cobro por hora: $" << precios[indicePrecioHora] << "/hora" << endl;
    } else {
        precioFinal = precios[indicePrecioEstadia];
        cout << "Cobro por estadia: $" << precios[indicePrecioEstadia] << endl;
    }

    cout << "Horas estacionado: " << horasEstacionado << endl;
    cout << "Total a pagar: $" << precioFinal << endl;


    // Eliminar el veh�culo del archivo
    if (archivoVehiculos.eliminarVehiculoPorPatente(patente)) {
    estadoActual.setLugaresDisponibles(estadoActual.getLugaresDisponibles() + 1);
    archivoEstacionamiento.actualizarEstacionamiento(0, estadoActual);
        cout << "Vehiculo egresado correctamente." << endl;
    } else {
        cout << "Error al registrar el egreso del vehiculo." << endl;
    }

    system("pause");
}

void MenuManager:: menuModificacionPrecios(){
    int seleccion;
    system("cls");
    cout << "PRECIOS : "<< endl;
    cout << "----------"<< endl;
    cout << "1 - VIGENTES"<< endl;
    cout << "2 - MODIFICAR"<< endl;
    cout << "-----------"<<endl;
    cout <<"INGRESE LA OPCION: " << endl;

    cin >> seleccion;

    if (seleccion == 1){

    FILE *p = fopen("precios", "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo de precios." << endl;
        return;
    }

    Precio reg;


    cout << "Listado de precios:" << endl;
    while (fread(&reg, sizeof(Precio), 1, p)) {
        cout << "---------------------------------"<< endl;
        cout << "Hora auto: " << reg.getPrecioHoraAuto() << endl;
        cout << "Dia auto: " << reg.getPrecioDiaAuto() << endl;
        cout << "Hora camioneta: " << reg.getPrecioHoraCamioneta() << endl;
        cout << "Dia camioneta: " << reg.getPrecioDiaCamioneta() << endl;
        cout << "---------------------------------" << endl;
    }

    fclose(p);
    system("pause");




}

        else if (seleccion == 2) {
            int opcion;
            int nuevoPrecio;

            cout << "---------------------------------" << endl;
            cout << "1 - HORA AUTO." << endl;
            cout << "2 - DIA AUTO." << endl;
            cout << "3 - HORA CAMIONETA." << endl;
            cout << "4 - DIA CAMIONETA." << endl;
            cout << "SELECCIONE LA OPCION A MODIFICAR: ";
            cin >> opcion;

            if (opcion < 1 || opcion > 6) {
                cout << "Opci�n no valida." << endl;
                system("pause");
                return;
            }

            cout << "Ingrese el nuevo precio: ";
            cin >> nuevoPrecio;

            ArchivosManager precios("precios");
            precios.modificarPrecio(opcion - 1, nuevoPrecio); // Restar 1 porque los �ndices comienzan en 0
        }


}

void MenuManager:: listadoVehiculos(){

FILE *p = fopen("vehiculosingresados", "rb");
    if (!p) {
        cout << "No se pudo abrir el archivo de Vehiculos." << endl;
        return;
    }

    Vehiculo reg;


    cout << "Listado de vehiculos:" << endl;
    while (fread(&reg, sizeof(Vehiculo), 1, p)) {
        cout << "---------------------------------"<< endl;
        cout << "PATENTE:  " << reg.getPatente() << endl;
        cout << "TIPO:  " << reg.getTipo() << endl;
        cout << "HORARIO DE INGRESO: " << reg.getFechaHoraIngresoFormato()<<endl;
        cout << "---------------------------------"<< endl;
    }

    fclose(p);
    system("pause");



}








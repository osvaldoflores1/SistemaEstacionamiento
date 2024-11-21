#include "MenuManager.h"
#include <iostream>
#include "Vehiculo.h"
#include "Estacionamiento.h"
#include "ArchivosManager.h"
#include "Precio.h"
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
        cout << "7. REPORTES" << endl;
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
                finDeMenu = true; // Salir del menú
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                system("pause"); // Pausa para que el usuario lea el mensaje
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
    int precioMesAuto;
    int precioDiaAuto;
    int precioHoraCamioneta;
    int precioDiaCamioneta;
    int precioMesCamioneta;

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
    cout << "Ingrese la tarifa del mes de auto:  ";
    cin >> precioMesAuto;


    cout << "Ingrese la tarifa de la hora de camioneta:  ";
    cin >> precioHoraCamioneta;
    cout << "Ingrese la tarifa del dia de camioneta:  ";
    cin >> precioDiaCamioneta;
    cout << "Ingrese la tarifa del mes de camioneta:  ";
    cin >> precioMesCamioneta;

    estacionamiento.setNombre(nombre);
    estacionamiento.setCuit(cuit);
    estacionamiento.setLugaresDisponibles(lugares);
    precio.setPrecioDiaAuto(precioDiaAuto);
    precio.setPrecioHoraAuto(precioHoraAuto);
    precio.setPrecioMesAuto(precioMesAuto);

    precio.setPrecioDiaCamioneta(precioDiaCamioneta);
    precio.setPrecioMesCamioneta(precioMesCamioneta);
    precio.setPrecioHoraCamioneta(precioHoraCamioneta);

    if (archivoManager.guardarEstacionamiento(estacionamiento) && archivoPrecios.guardarPrecio(precio)) {
        cout << "Estacionamiento guardado con éxito.\n";
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


    ArchivosManager archivoVehiculosIngresados("vehiculosingresados");
    Vehiculo nuevoVehiculo;
    cout << "INGRESO DE VEHICULOS" << endl;
    cout << "--------------------"<< endl;
    char patente[30];
    int tipoVehiculo;

    cout << "Ingrese la patente del vehiculo: ";
    cin.ignore();
    cin.getline(patente, 30);
    cout << "Ingrese el tipo de vehículo (1=Auto, 2=Camioneta): ";
    cin >> tipoVehiculo;


    nuevoVehiculo.setPatente(patente);
    nuevoVehiculo.setTipo(tipoVehiculo);


     if (archivoVehiculosIngresados.guardarVehiculo(nuevoVehiculo)) {
        cout << "Estacionamiento guardado con éxito.\n";
    } else {
        cout << "Error al guardar el estacionamiento.\n";
    }
}


void MenuManager::menuEgresoVehiculos() {
    system("cls");
    cout << "EGRESO DE VEHICULOS" << endl;
    // Aquí puedes implementar la lógica para el egreso de un vehículo
    char patente[30];

    cout << "Ingrese la patente del vehículo a egresar: ";
    cin >> patente;
    // Lógica para calcular tarifas y registrar el egreso...

    cout << "Vehículo egresado correctamente." << endl;
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
        cout << "Mes auto: " << reg.getPrecioMesAuto() << endl;
        cout << "Hora camioneta: " << reg.getPrecioHoraCamioneta() << endl;
        cout << "Dia camioneta: " << reg.getPrecioDiaCamioneta() << endl;
        cout << "Mes camioneta: " << reg.getPrecioMesCamioneta() << endl;
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
            cout << "3 - MES AUTO." << endl;
            cout << "4 - HORA CAMIONETA." << endl;
            cout << "5 - DIA CAMIONETA." << endl;
            cout << "6 - MES CAMIONETA." << endl;
            cout << "SELECCIONE LA OPCION A MODIFICAR: ";
            cin >> opcion;

            if (opcion < 1 || opcion > 6) {
                cout << "Opción no valida." << endl;
                system("pause");
                return;
            }

            cout << "Ingrese el nuevo precio: ";
            cin >> nuevoPrecio;

            ArchivosManager precios("precios");
            precios.modificarPrecio(opcion - 1, nuevoPrecio); // Restar 1 porque los índices comienzan en 0
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
        cout << "---------------------------------"<< endl;
    }

    fclose(p);
    system("pause");



}

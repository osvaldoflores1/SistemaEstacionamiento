#include "menuvehiculos.h"
#include <iostream>
#include <string>
using namespace std;

  void menuvehiculos:: IngresoVehiculo (){

    int opc=0;
    cout<< "**** INGRESO DE VEHICULOS ****"<<endl;
    cout<< "------------------------------"<<endl<<endl;
    cout<<"1- INGRESO" <<endl;
    cout<<"0- VOLVER"<<endl<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"INGRESE LA OPCION: "<<endl;
    cin>> opc;
    system("cls");

    if(opc == 1){
      string patente;
      int tipovehiculo;
      hora horaingreso;

      cout<< "ingrese patente: ";
      cin >> patente;
      cout<< "ingrese tipo de vehiculo:  ";
      cin>> tipovehiculo;

      vehiculos reg;
      reg.setPatente(patente);
      reg.setTipoVehiculo(tipovehiculo);
      reg.setHoraIngreso (horaingreso);

      bool ok = _archivoVehiculos.GuardarVehiculo(reg);
      if (ok) {
        cout << "nuevo ingreso generado" << endl;
        cout << endl ;
      }
      else {
        cout << "no se pudo registrar  el ingreso" ;
        cout<<endl;
      }
    }
    else {
      return;
    }
  }

  void menuvehiculos::EgresoVehiculo(){
    string patente;
    hora horasalida;
    int posicion;
    int opc;
    cout<< "**** SALIDA  DE VEHICULOS ****"<<endl;
    cout<< "-----------------------------"<<endl<<endl;
    cout<<"1- EGRESO" <<endl;
    cout<<"0- VOLVER"<<endl<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"INGRESE LA OPCION: "<<endl;
    cin>> opc;
    system("cls");

    if(opc==1){
      cout << " Ingrese patente: ";
      cin>> patente ;
      system("cls");
      vehiculos reg;
      posicion=_archivoVehiculos.BuscarVehiculo(patente);
      if (posicion >= 0){
        reg = _archivoVehiculos.leerVehiculos(posicion);
        reg.setHoraSalida(horasalida);
        _archivoVehiculos.GuardarVehiculo(reg,posicion);
        cout << "salida generada";
        cout<< endl;
        }
      else {
        cout<< "No funciona :(";
      }
    }
    else {
      return ;
    }
    system("pause");
    system("cls");

  }


  void menuvehiculos::mostrarVehiculos(vehiculos reg){

  }

  void menuvehiculos:: CargarTipoVehiculo(){
    int idvehiculo;
    float preciohora, preciodia, preciomes ;

    cout<< "ingrese id vehiculo: ";
    cin >> idvehiculo;
    cout<< "ingrese el precio por hora: ";
    cin>> preciohora;
    cout<< "ingrese el precio por dia: ";
    cin>> preciodia;
    cout<< "ingrese el precio por mes: ";
    cin>> preciomes;

    tipoVehiculos nuevo;
    nuevo.setidVehiculo(idvehiculo);
    nuevo.setPrecioHora(preciohora);
    nuevo.setPrecioDIA(preciodia);
    nuevo.setPrecioMes(preciomes);

    bool funciona = _archivoTipodeV.guardarTipoV(nuevo);
    if (funciona) {
      cout << "nuevo tipo de vehiculo  generado" << endl;
      cout << endl ;
    }
    else {
      cout << "no se pudo registrar el tipo de vehiculo" ;
      cout<<endl;
    }
    cout<< endl ;

  }

  void menuvehiculos:: ModificarTipoVehiculo(){

  }


  void menuvehiculos:: MostrarTipoVehiculos(tipoVehiculos reg){

  }

  void menuvehiculos::mostrar(){
    int posicion;
    string patente;
    cout << "patente: ";
    cin>> patente;

    posicion = _archivoVehiculos.BuscarVehiculo(patente);
    if (posicion >= 0 ){
      vehiculos nuevo = _archivoVehiculos.leerVehiculos(posicion);
      cout<< "patente: "<< nuevo.getPatente()<<endl;
      cout<< "tipo de vehiculo: "<< nuevo.getTipoVehiculo()<<endl;
      cout<< "hora ingreso: ";
      nuevo.getHoraIngreso().mostrar();

      cout<<"hora Salida: ";
      nuevo.getHoraSalida().mostrar();
    }
    else {
      cout << "no existe la patente";
    }

  }

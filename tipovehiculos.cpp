#include "tipovehiculos.h"


  void tipoVehiculos:: cargar(){

  }

  void tipoVehiculos:: setidVehiculo (int idvehiculo){
    _idVehiculo = idvehiculo ;
  }
  void tipoVehiculos::setPrecioHora (float precioHora){
    _precioHora = precioHora;
  }

  void tipoVehiculos:: setPrecioDIA (float precioDia){
    _precioDia = precioDia ;
  }
  void tipoVehiculos:: setPrecioMes (float precioMes){
    _precioMes = precioMes ;
  }
  void tipoVehiculos:: setEliminado (bool eliminado){
    _eliminado = eliminado ;
  }

  int tipoVehiculos:: getIdVehiculo (){
    return _idVehiculo;
  }
  float tipoVehiculos:: getPrecioHora(){
    return _precioHora;
  }
  float tipoVehiculos:: getPrecioDia(){
    return _precioDia;
  }
  float tipoVehiculos:: getPrecioMes (){
    return _precioMes;
  }
  bool tipoVehiculos:: getEliminado (){
    return _eliminado;
  }

#include "vehiculos.h"
#include "archivos.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


  void vehiculos:: Cargar(){

  }
  void vehiculos:: Mostrar(){
  }

  void vehiculos:: setPatente(std::string patente){
    strcpy(_patente,patente.c_str());
  }

  void vehiculos:: setTipoVehiculo(int tipoVehiculo){
    _tipoVehiculo = tipoVehiculo;
  }

  void vehiculos:: setHoraIngreso(hora horaingreso){
    _horaIngreso = horaingreso;

  }

  void vehiculos:: setHoraSalida(hora horasalida){
    _horaSalida = horasalida ;
  }

  void vehiculos:: setEliminado(bool eliminado){
    _eliminado = eliminado ;
  }

  std::string vehiculos::getPatente()const{
    return _patente;
  }

  int vehiculos:: getTipoVehiculo(){
    return _tipoVehiculo;
  }

  hora vehiculos:: getHoraIngreso(){
    return _horaIngreso;
  }

  hora vehiculos:: getHoraSalida(){
    return _horaSalida;
  }

  bool vehiculos:: getEliminado(){
    return _eliminado;
  }


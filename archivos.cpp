#include "archivos.h"
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

  archivos::archivos(std::string nombrearchivo){
  _nombreArchivo = nombrearchivo;
  }

  ///VEHICULOS
  bool archivos::GuardarVehiculo( vehiculos reg){
    bool pudoEscribir;

    FILE*p = fopen (_nombreArchivo.c_str(), "ab");
    if (p == nullptr){
      return false;
    }
    pudoEscribir = fwrite(&reg, sizeof(vehiculos),1,p);
    fclose(p);
    return pudoEscribir;
  }

  bool archivos::GuardarVehiculo(vehiculos reg, int nroreg){
    bool pudoEscribir;
    FILE*p = fopen(_nombreArchivo.c_str(),"rb+");
    if (p==nullptr){
      return false ;
    }
    fseek(p, nroreg * sizeof(vehiculos),SEEK_SET);
    pudoEscribir = fwrite (&reg, sizeof(vehiculos),1,p);
    fclose(p);
    return pudoEscribir;

  }


  int archivos::contarRegistros(){
    FILE*p = fopen (_nombreArchivo.c_str(),"rb");
    if (p==nullptr){
      return 0;
    }
    fseek(p,0,SEEK_END);
    int bytes = ftell(p);
    return bytes/ sizeof (vehiculos);
  }


  int archivos::BuscarVehiculo (std::string patente){
    FILE*p = fopen(_nombreArchivo.c_str(),"rb");
    if(p == nullptr){
      return -1;

    }
    int pos = 0;
    vehiculos reg;
    while (fread(&reg,sizeof(vehiculos),1,p)){
      if (reg.getPatente() == patente) {
        fclose(p);
        return pos;
      }
      pos ++;
    }
    fclose(p);
    return -1 ;
  }

  vehiculos archivos::leerVehiculos(int nroreg){
    vehiculos reg;
    FILE*p = fopen(_nombreArchivo.c_str(),"rb");
    if (p == nullptr){
      return reg;
    }
    fseek(p,nroreg * sizeof(vehiculos),SEEK_SET);
    fread(&reg, sizeof(vehiculos),1,p);
    fclose(p);
    return reg;
  }



  /// TIPO DE VEHICULOS

   bool archivos:: guardarTipoV ( tipoVehiculos reg){
      bool pudoEscribir;

      FILE*p = fopen (_nombreArchivo.c_str(), "ab");
      if (p == nullptr){
      return false;
      }
      pudoEscribir = fwrite(&reg, sizeof(tipoVehiculos),1,p);
      fclose(p);
      return pudoEscribir;
    }

   int archivos:: BuscarTipoV  ( int idvehiculo ){
     FILE *p = fopen(_nombreArchivo.c_str(), "rb");
      if (p == nullptr){
      return -1;
      }
      int i = 0;
      tipoVehiculos reg;
      while(fread(&reg, sizeof(tipoVehiculos), 1, p)){
      if(reg.getIdVehiculo() == idvehiculo){
      fclose(p);
      return i;
      }
      i++;
      }
      fclose(p);
      return -1;
    }

   bool  archivos::GuardarTipoV (tipoVehiculos reg, int nroreg){
      bool pudoEscribir;
      FILE*p = fopen (_nombreArchivo.c_str(), "rb+");
      if ( p == nullptr ){
        return false ;
      }
      fseek(p, nroreg * sizeof(tipoVehiculos),SEEK_SET);
      pudoEscribir = fwrite (&reg, sizeof(tipoVehiculos),1,p);
      fclose(p);
      return pudoEscribir;

    }

   tipoVehiculos  archivos::leerTipoVehiculo ( int nroreg) {
      tipoVehiculos reg;
      FILE*p = fopen(_nombreArchivo.c_str(),"rb");
      if (p == nullptr){
      return reg;
      }
      fseek(p,nroreg * sizeof(tipoVehiculos),SEEK_SET);
      fread(&reg, sizeof(tipoVehiculos),1,p);
      fclose(p);
      return reg;
    }

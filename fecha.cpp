#include "fecha.h"
#include<iostream>
#include <ctime>
using namespace std;


fecha::fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
fecha::fecha(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon+1;
    _anio = f->tm_year+1900;
}
int  fecha::getDia(){
    return _dia;
}
int  fecha::getMes(){
    return _mes;
}
int  fecha::getAnio(){
    return _anio;
}
void fecha::setDia(int dia){
    _dia = dia;
}
void fecha::setMes(int mes){
    _mes = mes;
}
void fecha::setAnio(int anio){
    _anio = anio;
}

void fecha::mostrar(){
    if (_dia < 10){
      cout << "0";
    }
    cout << _dia << "/";

    if (_mes < 10){
      cout << "0";
    }
    cout << _mes << "/";

    cout <<_anio << endl;
}


string fecha::toString(){
   return to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
}

#include "Hora.h"
#include <iostream>
#include <ctime>
using namespace std;

hora::hora(int Hora, int minuto){
    _hora = Hora;
    _minuto = minuto;
}
hora::hora(){
    time_t t;
    struct tm *f;
    time(&t);
    f = localtime(&t);
    _hora = f->tm_hour;
    _minuto = f->tm_min;
}
int  hora::getHora(){
    return _hora;
}
int  hora::getMinuto(){
    return _minuto;
}
void hora::setHora(int Hora){
    _hora = Hora;
}
void hora::setMinuto(int minuto){
    _minuto = minuto;

  }
void hora::mostrar(){
    if (_hora < 10){
        cout << "0";
    }
    cout << _hora << ":";

    if (_minuto < 10){
    cout << "0";
    }
    cout << _minuto << endl;
}



string hora::toString(){
   return to_string(_hora) + ":" + to_string(_minuto);
}

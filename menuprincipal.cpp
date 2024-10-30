#include "menuprincipal.h"
#include "menuvehiculos.h"
#include<iostream>
using namespace std;

void MenuPrincipal::Ejecutar(){
  int op;
  while (true){

  cout<< "**** MENU PRINCIPAL ****"<< endl ;
  cout<<"1- Alta Estacionamiento" <<endl;
  cout<<"2- Disponibilidad de Lugares" <<endl;
  cout<<"3- Ingreso de vehiculos" <<endl;
  cout<<"4- Egreso de vehiculos" <<endl;
  cout<<"5- Modificacion de Precios" <<endl;
  cout<<"6- Reportes" <<endl;
  cout<<"7- MOSTRAR DE PRUEBA" <<endl;
  cout<<"0- SALIR"<<endl;
  cin>> op;
  system("cls");

  menuvehiculos nuevo;
  switch(op){
  case 1:

    break;
  case 2:

    break;
  case 3:
      nuevo.IngresoVehiculo();
    break;
  case 4:
      nuevo.EgresoVehiculo();
      system("cls");

    break;
  case 5:

    break;
  case 6:

    break;
  case 7:
      nuevo.mostrar();
      system("pause");
      system("cls");
    break;
  case 0:
      return ;
    break;
  }



  }



}

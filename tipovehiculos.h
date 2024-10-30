#ifndef TIPOVEHICULOS_H
#define TIPOVEHICULOS_H


class tipoVehiculos
{
  private:
  int _idVehiculo;
  float _precioHora;
  float _precioDia;
  float _precioMes;
  bool _eliminado;


  public:
  void cargar();

  void setidVehiculo (int idvehiculo);
  void setPrecioHora (float precioHora);
  void setPrecioDIA (float precioDia);
  void setPrecioMes (float precioMes);
  void setEliminado (bool eliminado);

  int getIdVehiculo ();
  float getPrecioHora();
  float getPrecioDia();
  float getPrecioMes ();
  bool getEliminado ();

};

#endif // TIPOVEHICULOS_H

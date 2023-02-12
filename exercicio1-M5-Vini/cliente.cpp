#include "cliente.h"
using namespace std;

Cliente::Cliente(){
  this->IMEI   = -1;
  this->login = "";
};  
Cliente::Cliente(int IMEI, string login){
  this->IMEI    = IMEI;
  this->login  = login;
}
string Cliente::getLogin() const {
  return login;
}
int Cliente::getIMEI() const{
  return IMEI;
}

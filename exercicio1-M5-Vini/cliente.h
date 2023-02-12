#include <iostream>
using namespace std;

class Cliente{
private :
  int         IMEI;
  string login;  
public:  
  Cliente();
  Cliente(int IMEI, string login);
  string getLogin() const;
  int getIMEI() const;
};

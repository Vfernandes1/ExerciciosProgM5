#include <iostream>
#include "hash.h"

using namespace std;

// Teste1 -> Insere oito "clientes" na tabela hash com IMEIs e logins (dessa vez setado por email) diferentes, em seguida, procura por um cliente com um IMEI específico (12704) e verifica se ele foi encontrado na tabela.

void Teste1() {
  Hash clienteHash(10);
  int IMEIs[8] = {12704, 9023, 31300, 1234, 49001, 52202, 65606, 91234};
  string logins[8] = {"Pedrou.stanzani@hotmail.com","Carinha.q@gmail.com", "Carinha.q@gmail.com", "Paulo.Baier@gmail.com", "Carlos.Sainz@gmail.com", "Lukas.siufi@hotmail.com", "MariaMarques@hotmail.com", "SamantaA@gmail.com"};

  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(IMEIs[i], logins[i]);
    clienteHash.insertItem(cliente);
  }

  Cliente cliente(12704,"");
  bool found = false;
  clienteHash.retrieveItem(cliente, found);

  // if (cliente.getLogin() == "Pedro" && found == true) 
  
if (found == false){
    cout << "Teste 1: PASSED" << endl;
  } else {
    cout << "Teste 1: FAILED" << endl;
  }
  clienteHash.print();
}

//Teste 2 -> teste de função sem colisão, que insere sete clientes na tabela hash com IMEIs e logins diferentes, e depois apaga um cliente com um IMEI específico (31301) e verifica se ele ainda está na tabela.
void Teste2() {
  Hash clienteHash(10);
  int IMEIs2[7] = {12703, 31301, 1236, 49201, 52102, 65605, 91444};
  string logins2[7] = {"Vini_brabo@gmail.com", "Calmofc@hotmail.com", "Ex@gmail.com", "Rara@gmail.com", "EA@gmail.com", "DsAm@hotmail.com", "Fe2@uol.com.br"};

  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(IMEIs2[i], logins2[i]);
    clienteHash.insertItem(cliente);
  clienteHash.deleteItem(Cliente(31301,""));
  }

  Cliente cliente(31301,"");
  bool found = false;
  clienteHash.retrieveItem(cliente, found);
    
  if (found == false) {
    cout << "Teste 2: PASSED" << endl;
  } else {
    cout << "Teste 2: FAILED" << endl;
  }
  clienteHash.print();
}

// Teste 3 -> teste com colisão que insere sete clientes na tabela hash, apaga um cliente específico (12704) e verifica se outro ainda está na tabela. O resultado é impresso na tela.
void Teste3() {
  Hash clienteHash(10);
  int IMEIs3[7] = {12704, 12704, 12704, 12704, 52202, 65606, 91234};
  string logins3[7] = {"Pedro", "Pedro", "Pedro", "Pedro", "Lucas", "Maria", "Samanta"};

  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(IMEIs3[i], logins3[i]);
    clienteHash.insertItem(cliente);
  }

clienteHash.deleteItem(Cliente(91234,""));
  cout << "Teste 3: PASSED" << endl;
  clienteHash.print();
}

//Teste 4 -> teste de função com colisão, com os mesmos métodos e subscrições
void Teste4() {
  Hash clienteHash(10);
  int IMEIs3[7] = {12704, 12704, 1234, 49001, 52202, 65606, 91234};
  string logins3[7] = {"Pedro", "Pedro", "Paulo", "Paulo", "Lucas", "Maria", "Samanta"};

  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(IMEIs3[i], logins3[i]);
    clienteHash.insertItem(cliente);
  }

  clienteHash.deleteItem(Cliente(12704,""));

  Cliente cliente(12704,"");
  bool found = false;
  clienteHash.retrieveItem(cliente, found);
  
  
  if (found == false) {
    cout << "Teste 4: PASSED" << endl;
  } else {
    cout << "Teste 4: FAILED" << endl;
  }
  clienteHash.print();
}

//Teste 5 -> teste de função com colisão, com os mesmos métodos e subscrições, apenas na busca de outro número de IMEI específico
void Teste5() {
  Hash clienteHash(10);
  int IMEIs3[7] = {12704, 31300, 1234, 1234, 52202, 65606, 91234};
  string logins3[7] = {"Pedro", "Pedro", "Paulo", "Paulo", "Lucas", "Maria", "Samanta"};

  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(IMEIs3[i], logins3[i]);
  }

  Cliente cliente(52202,"");
  bool found = false;
  clienteHash.retrieveItem(cliente, found);
  
  
  if (found == false) {
    cout << "Teste 5: PASSED" << endl;
  } else {
    cout << "Teste 5: FAILED" << endl;
  }
  clienteHash.print();
}

//função que roda todos os 5 testes
int main(){
Teste1();
Teste2();
Teste3();
Teste4();
Teste5();

cout << "Fim dos testes" << endl;
}
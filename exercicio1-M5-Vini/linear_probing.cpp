#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];
}

Hash::~Hash(){
  delete [] structure;
}

bool Hash::isFull() const {
  return (length == max_items);
}

int Hash::getLength() const {
  return length;
}

void Hash::retrieveItem(Cliente& cliente, bool& found) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getIMEI() == cliente.getIMEI() ||
	structure[location].getIMEI() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);
  
  found = (structure[location].getIMEI() == cliente.getIMEI() );   
  if (found) { 
    cliente = structure[location];
  }
}

void Hash::insertItem(Cliente cliente) {
  int location;
  location = getHash(cliente);
  while (structure[location].getIMEI() > 0)
    location = (location + 1) % max_items;
  structure[location] = cliente;
  length++;
}

void Hash::deleteItem(Cliente cliente) {
  int startLoc = getHash(cliente);
  bool moreToSearch = true; 
  int location = startLoc;
  do {
    if (structure[location].getIMEI() == cliente.getIMEI() ||
	structure[location].getIMEI() == -1)
      moreToSearch = false;
    else
      location = (location + 1) % max_items;
  } while (location != startLoc && moreToSearch);

  if (structure[location].getIMEI() == cliente.getIMEI()) {       
    structure[location] = Cliente(-2,"");
    length--;
  }
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<< structure[i].getIMEI()<<", "<<structure[i].getLogin()<<endl;
  }
}

int Hash::getHash(Cliente cliente){
  return cliente.getIMEI() % max_items;
}


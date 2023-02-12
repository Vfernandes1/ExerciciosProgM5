#include "cliente.h"

class Hash {
 public:
  Hash(int max_items = 100);
  ~Hash();
  bool isFull() const;
  int getLength() const;
  
  void retrieveItem(Cliente& cliente, bool& found);   
  void insertItem(Cliente cliente); 
  void deleteItem(Cliente cliente);  
  void print();
 private:
  int getHash(Cliente cliente);
  int   max_items;
  int   length;
  Cliente* structure;
};



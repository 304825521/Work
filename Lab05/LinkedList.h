#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"
class LinkedList {
private:
  Node *head;
  Node *tail;
  int length;

public:
  LinkedList();
  ~LinkedList();
  void Insert(std::string name, int id);
  bool Remove(std::string name, int id);
  int Hashfunction(std::string name);
  bool Find(std::string name);
  void Remove();
  void Print();
};

#endif // __LINKEDLIST_H__
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "LeftListHeap.h"
#include <fstream>
#include <iostream>
using namespace std;
class executive {
private:
public:
  executive(string _filename);
  ~executive();
  LeftListHeap myheap;
  LeftListHeap myheapB;
  void Print();
};
#endif
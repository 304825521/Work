#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "MinMax.h"
#include <fstream>
#include <iostream>
using namespace std;
class executive {
private:
  MinMax myheap;
  MinMax myTest;

public:
  executive(string _filename);
  ~executive();

  void Print();
};
#endif
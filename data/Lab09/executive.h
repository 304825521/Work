#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "DisjointSets.h"
#include <fstream>
#include <iostream>
using namespace std;
class executive {
private:
public:
  executive(string _filename);
  ~executive();

  void Print();
};
#endif
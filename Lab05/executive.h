#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "maxHeap.h"
#include "minHeap.h"
#include <fstream>
#include <iostream>
using namespace std;
class executive {
private:
  minHeap minheap;
  maxHeap maxheap;

public:
  executive(string _filename);
  ~executive();

  void Print();
};
#endif
#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include "Node.h"
using namespace std;

class minHeap {
public:
  minHeap();
  ~minHeap();

  void Insert(string name, float distance, int count_view);
  void printTest();
  void heapify(Node *arr, int size, int i);

  int GetSize();
  bool isEmpty();
  bool findName(string name);
  void swap(Node *arr, int i, int j);

private:
  int size = 0;
  Node *minNodeArr;
  const int MAXSIZE = 1000;
};

#endif // __MINHEAP_H__
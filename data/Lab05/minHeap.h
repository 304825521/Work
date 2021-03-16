#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include "Node.h"
using namespace std;

class minHeap {
public:
  minHeap();
  ~minHeap();

  void Insert(string name, float distance, int count_view);
  void LevelOrder();
  void heapify(Node *arr, int size, int i);
  void buildHeap();
  void SearchNearestRestaurant();
  void RemoveNearestRestaurant();

  //@tag: Help method
  int GetSize();
  bool isEmpty();
  bool findName(string name, float distance, int count_review);
  void swap(Node *arr, int i, int j);
  int GetHeight(Node *temp, int index);

private:
  int size = 0;
  Node *minHeapArr;
  const int MAXSIZE = 20;

  void buildHeap(Node *arr, int size);
};

#endif // __MINHEAP_H__
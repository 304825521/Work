#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__
#include "Node.h"
using namespace std;
class maxHeap {
public:
  maxHeap();
  ~maxHeap();

  void Insert(string name, float distance, int count_view);
  void LevelOrder();
  void heapify(Node *arr, int size, int i);
  void buildHeap();
  void SearchMostReviewedRestaurant();
  void RemoveMostReviewedRestaurant();

  //@tag: Help method
  int GetSize();
  bool isEmpty();
  bool findName(string name, float distance, int count_review);
  void swap(Node *arr, int i, int j);
  int GetHeight(Node *temp, int index);

private:
  int size = 0;
  Node *maxHeapArr;
  const int MAXSIZE = 20;

  void buildHeap(Node *arr, int size);
};

#endif // __MAXHEAP_H__
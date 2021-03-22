#ifndef __MINMAX_H__
#define __MINMAX_H__
#include "Node.h"
using namespace std;
class MinMax {
public:
  MinMax();
  ~MinMax();

  void HeapifyMax(Node *arr, int size, int i);
  void HeapifyMin(Node *arr, int size, int i);
  void swap(Node *arr, int i, int j);
  int GetHeight(Node *temp, int index);
  int GetSize();
  int Find(int key);

  void BuildHeap();
  void Insert(int key);
  void Delete(int key);
  void MinLevelElements();
  void MaxLevelElements();

  //@todo: test class
  void LevelOrder();

private:
  Node *m_Arr;
  int m_size;
  const int MAXSIZE = 20;

  void BuildHeap(Node *root, int size);
  void Insert(int key, Node *root);
  void Delete(int key, Node *root);
  void MinLevelElements(Node *root);
  void MaxLevelElements(Node *root);
};

#endif // __MINMAX_H__
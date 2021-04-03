#ifndef __MINMAX_H__
#define __MINMAX_H__
#include "Node.h"
#include <cmath>
using namespace std;
class MinMax {
public:
  MinMax();
  ~MinMax();

  void init();
  void Insert(int key);
  void Heapify(Node *arr, int size, int i, bool isMinLevel);

  int GetHeight(Node *temp, int index);
  int GetParent(int index);
  int GetMaxNode(Node *arr, int index);
  void Swap(Node *arr, int i, int j);
  void BuildHeap();
  void DeleteMin();
  bool Find(int key);
  int GetDeleteIndex(int key);
  int GetSecondSmallestIndex();
  int GetSecondLargestIndex(int index);
  void HeapifyMin(Node *arr, int size, int i);
  void HeapifyMax(Node *arr, int size, int i);
  int GetMinNode();

  int FindMin();
  int FindMax();
  void LevelOrder();
  void ExperimentalProfiling();
  void DeleteMax();
  string doubleToString(double temp);
  void ClearTree(int size, Node *arr);
  int GetSize() { return m_size; }

private:
  void Insert(int key, Node *arr);
  Node *m_Arr;
  int m_size;
  const int MAXSIZE = 100;
  bool isMinLevel = true;
  int height = 0;
  int m_index;
  int count = 0;
  int LevelChangeIndex = pow(2, 0);
};

#endif // __MINMAX_H__
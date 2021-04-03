#ifndef __LEFTLISTHEAP_H__
#define __LEFTLISTHEAP_H__
#include "Node.h"
class LeftListHeap {
public:
  LeftListHeap();
  ~LeftListHeap();

  void Insert(int key);
  void BuildHeap();
  void Concatenate();
  void DeleteMin();
  void Inorder();
  void LevelOrder();

  void GetRank(Node *root);

private:
  Node *m_head;
};

#endif // __LEFTLISTHEAP_H__
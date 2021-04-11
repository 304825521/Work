#ifndef __LEFTLISTHEAP_H__
#define __LEFTLISTHEAP_H__
#include "Node.h"
class LeftListHeap {
public:
  LeftListHeap();
  ~LeftListHeap();

  void Insert(int key);
  void BuildHeap();
  void Concatenate(Node *h1, Node *h2);
  void DeleteMin();
  void Inorder();
  void LevelOrder();
  void ClearTree(Node *root);
  Node *Merge(Node *h1, Node *h2);
  int GetHeight(Node *root);
  Node *GetRoot() { return m_head; }
  void SetRoot(Node *root) { m_head = root; }
  void Swap(Node *&h1, Node *&h2);
  int Rank(Node *node);
  bool Isswapped() { return IsSwapped; }
  void SetSwapped(bool change) { IsSwapped = change; }

private:
  Node *m_head;
  int count;
  bool IsSwapped = false;
  void Insert(int key, Node *root);
  void LevelOrder(Node *root, int level);
  void Inorder(Node *root);
};

#endif // __LEFTLISTHEAP_H__
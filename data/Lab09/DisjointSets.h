#ifndef __DISJOINTSETS_H__
#define __DISJOINTSETS_H__
#include "Node.h"
class DisjointSets {
public:
  DisjointSets();
  ~DisjointSets();

  void MakeSet(int array[], int Size);
  void SetUnionByRank(int x, int y);
  int Find(int value);
  void PathCompression(int value);
  void PathPrint(int value);

  Node *HelpNode(Node *temp);
  int GetRepresentValue(int value);

private:
  int size;
  Node **m_Arr;
};

#endif // __DISJOINTSETS_H__
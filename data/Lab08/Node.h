#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>
class Node {
private:
  int key, rank;
  Node *m_right, *m_left;

  Node();
  ~Node() {}

  Node *GetRight() { return m_right; }
  Node *GetLeft() { return m_left; }
  int GetKey() { return key; }
  int GetRank() { return rank; }
  void SetRight(Node *right) { m_right = right; }
  void SetLeft(Node *left) { m_left = left; }
  void SetKey(int value) { key = value; }
  void SetRank(int value) { rank = value; }

public:
};

#endif
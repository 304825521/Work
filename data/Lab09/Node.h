#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>
using namespace std;
class Node {
private:
  int key, rank;
  Node *m_right, *m_left;
  Node *m_parent;
  Node *m_next;

public:
  Node();
  ~Node() {}
  Node(int key);
  Node *GetRight() { return m_right; }
  Node *GetLeft() { return m_left; }
  Node *GetParent() { return m_parent; }
  Node *GetNext() { return m_next; }
  int GetKey() { return key; }
  int GetRank() { return rank; }
  void SetRight(Node *right) { m_right = right; }
  void SetLeft(Node *left) { m_left = left; }
  void SetKey(int value) { key = value; }
  void SetRank(int value) { rank = value; }
  void SetParent(Node *parent) { m_parent = parent; }
  void SetNext(Node *next) { m_next = next; }
};

#endif
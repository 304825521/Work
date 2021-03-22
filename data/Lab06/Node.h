#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>
class Node {
private:
  int m_num;

public:
  Node *m_right, *m_left;
  Node(int num);
  Node();
  ~Node();

  void SetLeft(Node *left);
  Node *GetLeft();

  void SetRight(Node *right);
  Node *GetRight();

  void SetValue(int num);

  int GetValue();
};

#endif
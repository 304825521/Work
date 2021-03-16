#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
class Node {
private:
  std::string m_name;
  float m_distance;
  int m_count_review;

public:
  Node *m_right, *m_left, *m_mid = nullptr;
  Node(std::string name, float distance, int count_review);
  Node();

  void SetLeft(Node *left);
  Node *GetLeft();

  void SetMid(Node *left);
  Node *GetMid();

  void SetRight(Node *right);
  Node *GetRight();

  void SetValue(std::string name, float distance, int count_view);

  std::string GetName();
  int GetCountView();
  float GetDistance();
  ~Node();
};

#endif
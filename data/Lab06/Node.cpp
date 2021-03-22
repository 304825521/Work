#include "Node.h"

Node::Node() {
  m_num = -1;
  m_left = m_right = nullptr;
}

Node::~Node() {}

void Node::SetLeft(Node *left) { m_left = left; }

Node *Node::GetLeft() { return m_left; }

Node *Node::GetRight() { return m_right; }

void Node::SetValue(int num) { m_num = num; }

int Node::GetValue() { return m_num; }

void Node::SetRight(Node *right) { m_right = right; }

Node::Node(int num) {
  m_num = num;
  m_left = m_right = nullptr;
}

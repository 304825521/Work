#include "Node.h"

Node::Node() {
  m_name = "";
  m_distance = 0;
  m_count_review = 0;
  m_mid = m_left = m_right = nullptr;
}

void Node::SetLeft(Node *left) { m_left = left; }

Node *Node::GetLeft() { return m_left; }

Node *Node::GetRight() { return m_right; }

void Node::SetValue(std::string name, float distance, int count_view) {
  m_name = name;
  m_distance = distance;
  m_count_review = count_view;
}

std::string Node::GetName() { return m_name; }

int Node::GetCountView() { return m_count_review; }

float Node::GetDistance() { return m_distance; }

void Node::SetRight(Node *right) { m_right = right; }

Node *Node::GetMid() { return m_mid; }

void Node::SetMid(Node *mid) { m_mid = mid; }

Node::~Node() {}

Node::Node(std::string name, float distance, int count_review) {
  m_name = name;
  m_distance = distance;
  m_count_review = count_review;
}

#include "Node.h"

Node::Node() {
  key = rank = 0;
  m_parent = nullptr;
}

Node::Node(int value) {
  key = value;
  rank = 0;
  m_parent = nullptr;
}

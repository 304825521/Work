#include "Node.h"

Node::Node() {
  key = -1;
  rank = 0;
  m_left = m_right = nullptr;
}

Node::Node(int key) {
  m_left = m_right = nullptr;
  this->key = key;
}

#include "LeftListHeap.h"
#include <fstream>

// test
#include <queue>
#include <vector>

LeftListHeap::LeftListHeap() {
  m_head = nullptr;
  count = 0;
}

LeftListHeap::~LeftListHeap() {}

void LeftListHeap::ClearTree(Node *root) {
  if (root != nullptr) {
    ClearTree(root->GetLeft());
    ClearTree(root->GetRight());
    delete root;
  }
}

void LeftListHeap::Swap(Node *&h1, Node *&h2) {
  Node *temp = h1;
  h1 = h2;
  h2 = temp;
  temp = nullptr;
  delete temp;
}

void LeftListHeap::Insert(int key) { Insert(key, m_head); }

void LeftListHeap::Insert(int key, Node *root) {
  if (m_head == nullptr) {
    m_head = new Node(key);
  } else {
    Node *temp = new Node(key);
    m_head = Merge(m_head, temp);
  }
}

void LeftListHeap::BuildHeap() {
  cout << "Output: Heap built successfully. The new level order traversal is:";
  LevelOrder();
}

void LeftListHeap::DeleteMin() {
  Node *left = m_head->GetLeft();
  Node *right = m_head->GetRight();
  delete m_head;
  m_head = Merge(left, right);
}

void LeftListHeap::Inorder() { Inorder(m_head); }

int LeftListHeap::Rank(Node *node) {
  if (node == nullptr)
    return 0;

  int leftRank = Rank(node->GetLeft());
  int minRank = Rank(node->GetRight());

  if (leftRank < minRank)
    minRank = leftRank;

  return minRank + 1;
}

Node *LeftListHeap::Merge(Node *h1, Node *h2) {
  SetSwapped(false);
  if (h1 == nullptr) {
    return h2;
  }
  if (h2 == nullptr) {
    return h1;
  }
  if (h1->GetKey() > h2->GetKey()) {
    Swap(h1, h2);
  }
  h1->SetRight(Merge(h1->GetRight(), h2));
  if (Rank(h1->GetLeft()) < Rank(h1->GetRight())) {
    Node *temp = h1->GetLeft();
    h1->SetLeft(h1->GetRight());
    h1->SetRight(temp);
    SetSwapped(true);
  }
  return h1;
}

int LeftListHeap::GetHeight(Node *root) {
  int height = 0;
  while (root != nullptr) {
    height++;
    if (GetHeight(root->GetLeft()) > GetHeight(root->GetRight())) {
      root = root->GetLeft();
    } else {
      root = root->GetRight();
    }
  }
  return height;
}

void LeftListHeap::LevelOrder() {
  int height = GetHeight(m_head);
  for (int i = 0; i < height; i++) {
    LevelOrder(m_head, i);
  }
}
void LeftListHeap::LevelOrder(Node *root, int level) {
  if (root == nullptr) {
    return;
  } else if (level == 0) {
    cout << root->GetKey() << ' ';
  } else {
    LevelOrder(root->GetLeft(), level - 1);
    LevelOrder(root->GetRight(), level - 1);
  }
}

void LeftListHeap::Inorder(Node *root) {
  if (root != NULL) {
    Inorder(root->GetLeft());
    cout << root->GetKey() << " ";
    Inorder(root->GetRight());
  }
}

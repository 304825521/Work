#include "DisjointSets.h"

DisjointSets::DisjointSets() {
  size = 0;
  m_Arr = nullptr;
}

Node *DisjointSets::HelpNode(Node *temp) {
  if (temp->GetParent() == nullptr) {
    return temp;
  } else {
    return HelpNode(temp->GetParent());
  }
}

int DisjointSets::GetRepresentValue(int value) {
  Node *temp = nullptr;

  for (int i = 0; i < size; i++) {
    if (m_Arr[i]->GetKey() == value) {
      temp = m_Arr[i];
      break;
    }
  }

  Node *tempRoot = HelpNode(temp);
  if (temp == tempRoot) {
    return temp->GetKey();
  } else {
    return tempRoot->GetKey();
  }
}

DisjointSets::~DisjointSets() {
  for (int i = 0; i < size; i++) {
    if (m_Arr[i] != nullptr) {
      delete m_Arr[i];
    }
  }
  delete[] m_Arr;
}

void DisjointSets::MakeSet(int array[], int Size) {
  size = Size;
  m_Arr = new Node *[size]();
  for (size_t i = 0; i < size; i++) {
    int value = array[i];
    m_Arr[i] = new Node(value);
  }
}

void DisjointSets::SetUnionByRank(int x, int y) {
  Node *tempX = nullptr;
  Node *tempY = nullptr;

  for (int i = 0; i < size; i++) {
    if (m_Arr[i]->GetKey() == x) {
      tempX = m_Arr[i];
      break;
    }
  }

  for (int i = 0; i < size; i++) {
    if (m_Arr[i]->GetKey() == y) {
      tempY = m_Arr[i];
      break;
    }
  }

  tempX = HelpNode(tempX);
  tempY = HelpNode(tempY);

  if (tempX != nullptr && tempY != nullptr) {
    if (tempX->GetRank() <= tempY->GetRank()) {
      tempX->SetParent(tempY);

      if (tempX->GetRank() == tempY->GetRank()) {
        tempY->SetRank(tempY->GetRank() + 1);
      }
    } else {
      tempY->SetParent(tempX);
    }
  }
}

int DisjointSets::Find(int key) {
  Node *temp = nullptr;
  for (int i = 0; i < size; i++) {
    if (m_Arr[i]->GetKey() == key) {
      temp = m_Arr[i];
      break;
    }
  }

  if (temp == nullptr) {
    return -1;
  } else {
    return HelpNode(temp)->GetKey();
  }
}

void DisjointSets::PathCompression(int value) {
  if (Find(value) == -1) {
    cout << "Cannot Find the value!\n";
    cout << "=====================================================\n";
    return;
  } else {
    Node *temp = nullptr;

    for (int i = 0; i < size; i++) {
      if (m_Arr[i]->GetKey() == value) {
        temp = m_Arr[i];
        break;
      }
    }

    Node *tempRoot = HelpNode(temp);

    if (tempRoot == temp) {
      cout << "The value cannot use PathCompression!\n";
      cout << "=====================================================\n";
      return;
    } else {
      temp->SetParent(nullptr);
      temp->SetParent(tempRoot);
    }
  }
}

void DisjointSets::PathPrint(int value) {
  if (Find(value) == -1) {
    cout << "Cannot Find the value!\n";
    cout << "=====================================================\n";
    return;
  } else {

    Node *temp = nullptr;

    for (int i = 0; i < size; i++) {
      if (m_Arr[i]->GetKey() == value) {
        temp = m_Arr[i];
        break;
      }
    }

    Node *tempRoot = HelpNode(temp);

    if (temp == tempRoot) {
      cout << "Output: The path for the element " << value << " is: " << value
           << " -> NULL";
    } else {
      cout << "Output: The path for the element " << value << " is: ";
      while (temp->GetParent() != nullptr) {
        cout << temp->GetKey();
        temp = temp->GetParent();
        if (temp->GetParent() != nullptr) {
          cout << "->";
        } else {
          cout << "->" << temp->GetKey() << "->Null\n";
        }
      }
    }
  }
}

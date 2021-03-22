#include "MinMax.h"
#include <math.h>
MinMax::MinMax() {
  m_Arr = new Node[MAXSIZE]();
  m_size = 0;
}

MinMax::~MinMax() { delete[] m_Arr; }

void MinMax::HeapifyMax(Node *arr, int size, int i) {
  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  int max = i;
  if (c1 < size && arr[c1].GetValue() > arr[max].GetValue()) {
    max = c1;
  }
  if (c2 < size && arr[c2].GetValue() > arr[max].GetValue()) {
    max = c2;
  }
  if (max != i) {
    swap(arr, max, i);
    HeapifyMax(arr, size, max);
  }
}

void MinMax::HeapifyMin(Node *arr, int size, int i) {
  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  int min = i;
  if (c1 < size && arr[c1].GetValue() < arr[min].GetValue() &&
      arr[c1].GetValue() << arr[c2].GetValue()) {
    min = c1;
  }
  if (c2 < size && arr[c2].GetValue() < arr[min].GetValue() &&
      arr[c1].GetValue() << arr[c2].GetValue()) {
    min = c2;
  }
  if (min != i) {
    swap(arr, min, i);
    HeapifyMin(arr, size, min);
  }
}

void MinMax::swap(Node *arr, int i, int j) {
  Node *temp = new Node(arr[i].GetValue());
  arr[i].SetValue(arr[j].GetValue());
  arr[j].SetValue(temp->GetValue());
  temp->SetValue(-1);
  delete temp;
}

int MinMax::GetHeight(Node *temp, int index) {
  int height = 0;
  while (temp[index].GetValue() != -1) {
    index = 2 * index + 1;
    height++;
  }
  return height;
}

int MinMax::GetSize() { return m_size; }

int MinMax::Find(int key) {
  for (int i = 0; i < m_size; i++) {
    if (m_Arr[i].GetValue() == key) {
      return i;
    }
  }
  return -1;
}

//=========================== Public Main Function ==================
void MinMax::BuildHeap() { BuildHeap(m_Arr, GetSize()); }

void MinMax::Insert(int key) { Insert(key, m_Arr); }

void MinMax::Delete(int key) { Delete(key, m_Arr); }

void MinMax::MinLevelElements() {
  int height = GetHeight(m_Arr, 0);
  for (int i = 1; i <= height; i++) {
    if ((i - 1) % 2 == 0) {
      if (i == 1) {
        cout << m_Arr[0].GetValue() << "," << endl;
      } else {
        int minNode = pow(2, i - 1);
        int leftNodeIndex = 0;
        int temp = 0;
        for (int j = 1; j < i; j++) {
          leftNodeIndex = 2 * temp + 1;
          temp = leftNodeIndex;
        }
        int count = 0;
        while (count < minNode) {
          if (m_Arr[count + leftNodeIndex].GetValue() != -1) {
            cout << m_Arr[leftNodeIndex + count].GetValue() << ",";
          }
          count++;
        }
        cout << endl;
      }
    }
  }
}

void MinMax::MaxLevelElements() {
  int height = GetHeight(m_Arr, 0);
  for (int i = 1; i <= height; i++) {
    if ((i - 1) % 2 == 1) {
      int minNode = pow(2, i - 1);
      int leftNodeIndex = 0;
      int temp = 0;
      for (int j = 1; j < i; j++) {
        leftNodeIndex = 2 * temp + 1;
        temp = leftNodeIndex;
      }
      int count = 0;
      while (count < minNode) {
        if (m_Arr[count + leftNodeIndex].GetValue() != -1) {
          cout << m_Arr[leftNodeIndex + count].GetValue() << ",";
        }
        count++;
      }
      cout << endl;
    }
  }
}

void MinMax::LevelOrder() {
  int height = GetHeight(m_Arr, 0);
  for (int i = 1; i <= height; i++) {
    if (i == 1) {
      cout << m_Arr[0].GetValue() << "," << endl;
    } else if (i >= 2) {
      int minNode = pow(2, i - 1);
      int leftNodeIndex = 0;
      int temp = 0;
      for (int j = 1; j < i; j++) {
        leftNodeIndex = 2 * temp + 1;
        temp = leftNodeIndex;
      }
      int count = 0;
      while (count < minNode) {
        if (m_Arr[count + leftNodeIndex].GetValue() != -1) {
          cout << m_Arr[leftNodeIndex + count].GetValue() << ",";
        }
        count++;
      }
      cout << endl;
    }
  }
}

//=========================== Private Main Function ==================
void MinMax::BuildHeap(Node *root, int size) {
  int last_node = size - 1;
  int parent = (last_node - 1) / 2;
  int i;

  int height = GetHeight(m_Arr, 0); // 4
  for (int j = 1; j <= height - 1; j++) {
    int maxNodeInCurrentLevel = pow(2, j - 1);
    int leftNodeIndex = 0;
    int temp = 0;
    for (int k = 1; k < j; k++) {
      leftNodeIndex = 2 * temp + 1;
      temp = leftNodeIndex;
    }

    int count = 0;
    while (count < maxNodeInCurrentLevel) {
      if (m_Arr[count + maxNodeInCurrentLevel].GetValue() != -1) {
        if ((height - 1 - j) % 2 == 0) {
          for (i = parent; i >= leftNodeIndex; i--) {
            HeapifyMin(m_Arr, size, i);
          }
        } else if ((height - 1 - j) % 2 == 1) {
          for (i = parent; i >= leftNodeIndex; i--) {
            HeapifyMax(m_Arr, size, i);
          }
        }
      }
      count++;
    }
  }
}

void MinMax::Insert(int key, Node *root) {
  m_Arr[m_size].SetValue(key);
  BuildHeap();
  m_size++;
}

void MinMax::Delete(int key, Node *root) {
  if (Find(key) == -1) {
    cout << "Cannot find the key in the tree!\n";
  } else {
    for (int i = Find(key); i < m_size; i++) {
      swap(m_Arr, i, i + 1);
    }
    m_Arr[m_size].SetValue(-1);
  }
  m_size--;
  BuildHeap(m_Arr, m_size);
}

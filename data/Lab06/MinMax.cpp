#include "MinMax.h"
#include <cmath>
#include <math.h>
#include <type_traits>
MinMax::MinMax() {
  m_Arr = new Node[MAXSIZE]();
  m_size = 0;
  m_index = -1;
}

MinMax::~MinMax() { delete[] m_Arr; }

void MinMax::Heapify(Node *arr, int size, int i, bool isMinLevel) {}

int MinMax::GetHeight(Node *temp, int index) {
  int height = 0;
  while (temp[index].GetValue() != -1) {
    index = 2 * index + 1;
    height++;
  }
  return height;
}

int MinMax::GetParent(int index) { return floor((index - 1) / 2); }

int MinMax::GetMaxNode(Node *arr, int index) {
  int returnIndex = 0;
  while (GetParent(index) != 0) {
    index = GetParent(index);
  }
  returnIndex = index;
  return returnIndex;
}

void MinMax::Swap(Node *arr, int i, int j) {
  Node *temp = new Node(arr[i].GetValue());
  arr[i].SetValue(arr[j].GetValue());
  arr[j].SetValue(temp->GetValue());
  temp->SetValue(-1);
  delete temp;
}

void MinMax::BuildHeap() {
  int height = GetHeight(m_Arr, 0);
  // cout << FindSecondSmallestIndex() << endl;
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

void MinMax::Delete() {
  if (m_size == 0) {
    throw -2;
  }
  if (m_size == 1) { // case 1: only one
    m_Arr[0].SetValue(-1);
  } else if (m_size == 2) { // case 2: have one child
    Swap(m_Arr, 0, 1);
    m_Arr[1].SetValue(-1);
  } else if (m_size >= 3) { // case 3: have more one child
    int secondIndex = GetSecondSmallestIndex();
    int smallvalue = m_Arr[secondIndex].GetValue();
    int lastvalue = m_Arr[m_size - 1].GetValue();
    if (lastvalue > smallvalue) {
      m_Arr[0].SetValue(smallvalue);
      m_Arr[secondIndex].SetValue(lastvalue);
      m_Arr[m_size - 1].SetValue(-1);
      int parent = GetParent(secondIndex);
      if (m_Arr[secondIndex].GetValue() < m_Arr[parent].GetValue()) {
        HeapifyMin(m_Arr, m_size, secondIndex);
      }
    }
  }
  m_size--;
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
    Swap(arr, min, i);
    HeapifyMin(arr, size, min);
  }
}

int MinMax::GetMinNode() { return m_Arr[0].GetValue(); }

bool MinMax::Find(int key) {
  for (int i = 0; i < m_size; i++) {
    if (m_Arr[i].GetValue() == key) {
      return true;
    }
  }
  return false;
}

int MinMax::GetDeleteIndex(int key) {
  int temp = -1;
  for (int i = 0; i < m_size; i++) {
    if (m_Arr[i].GetValue() == key) {
      temp = i;
    }
  }
  return temp;
}

int MinMax::GetSecondSmallestIndex() {
  int minIndex = 1;
  for (int i = 1; i < m_size; i++) {
    if (m_Arr[i].GetValue() < m_Arr[minIndex].GetValue()) {
      minIndex = i;
    }
  }
  return minIndex;
}

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

void MinMax::Insert(int key) { Insert(key, m_Arr); }

void MinMax::Insert(int key, Node *arr) {

  m_index++;
  if (m_index == 0) {
    arr[m_index].SetValue(key);
  } else {
    arr[m_index].SetValue(key);

    if (!isMinLevel) {
      int parent = GetParent(m_index);
      if (key < arr[parent].GetValue()) {
        Swap(arr, m_index, parent);
        if (arr[parent].GetValue() < arr[0].GetValue()) {
          Swap(arr, parent, 0);
        }
      } else if (key > arr[parent].GetValue()) {
        int maxNodeIndex = GetMaxNode(arr, m_index);
        Swap(arr, m_index, maxNodeIndex);
      }
    } else if (isMinLevel) {
      int parent = GetParent(m_index);
      if (key < arr[parent].GetValue()) {
        if (key < arr[0].GetValue()) {
          Swap(arr, m_index, 0);
        }
      } else if (key > arr[parent].GetValue()) {
        Swap(arr, m_index, parent);
      }
    }
  }
  m_size++;
  count++;
  if (count >= LevelChangeIndex) {
    LevelChangeIndex = pow(2, GetHeight(arr, 0));
    isMinLevel = !isMinLevel;
    count = 0;
  }
}

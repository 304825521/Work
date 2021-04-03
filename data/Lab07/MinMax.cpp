#include "MinMax.h"
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <type_traits>
MinMax::MinMax() {
  m_Arr = new Node[MAXSIZE]();
  m_size = 0;
  m_index = -1;
}

MinMax::~MinMax() { delete[] m_Arr; }

void MinMax::init() {
  m_size = 0;
  m_index = -1;
  height = 0;
  count = 0;
  LevelChangeIndex = pow(2, 0);
  isMinLevel = true;
}

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

void MinMax::DeleteMax() {
  if (m_size == 0) {
    throw -2;
  } else if (m_size == 1) {
    m_Arr[0].SetValue(-1);
  } else if (m_size == 2) {
    m_Arr[1].SetValue(-1);
  } else if (m_size == 3) {
    if (m_Arr[1].GetValue() > m_Arr[2].GetValue()) {
      Swap(m_Arr, 1, 2);
      m_Arr[2].SetValue(-1);
    }
  } else if (m_size >= 4) {
    int secondLargestIndex = 0;
    int removeLargerIndex = 0;
    if (m_Arr[1].GetValue() > m_Arr[2].GetValue()) {
      secondLargestIndex = GetSecondLargestIndex(2);
      removeLargerIndex = 1;
    } else {
      secondLargestIndex = GetSecondLargestIndex(3);
      removeLargerIndex = 2;
    }
    int lastvalue = m_Arr[m_size - 1].GetValue();
    if (lastvalue >= m_Arr[secondLargestIndex].GetValue()) {
      m_Arr[removeLargerIndex].SetValue(m_Arr[secondLargestIndex].GetValue());
      m_Arr[secondLargestIndex].SetValue(lastvalue);
      m_Arr[m_size - 1].SetValue(-1);
      HeapifyMax(m_Arr, m_size, removeLargerIndex);
    } else {
      m_Arr[removeLargerIndex].SetValue(m_Arr[secondLargestIndex].GetValue());
      m_Arr[secondLargestIndex].SetValue(lastvalue);
      m_Arr[m_size - 1].SetValue(-1);
      HeapifyMax(m_Arr, m_size, removeLargerIndex);
      HeapifyMax(m_Arr, m_size, secondLargestIndex);
    }
    // cout << "largest:" << m_Arr[secondLargestIndex].GetValue() << endl;
    m_size--;
  }
}
void MinMax::DeleteMin() {
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

void MinMax::HeapifyMax(Node *arr, int size, int i) {
  int c1 = 2 * i + 1;
  int c2 = 2 * i + 2;
  int max = i;
  if (c1 < size && arr[c1].GetValue() > arr[max].GetValue() &&
      arr[c1].GetValue() << arr[c2].GetValue()) {
    max = c1;
  }
  if (c2 < size && arr[c2].GetValue() > arr[max].GetValue() &&
      arr[c1].GetValue() << arr[c2].GetValue()) {
    max = c2;
  }
  if (max != i) {
    Swap(arr, max, i);
    HeapifyMin(arr, size, max);
  }
}

int MinMax::GetMinNode() { return m_Arr[0].GetValue(); }

int MinMax::FindMin() { return m_Arr[0].GetValue(); }

int MinMax::FindMax() {
  int first = m_Arr[1].GetValue();
  int second = m_Arr[2].GetValue();
  if (first > second) {
    return first;
  } else {
    return second;
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

void MinMax::ExperimentalProfiling() {
  string demension[6][6];
  clock_t startBuildHeap, finishBuildHeap;
  clock_t startFindMinHeap, finishFindMinHeap;
  clock_t startFindMaxHeap, finishFindMaxHeap;
  clock_t startDeleteMinHeap, finishDeleteMinHeap;
  clock_t startDeleteMaxHeap, finishDeleteMaxHeap;
  demension[0][0] = "Input size";
  demension[0][1] = "100,000";
  demension[0][2] = "200,000";
  demension[0][3] = "300,000";
  demension[0][4] = "400,000";
  demension[0][5] = "500,000";
  demension[1][0] = "BuildHeap(s)";
  demension[2][0] = "FindMin(s)";
  demension[3][0] = "FindMax(s)";
  demension[4][0] = "DeleteMin(s)";
  demension[5][0] = "DeleteMax(s)";
  int index = 1;
  cout << "Please Waiting a second!\n";
  for (int i = 1; i <= 5; i++) {
    int num;
    srand(time(NULL));
    int size = i * 100000;
    Node *temp = m_Arr;
    delete[] temp;
    m_Arr = new Node[size]();
    init();

    // ---------------- step 1 -----------------------
    startBuildHeap = clock();
    for (int j = 0; j < size; j++) {
      num = rand() % 500000 + 1;
      Insert(num);
      // cout << num << endl;
    }
    finishBuildHeap = clock();
    string storeRecordTime = doubleToString(
        (double)(finishBuildHeap - startBuildHeap) / CLOCKS_PER_SEC);
    cout << endl;
    demension[1][index] = storeRecordTime;

    // ---------------- step 2 -----------------------
    startFindMinHeap = clock();
    FindMin();
    finishFindMinHeap = clock();
    string storeRecordTime01 = doubleToString(
        (double)(finishFindMinHeap - startFindMinHeap) / CLOCKS_PER_SEC);
    demension[2][index] = storeRecordTime01;

    // ---------------- step 3 -----------------------
    startFindMaxHeap = clock();
    FindMax();
    finishFindMaxHeap = clock();
    string storeRecordTime02 = doubleToString(
        (double)(finishFindMaxHeap - startFindMaxHeap) / CLOCKS_PER_SEC);
    demension[3][index] = storeRecordTime02;

    // ---------------- step 4 -----------------------
    startDeleteMinHeap = clock();
    DeleteMin();
    finishDeleteMinHeap = clock();
    string storeRecordTime03 = doubleToString(
        (double)(finishDeleteMinHeap - startDeleteMinHeap) / CLOCKS_PER_SEC);
    demension[4][index] = storeRecordTime03;

    // ---------------- step 5 -----------------------
    startDeleteMaxHeap = clock();
    DeleteMax();
    finishDeleteMaxHeap = clock();
    string storeRecordTime04 = doubleToString(
        (double)(finishDeleteMaxHeap - startDeleteMaxHeap) / CLOCKS_PER_SEC);
    demension[5][index] = storeRecordTime04;

    index++;
    cout << "Done loop " << i << endl << endl;
  }
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      cout << demension[i][j] << "    ";
    }
    cout << endl << endl << endl;
  }
}

string MinMax::doubleToString(double temp) {
  string storeRecordTime = to_string(temp);
  return storeRecordTime;
}

void MinMax::ClearTree(int size, Node *arr) {
  for (int i = 0; i < size; i++) {
    arr[i].SetValue(-1);
  }
}

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

int MinMax::GetSecondLargestIndex(int index) {
  int maxIndex = index;
  for (int i = index; i < m_size; i++) {
    if (m_Arr[i].GetValue() > m_Arr[maxIndex].GetValue()) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

void MinMax::Insert(int key) { Insert(key, m_Arr); }

void MinMax::Insert(int key, Node *arr) {
  m_index++;
  if (m_index == 0) {
    arr[0].SetValue(key);
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

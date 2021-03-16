#include "minHeap.h"

minHeap::minHeap() {
  minNodeArr = new Node[MAXSIZE + 1]();
  for (int i = 0; i < MAXSIZE; i++) {
    minNodeArr[i].SetValue("", 0, 0);
  }
  size = 0;
}

void minHeap::Insert(string name, float distance, int count_view) {
  if (findName(name)) {
    throw 1;
  }
  minNodeArr[size].SetValue(name, distance, count_view);
  size++;
}

int minHeap::GetSize() { return size; }

bool minHeap::isEmpty() {
  if (GetSize() == 0) {
    return true;
  }
  return false;
}

void minHeap::printTest() {
  for (int i = 0; i < GetSize(); i++) {
    std::cout << minNodeArr[i].GetName() << "," << minNodeArr[i].GetDistance()
              << "," << minNodeArr[i].GetCountView() << endl;
  }
}

void minHeap::heapify(Node *arr, int size, int i) {
  if (i >= size) {
    return;
  }
  int c1 = 3 * i + 1;
  int c2 = 3 * i + 2;
  int c3 = 3 * i + 3;
  int maxIndex = i;
  if (c1 < size && arr[c1].GetDistance() > arr[maxIndex].GetDistance() &&
      arr[c1].GetDistance() > arr[c2].GetDistance() &&
      arr[c1].GetDistance() > arr[c3].GetDistance()) {
    maxIndex = c1;
  }
  if (c2 < size && arr[c2].GetDistance() > arr[maxIndex].GetDistance() &&
      arr[c2].GetDistance() > arr[c1].GetDistance() &&
      arr[c2].GetDistance() > arr[c3].GetDistance()) {
    maxIndex = c2;
  }
  if (c3 < size && arr[c3].GetDistance() > arr[maxIndex].GetDistance() &&
      arr[c3].GetDistance() > arr[c1].GetDistance() &&
      arr[c3].GetDistance() > arr[c2].GetDistance()) {
    maxIndex = c3;
  }
  if (maxIndex != i) {
    swap(arr, maxIndex, i);
    heapify(arr, size, maxIndex);
  }
}

bool minHeap::findName(string name) {
  for (int i = 0; i < size; i++) {
    if (minNodeArr[i].GetName() == name) {
      return true;
    }
  }
  return false;
}

void minHeap::swap(Node *arr, int i, int j) {
  Node *temp =
      new Node(arr[i].GetName(), arr[i].GetDistance(), arr[i].GetCountView());

  arr[i].SetValue(arr[j].GetName(), arr[j].GetDistance(),
                  arr[j].GetCountView());
  arr[j].SetValue(temp->GetName(), temp->GetDistance(), temp->GetCountView());
  temp = nullptr;
  delete temp;
}

minHeap::~minHeap() { delete[] minNodeArr; }

#include "minHeap.h"

minHeap::minHeap() {
  minHeapArr = new Node[MAXSIZE]();
  size = 0;
  index = -1;
}

void minHeap::Insert(string name, float distance, int count_view) {
  index++;
  minHeapArr[index].SetValue(name, distance, count_view);
  size++;
  buildHeap();
}

int minHeap::GetSize() { return size; }

bool minHeap::isEmpty() {
  if (GetSize() == 0) {
    return true;
  }
  return false;
}

void minHeap::LevelOrder() {
  int height = GetHeight(minHeapArr, 0);
  for (int i = 1; i <= height; i++) {
    if (i == 1) {
      cout << minHeapArr[0].GetName() << endl;
    } else if (i >= 2) {
      //@tag: minNode in current Node
      int minNode = pow(3, i - 1);
      int leftNodeIndex = 0;
      int temp = 0;
      for (int j = 1; j < i; j++) {
        leftNodeIndex = 3 * temp + 1;
        temp = leftNodeIndex;
      }
      // cout << "LeftNodeIndex: " << leftNodeIndex << endl;
      int count = 0;
      while (count < minNode) {
        if (minHeapArr[count + leftNodeIndex].GetCountView() != 0) {
          cout << minHeapArr[leftNodeIndex + count].GetName() << ":";
        }
        count++;
      }
      cout << endl;
    }
  }
}

void minHeap::heapify(Node *arr, int size, int i) {
  if (i >= size) {
    return;
  }
  int c1 = 3 * i + 1;
  int c2 = 3 * i + 2;
  int c3 = 3 * i + 3;
  int minIndex = i;
  if (c1 < size && arr[c1].GetDistance() < arr[minIndex].GetDistance()) {
    minIndex = c1;
  }
  if (c2 < size && arr[c2].GetDistance() < arr[minIndex].GetDistance()) {
    minIndex = c2;
  }
  if (c3 < size && arr[c3].GetDistance() < arr[minIndex].GetDistance()) {
    minIndex = c3;
  }
  if (minIndex != i) {
    swap(arr, minIndex, i);
    heapify(arr, size, minIndex);
  }
}

void minHeap::buildHeap() { buildHeap(minHeapArr, GetSize()); }

bool minHeap::findName(string name, float distance, int count_review) {
  for (int i = 0; i < size; i++) {
    if (minHeapArr[i].GetName() == name &&
        minHeapArr[i].GetDistance() == distance &&
        minHeapArr[i].GetCountView() == count_review) {
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
  temp->SetValue("", 0, 0);
  delete temp;
}

int minHeap::GetHeight(Node *temp, int index) {
  int height = 0;
  while (temp[index].GetCountView() != 0) {
    index = 3 * index + 1;
    height++;
  }
  return height;
}

void minHeap::buildHeap(Node *arr, int size) {
  int parentNode = floor((index - 1) / 3);
  for (int i = parentNode; i >= 0; i--) {
    heapify(arr, size, i);
  }
}

void minHeap::SearchNearestRestaurant() {
  cout << "Nearest restaurant: " << minHeapArr[0].GetName() << endl;
  cout << "Distance " << minHeapArr[0].GetDistance() << " miles" << endl;
  cout << "============================================\n";
}

void minHeap::RemoveNearestRestaurant() {
  string name = minHeapArr[0].GetName();
  int distance = minHeapArr[0].GetDistance();
  cout << "Most reviewed restaurant:" << name << ":" << distance
       << " has been removed.\n";
  for (int i = 0; i < size; i++) {
    swap(minHeapArr, i, i + 1);
  }
  minHeapArr[size].SetValue("", 0, 0);
  size--;
  buildHeap(minHeapArr, size);
}

minHeap::~minHeap() { delete[] minHeapArr; }

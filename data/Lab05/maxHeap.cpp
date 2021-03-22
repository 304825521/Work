#include "maxHeap.h"
#include <cmath>

maxHeap::maxHeap() {
  maxHeapArr = new Node[MAXSIZE]();
  size = 0;
}

void maxHeap::Insert(string name, float distance, int count_view) {
  maxHeapArr[size].SetValue(name, distance, count_view);
  size++;
}

int maxHeap::GetSize() { return size; }

bool maxHeap::isEmpty() {
  if (GetSize() == 0) {
    return true;
  }
  return false;
}

void maxHeap::LevelOrder() {
  //@done: print the heap
  int height = GetHeight(maxHeapArr, 0);
  for (int i = 1; i <= height; i++) {
    if (i == 1) {
      cout << maxHeapArr[0].GetName() << endl;
    } else if (i >= 2) {
      //@tag: maxNode in current Node
      int maxNode = pow(3, i - 1);
      int leftNodeIndex = 0;
      int temp = 0;
      for (int j = 1; j < i; j++) {
        leftNodeIndex = 3 * temp + 1;
        temp = leftNodeIndex;
      }
      // cout << "LeftNodeIndex: " << leftNodeIndex << endl;
      int count = 0;
      while (count < maxNode) {
        if (maxHeapArr[count + leftNodeIndex].GetCountView() != 0) {
          cout << maxHeapArr[leftNodeIndex + count].GetName() << ":";
        }

        count++;
      }
      cout << endl;
    }
  }
}

void maxHeap::SearchMostReviewedRestaurant() {
  cout << "Most reviewed restaurant: " << maxHeapArr[0].GetName() << endl;
  cout << "Number of reviews: " << maxHeapArr[0].GetCountView() << endl;
}

void maxHeap::RemoveMostReviewedRestaurant() {
  string name = maxHeapArr[0].GetName();
  int reviews = maxHeapArr[0].GetCountView();
  cout << "Most reviewed restaurant:" << name << ":" << reviews
       << " has been removed.\n";
  for (int i = 0; i < size; i++) {
    swap(maxHeapArr, i, i + 1);
  }
  maxHeapArr[size].SetValue("", 0, 0);
  size--;
  buildHeap(maxHeapArr, size);
}

void maxHeap::heapify(Node *arr, int size, int i) {
  if (i >= size) {
    return;
  }
  int c1 = 3 * i + 1;
  int c2 = 3 * i + 2;
  int c3 = 3 * i + 3;
  int maxIndex = i;
  if (c1 < size && arr[c1].GetCountView() > arr[maxIndex].GetCountView() &&
      arr[c1].GetCountView() > arr[c2].GetCountView() &&
      arr[c1].GetCountView() > arr[c3].GetCountView()) {
    maxIndex = c1;
  }
  if (c2 < size && arr[c2].GetCountView() > arr[maxIndex].GetCountView() &&
      arr[c2].GetCountView() > arr[c1].GetCountView() &&
      arr[c2].GetCountView() > arr[c3].GetCountView()) {
    maxIndex = c2;
  }
  if (c3 < size && arr[c3].GetCountView() > arr[maxIndex].GetCountView() &&
      arr[c3].GetCountView() > arr[c1].GetCountView() &&
      arr[c3].GetCountView() > arr[c2].GetCountView()) {
    maxIndex = c3;
  }
  if (maxIndex != i) {
    swap(arr, maxIndex, i);
    heapify(arr, size, maxIndex);
  }
}

bool maxHeap::findName(string name, float distance, int count_review) {
  for (int i = 0; i < size; i++) {
    if (maxHeapArr[i].GetName() == name &&
        maxHeapArr[i].GetDistance() == distance &&
        maxHeapArr[i].GetCountView() == count_review) {
      return true;
    }
  }
  return false;
}

void maxHeap::swap(Node *arr, int i, int j) {
  Node *temp =
      new Node(arr[i].GetName(), arr[i].GetDistance(), arr[i].GetCountView());

  arr[i].SetValue(arr[j].GetName(), arr[j].GetDistance(),
                  arr[j].GetCountView());
  arr[j].SetValue(temp->GetName(), temp->GetDistance(), temp->GetCountView());
  temp->SetValue("", 0, 0);
  delete temp;
}

int maxHeap::GetHeight(Node *temp, int index) {
  int height = 0;
  while (temp[index].GetCountView() != 0) {
    index = 3 * index + 1;
    height++;
  }
  return height;
}

void maxHeap::buildHeap() { buildHeap(maxHeapArr, GetSize()); }

void maxHeap::buildHeap(Node *arr, int size) {
  int last_node_Index = size - 1;
  int parentNode = floor((last_node_Index - 1) / 3);
  for (int i = parentNode; i >= 0; i--) {
    heapify(arr, size, i);
  }
}

maxHeap::~maxHeap() { delete[] maxHeapArr; }

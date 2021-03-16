#include "maxHeap.h"
#include "minHeap.h"
#include <cmath>

maxHeap::maxHeap() {
  maxHeapArr = new Node[MAXSIZE + 1]();
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
  // int i = 1;
  // int levelSize = 3;
  // if (size > 0) {
  //   std::cout << maxHeapArr[0].GetName() << "\n";
  // }
  // if (size > 1) {
  //   while (i < size) {
  //     do {
  //       Print(i);
  //       i = i + 3;
  //     } while (i <= levelSize || maxHeapArr[i].GetCountView() == 0);
  //     levelSize = levelSize * 3 + levelSize;
  //     std::cout << "\n";
  //   }
  // }
}

void maxHeap::Print(int index) {
  int i = 0;
  while (i < 3 && maxHeapArr[index].GetCountView() != 0) {
    cout << maxHeapArr[index].GetName() << ":";
    i++;
    index++;
  }
}

void maxHeap::SearchMostReviewedRestaurant() {
  cout << "Most reviewed restaurant: " << maxHeapArr[0].GetName() << endl;
  cout << "Number of reviews: " << maxHeapArr[0].GetCountView() << endl;
  cout << "============================================\n";
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

void maxHeap::buildHeap() { buildHeap(maxHeapArr, GetSize()); }

void maxHeap::buildHeap(Node *arr, int size) {
  int last_node_Index = size - 1;
  int parentNode = floor((last_node_Index - 1) / 3);
  for (int i = parentNode; i >= 0; i--) {
    heapify(arr, size, i);
  }
}

maxHeap::~maxHeap() { delete[] maxHeapArr; }

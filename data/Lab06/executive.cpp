#include "executive.h"
#include <stdexcept>
#include <string>

executive::executive(std::string _filename) {
  ifstream input;
  string name;
  float distance;
  int count_review;
  string temp;
  input.open(_filename);
  if (input.is_open()) {
    while (!input.eof()) {
      getline(input, temp, ',');
      int num = stoi(temp);
      myheap.Insert(num);
    }
  } else {
    cout << "Cannot open the files!\n";
  }
  input.close();
  myheap.BuildHeap();
  Print();
}

executive::~executive() {}

void executive::Print() {
  try {
    while (true) {

      cout << "Please choice one of the following commands:\n";
      cout << "1- BuildHeap\n2- Insert\n3- Delete\n4- MinLevelElements\n5- "
              "MaxLevelElements\n6- Exit\n";
      cout << "Enter your choice:\n";
      int choice;
      cin >> choice;
      cout << "=====================================================\n";
      if (choice == 1) {
        cout << "Output:\n";
        myheap.LevelOrder();
        cout << "=====================================================\n";
      } else if (choice == 2) {
        cout << "Enter element to be inserted:";
        int key;
        cin >> key;
        myheap.Insert(key);
        cout << "Output: " << key << " has been inserted successfully!\n";
        cout << "=====================================================\n";
      } else if (choice == 3) {
        cout << "Enter element to be Deleted:";
        int key;
        cin >> key;
        myheap.Delete(key);
        cout << "Output: " << key << " has been deleted successfully!\n";
        cout << "=====================================================\n";
      } else if (choice == 4) {
        myheap.MinLevelElements();
        cout << "=====================================================\n";
      } else if (choice == 5) {
        myheap.MaxLevelElements();
        cout << "=====================================================\n";
      } else if (choice == 6) {
        cout << "Output: Bye Bye!\n";
        cout << "=========================================================\n";
        break;
      } else {
        throw -1;
        break;
      }
    }
  } catch (int num) {
    if (num == -1) {
      cout << "Input Error!\n";
      cout << "=========================================================\n";
    }
  }
}

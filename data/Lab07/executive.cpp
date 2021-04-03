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
  Print();
  // myTest.ExperimentalProfiling();
}

executive::~executive() {}

void executive::Print() {
  try {
    while (true) {

      cout << "Please choice one of the following commands:\n";
      cout
          << "1- BuildHeap\n2- Insert\n3- DeleteMin\n4- DeleteMax\n5- "
             "FindMin\n6- FindMax\n7- LevelOrder\n8- ExperimentalProfiling\n9- "
             "Exit\n";
      cout << "Enter your choice:\n";
      int choice;
      cin >> choice;
      cout << "=====================================================\n";
      if (choice == 1) {
        cout << "Output:\n";
        myheap.BuildHeap();
        cout << "=====================================================\n";
      } else if (choice == 2) {
        cout << "Enter element to be inserted:";
        int key;
        cin >> key;
        myheap.Insert(key);
        cout << "Output: " << key << " has been inserted successfully!\n";
        cout << "=====================================================\n";
      } else if (choice == 3) {
        int min = myheap.GetMinNode();
        myheap.DeleteMin();
        cout << "Output: " << min << " has been deleted successfully!\n";
        cout << "=====================================================\n";
      } else if (choice == 4) {
        //@todo: fix the question
        int max = myheap.FindMax();
        myheap.DeleteMax();
        cout << "Output: " << max << " has been deleted successfully!\n";
        cout << "=====================================================\n";
        cout << "=====================================================\n";
      } else if (choice == 5) {
        cout << "Output:" << myheap.FindMin() << " is the minimum element!\n";

        cout << "=====================================================\n";
      } else if (choice == 6) {
        cout << "Output:" << myheap.FindMax() << " is the maximun element!\n";

        cout << "=====================================================\n";
      } else if (choice == 7) {
        myheap.LevelOrder();
        cout << "=====================================================\n";

      } else if (choice == 8) {
        myTest.ExperimentalProfiling();
        cout << "=========================================================\n";
      } else if (choice == 9) {
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
    } else if (num == -2) {
      cout << "Delete the empty tree!\n";
      cout << "=========================================================\n";
      exit(1);
    }
  }
}

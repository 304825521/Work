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
      //@todo:Insert number
    }
  } else {
    cout << "Cannot open the files!\n";
  }
  input.close();
  Print();
}

executive::~executive() {}

void executive::Print() {
  //@todo: when finished the leftListHeap.cpp to do this
  try {
    while (true) {

      cout << "Please choice one of the following commands:\n";
      cout << "1- BuildHeap\n2- Insert\n3- Concatenate\n4- DeleteMin\n5- "
              "FindMin\n6- Inorder\n7- LevelOrder\n\n8- "
              "Exit\n";
      cout << "Enter your choice:\n";
      int choice;
      cin >> choice;
      cout << "=====================================================\n";
      if (choice == 1) {

        cout << "=====================================================\n";
      } else if (choice == 2) {

        cout << "=====================================================\n";
      } else if (choice == 3) {

        cout << "=====================================================\n";
      } else if (choice == 4) {

        cout << "=====================================================\n";
      } else if (choice == 5) {

        cout << "=====================================================\n";
      } else if (choice == 6) {

        cout << "=====================================================\n";
      } else if (choice == 7) {

        cout << "=====================================================\n";

      } else if (choice == 8) {
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

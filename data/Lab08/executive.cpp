#include "executive.h"
#include "LeftListHeap.h"
#include <stdexcept>
#include <string>

executive::executive(std::string _filename) {
  ifstream input;
  string name;
  float distance;
  int count_review;
  string temp;
  int count = 0;
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
}

executive::~executive() {}

void executive::Print() {
  try {
    while (true) {

      cout << "Please choice one of the following commands:\n";
      cout << "1- BuildHeap\n2- Insert\n3- Concatenate\n4- DeleteMin\n5- "
              "FindMin\n6- Inorder\n7- LevelOrder\n8- "
              "Exit\n";
      cout << "Enter your choice:\n";
      int choice;
      cin >> choice;
      cout << "=====================================================\n";
      if (choice == 1) {
        myheap.BuildHeap();
        cout << endl;
        cout << "=====================================================\n";
      } else if (choice == 2) {
        cout << "Output: Enter the value you want to insert:";
        int num;
        cin >> num;
        myheap.Insert(num);
        cout << num
             << " has been successfully inserted into the heap. THe new level "
                "order traversal is:";
        myheap.LevelOrder();
        cout << endl;
        cout << "=====================================================\n";
      } else if (choice == 3) {
        bool check = false;
        cout << "\nEnter first value of your new heap (positive, unique "
                "integers only please): ";
        int first = 0;
        cin >> first;
        LeftListHeap h2;
        h2.Insert(first);
        if (h2.Isswapped()) {
          check = true;
        }
        cout << "Enter second value of your new heap: ";
        int second = 0;
        cin >> second;
        h2.Insert(second);
        if (h2.Isswapped()) {
          check = true;
        }
        cout << "Enter the third value of your new heap: ";
        int third = 0;
        cin >> third;
        h2.Insert(third);
        if (h2.Isswapped()) {
          check = true;
        }
        myheap.SetRoot(myheap.Merge(myheap.GetRoot(), h2.GetRoot()));
        cout
            << "\nOutput: Trees A and B have been merged to form new tree C!\n";
        if (check) {
          cout << "Subtrees have been swapped!\n";
        }
        cout << "The new level order traversal is:";
        myheap.LevelOrder();
        cout << endl;
        cout << "=====================================================\n";
      } else if (choice == 4) {
        int min = myheap.GetRoot()->GetKey();
        myheap.DeleteMin();
        cout << "Output: The minimum element " << min
             << " has been deleted. The new level order traversal is:";
        myheap.LevelOrder();
        cout << endl;
        cout << "=====================================================\n";
      } else if (choice == 5) {
        int min = myheap.GetRoot()->GetKey();
        cout << "Output: The minimum element is:" << min << endl;
        cout << "=====================================================\n";
      } else if (choice == 6) {
        cout << "Output: The in order traversal for the heap is:";
        myheap.Inorder();
        cout << endl;
        cout << "=====================================================\n";
      } else if (choice == 7) {
        cout << "Output: The level order traversal for the heap is:";
        myheap.LevelOrder();
        cout << endl;
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

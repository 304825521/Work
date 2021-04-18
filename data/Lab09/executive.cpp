#include "executive.h"
#include <stdexcept>
#include <string>

executive::executive(std::string _filename) {
  ifstream input;
  int temp;
  int count = 0;
  input.open(_filename);
  if (input.is_open()) {
    while (!input.eof()) {
      input >> temp;
      array[m_size] = temp;
      m_size++;
    }
  } else {
    cout << "Cannot open the files!\n";
  }
  input.close();
  Print();
  // mySet.MakeSet(array, m_size);
  // mySet.SetUnionByRank(1, 2);
  // mySet.SetUnionByRank(3, 4);
  // mySet.SetUnionByRank(5, 6);
  // mySet.SetUnionByRank(7, 8);
  // mySet.SetUnionByRank(2, 4);
  // mySet.SetUnionByRank(2, 5);
  // mySet.SetUnionByRank(6, 8);
  // mySet.PathPrint(1);
  // mySet.PathCompression(7);
  // mySet.PathCompression(1);
  // mySet.PathPrint(1);
}

executive::~executive() {}

void executive::Print() {
  try {
    while (true) {

      cout << "Please choice one of the following commands:\n";
      cout << "1- MakeSet\n2- UnionByRank\n3- Find\n4- PathCompression\n";
      cout << "5- PrintPath\n6- Exit\n";
      cout << "Enter your choice:\n";
      int choice;
      cin >> choice;
      cout << "=====================================================\n";
      if (choice == 1) {
        mySet.MakeSet(array, m_size);
        cout << "Output: The disjoint sets have been constructed!\n";
        cout << "=====================================================\n";
      } else if (choice == 2) {
        int num1, num2;
        cout << "Output: Enter the representative elements for the two sets "
                "which you wish to union:\n";
        cout << "Enter first number:";
        cin >> num1;
        cout << "Enter Second number:";
        cin >> num2;
        mySet.SetUnionByRank(num1, num2);
        cout << "Output: Union on " << num1 << " and " << num2
             << " has been done. The represnetative element is "
             << mySet.GetRepresentValue(num2) << endl;
        cout << "=====================================================\n";
      } else if (choice == 3) {
        int num;
        cout << "Output: Enter the element you want to find:";
        cin >> num;
        int find = mySet.Find(num);
        if (find == -1) {
          cout << "Sorry! " << num << " is not found!\n";
        } else {
          cout << "Output: Element " << num << " has been found successfully."
               << "The representative element is "
               << mySet.GetRepresentValue(num) << endl;
        }
        cout << "=====================================================\n";
      } else if (choice == 4) {
        int num = 0;
        cout << "Output: Enter the element on whose set you would want to "
                "perform path compression.\n";
        cin >> num;
        mySet.PathCompression(num);
        cout << "Output: Path compression has been done successfully."
             << "The representative element is " << mySet.GetRepresentValue(num)
             << endl;
        cout << "=====================================================\n";
      } else if (choice == 5) {
        cout << "Output: Enter the element you want to find the path for:";
        int num;
        cin >> num;
        mySet.PathPrint(num);
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
    } else if (num == -2) {
      cout << "Delete the empty tree!\n";
      cout << "=========================================================\n";
      exit(1);
    }
  }
}

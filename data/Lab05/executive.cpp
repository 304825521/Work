#include "executive.h"
#include "minHeap.h"
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
      //@done:Get and process the data
      getline(input, temp, '\n');
      int firstIndex = temp.find(",");
      name = temp.substr(0, firstIndex);
      string newtemp = temp.substr(firstIndex + 1);
      int secondIndex = newtemp.find(",");
      string Distance = newtemp.substr(0, secondIndex);
      distance = stof(Distance);
      string Count_view = newtemp.substr(secondIndex + 1);
      count_review = stoi(Count_view);
      //@done: Insert the data into node
      maxheap.Insert(name, distance, count_review);
      minheap.Insert(name, distance, count_review);
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
    int choice = 0;
    while (true) {
      cout << "Restaurant Management System:\n\n"
           << "1- Add New Restaurant\n2- Remove Nearest Restaurant\n"
           << "3- Remove Most Reviewed Restaurant\n"
           << "4- Search Nearest Restaurant\n5- Search Most Reviewed "
              "Restaurant\n"
           << "6- Print By Restaurant Distance\n"
           << "7- Print By Restaurant Review Count\n"
           << "8- Exit\n\n";

      cout << "Please enter you choice to pick:";
      cin >> choice;
      cout << "=========================================================\n";
      if (choice == 1) {
        string temp = "";
        string name;
        float distance;
        int count_review;
        cout << "Enter the record to be inserted:\n";
        //@done:Get and process the data
        cin >> temp;
        cout << "=========================================================\n";
        int firstIndex = temp.find(",");
        name = temp.substr(0, firstIndex);
        string newtemp = temp.substr(firstIndex + 1);
        int secondIndex = newtemp.find(",");
        string Distance = newtemp.substr(0, secondIndex);
        distance = stof(Distance);
        string Count_view = newtemp.substr(secondIndex + 1);
        count_review = stoi(Count_view);
        //@done: Insert the data into node
        //@todo:minheap is not finished
        if (maxheap.findName(name, distance, count_review) &&
            minheap.findName(name, distance, count_review)) {
          throw -1;
        } else {
          maxheap.Insert(name, distance, count_review);
          minheap.Insert(name, distance, count_review);
          cout << "Output: Record is successfully inserted.\n";
          cout << "=========================================================\n";
        }
      } else if (choice == 2) {
        minheap.RemoveNearestRestaurant();
        cout << "=========================================================\n";
      } else if (choice == 3) {
        maxheap.RemoveMostReviewedRestaurant();
        cout << "=========================================================\n";
      } else if (choice == 4) {
        minheap.SearchNearestRestaurant();
      } else if (choice == 5) {
        maxheap.SearchMostReviewedRestaurant();
        cout << "=========================================================\n";
      } else if (choice == 6) {
        cout << "by distance\n";
        minheap.LevelOrder();
        cout << "=========================================================\n";
      } else if (choice == 7) {
        cout << "by Review Count\n";
        maxheap.LevelOrder();
        cout << "=========================================================\n\n";
      } else if (choice == 8) {
        cout << "Bye Bye !!\n";
        cout << "=========================================================\n";
        break;
      } else {
        throw -2;
      }
    }
  } catch (int errorNumber) {
    if (errorNumber == -1) {
      cout << "\n";
      cout << "=========================================================\n";
      cout << "Duplicate restaurants are not allowed.\n";
      cout << "=========================================================\n";
    } else if (errorNumber == -2) {
      cout << "Input Error!\n";
      cout << "=========================================================\n";
    }
  }
}

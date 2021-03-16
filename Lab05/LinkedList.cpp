#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
  length = 0;
}

LinkedList::~LinkedList() { Remove(); }

void LinkedList::Insert(std::string name, int id) {
  if (length == 0) {
    head = new Node(name, id);
    tail = head;
  } else if (length == 1) {
    tail = new Node(name, id);
    head->SetNext(tail);
  } else if (length > 1) {
    Node *temp = new Node(name, id);
    tail->SetNext(temp);
    tail = temp;
    temp = nullptr;
  }
  length++;
}

bool LinkedList::Remove(std::string name, int id) {
  bool remove = false;
  Node *temp = head;
  while (true) {
    if (temp->GetID() == id && temp->GetName() == name) {
      if (head->getNext() == nullptr) {
        delete temp;
        head = nullptr;
        tail = nullptr;
        remove = true;
        break;
      } else {
        if (head->getNext() == tail) {
          if (temp == head) {
            head = tail;
            delete temp;
            remove = true;
            break;
          } else if (temp == tail) {
            tail = head;
            head->SetNext(nullptr);
            delete temp;
            remove = true;
            break;
          }
        } else {
          if (temp->getNext() == tail) {
            Node *before = head;
            while (before->getNext() != temp)
              before = before->getNext();
            before->SetNext(tail);
            temp->SetNext(nullptr);
            delete temp;
            remove = true;
            break;
          } else if (head->getNext() == temp) {
            head->SetNext(temp->getNext());
            temp->SetNext(nullptr);
            delete temp;
            remove = true;
            break;
          } else {
            Node *before = head;
            while (before->getNext() != temp)
              before = before->getNext();
            before->SetNext(temp->getNext());
            temp->SetNext(nullptr);
            delete temp;
            remove = true;
            break;
          }
        }
      }
    } else {
      if (temp->getNext() != nullptr) {
        temp = temp->getNext();
      } else {
        break;
      }
    }
  }
  return remove;
}

bool LinkedList::Find(std::string name) {
  Node *find = head;
  bool Find = false;
  while (find != tail) {
    if (find->GetName() == name) {
      Find = true;
      break;
    } else {
      find = find->getNext();
    }
  }
  if (tail->GetName() == name) {
    Find = true;
  }
  return Find;
}

void LinkedList::Remove() {
  if (head == tail) {
    delete head;
  } else if (head->getNext() == tail) {
    delete tail;
    tail = head;
    delete head;
  } else if (head->getNext() != tail) {
    while (tail != head) {
      Node *temp = head;
      while (temp->getNext() != tail) {
        temp = temp->getNext();
      }
      delete tail;
      tail = temp;
      temp = nullptr;
    }
    delete head;
  } else if (head == nullptr) {
    delete head;
  }
}

void LinkedList::Print() {
  if (head == nullptr)
    return;
  else {
    Node *temp = head;
    while (temp->getNext() != nullptr) {
      std::cout << " => " << temp->GetID() << " " << temp->GetName();
      temp = temp->getNext();
    }
    std::cout << " => " << temp->GetID() << " " << temp->GetName();
  }
}

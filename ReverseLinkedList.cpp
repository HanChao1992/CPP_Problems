#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

struct node {
  int number;
  node * next;
};

void addNode(node * head, int n) {
  if(head->next != NULL) {
    addNode(head->next, n);
  }
  else {
    node * added = new node;
    added->number = n;
    added->next = NULL;
    head->next = added;
  }
}

node * reverseList(node * head) {
  node * cursor = NULL;
  node * next;
  while (head != NULL) {
    next = head->next;
    head->next = cursor;
    cursor = head;
    head = next;
  }
  return cursor;
}

void printList (node * head) {
  node * temp;
  temp = head;
  while (temp != NULL) {
    cout << temp->number << ">>";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

void destroyList(node * head) {
  node * temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {
  node * root = new node;
  root->number = 1;
  root->next = NULL;
  addNode(root, 2);
  addNode(root, 3);
  printList(root);
  root = reverseList(root);

  printList(root);
  destroyList(root);
}

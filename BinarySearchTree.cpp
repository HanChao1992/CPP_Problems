#include <stdlib.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node {
  int value;
  node * left;
  node * right;
};

void addNode(node * root, int n) {
  if(root == NULL) {
    cout << "Invalid" << endl;
  }
  else if (root->value < n) {
    if (!root->right) {
      root->right = new node;
      root->right->value = n;
    }
    else {
      addNode(root->right, n);
    }
  }
  else if (root->value > n) {
    if (!root->left) {
      root->left = new node;
      root->left->value = n;
    }
    else {
      addNode(root->left, n);
    }
  }
}

bool searchNode(node * root, int n) {
  if (root) {
    if (root->value == n){
      return true;
    }
    else if (root->value < n) {
      return searchNode(root->right, n);
    }
    else if (root->value > n) {
      return searchNode(root->left, n);
    }
    //return false;
  }
  return false;
}

node * minValueNode(node * root) {
  node * cur = root;
  while(cur->left) {
    cur = cur->left;
  }
  return cur;
}

node * deleteNode(node * root, int n) {
  if (root == NULL) {
    return root;
  }
  if (root->value > n) {
    root->left = deleteNode(root->left, n);
  }
  else if(root->value < n) {
    root->right = deleteNode(root->right, n);
  }
  else {
    if (root->left == NULL) {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      node *temp = root->left;
      free(root);
      return temp;
    }
    node * temp = minValueNode(root->right);
    root->value = temp->value;
    root->right = deleteNode(root->right, temp->value);
  }
  return root;
}

void printPreorder(node * root) {
  if(root){
    cout << root->value << " ";
    printPreorder(root->left);
    printPreorder(root->right);
  }
}

int sumR(node * root) {
  if (root != NULL) {
    return sumR(root->left) +
    root->value + sumR(root->right);
  }
  else {
    return 0;
  }
}

int sumIinorder(node * root) {
   stack<node*> s;
   int result = 0;
   node* cur = root;
   while(cur != NULL) {
     s.push(cur);
     cur = cur->left;
   }
   while(!s.empty()){
     cur = s.top();
     s.pop();
     result += cur->value;

     cur = cur->right;

     while(cur != NULL) {
       s.push(cur);
       cur = cur->left;
     }
   }
   return result;
}

int sumIpreorder(node * root) {
  stack<node*> s;
  int result = 0;
  if (root != NULL){
    s.push(root);
  }

  while(!s.empty()){
    node* cur = s.top();
    s.pop();
    result += cur->value;
    if (cur->right != NULL) {
      s.push(cur->right);
    }
    if (cur->left != NULL) {
      s.push(cur->left);
    }
  }
  return result;
}


int main() {
  node * root = new node;
  root->value = 10;
  root->left = NULL;
  root->right = NULL;
  addNode(root, 9);
  addNode(root, 11);
  int total = sumR(root);
  cout << "Recursive Sum is " << total << endl;
  total = sumIinorder(root);
  cout << "Iterative inorder Sum is " << total << endl;
  total = sumIpreorder(root);
  cout << "Iterative preorder Sum is " << total << endl;
  printPreorder(root);
  cout << endl;
  cout << searchNode(root, 9) << endl;
  cout << searchNode(root, 11) << endl;
  cout << searchNode(root, 8) << endl;
  root = deleteNode(root, 9);
  printPreorder(root);
  cout << endl;
}

#include <iostream>
using namespace std;

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data) {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

TreeNode *createNode() {
  int data;
  cout << "enter value: ";
  cin >> data;
  if (data == -1) {
    return NULL;
  }
  TreeNode *root = new TreeNode(data);
  root->left = createNode();
  root->right = createNode();
  return root;
}

int main() {
  TreeNode* root = createNode();
  cout << root -> data << endl;
  return 0;
}
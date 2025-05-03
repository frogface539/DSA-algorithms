#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    this->data = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node* createNode() {
  int data;
  cout<<"enter data: ";
  cin >> data;
  Node *root = new Node(data);
  if (data == -1) {
    return NULL;
  }
  root->left = createNode();
  root->right = createNode();
  return root;
}

// Root Left Right
void PreOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  
  cout << root->data << " ";
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}

// Left Root Right
void InOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  
  InOrderTraversal(root->left);
  cout << root->data << " ";
  InOrderTraversal(root->right);
}

// Left Right Root
void PostOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }
  
  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);
  cout << root->data << " ";
}


//Traverse level wise

void levelOrderTraversal(Node* root) {
    if(root == NULL){
        return;
    }

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout << temp -> data << " ";
            if(temp -> left != NULL){
                q.push(temp -> left);
            }

            if(temp -> right != NULL){
                q.push(temp -> right);
            }
        }
    }
}

int main() {
  Node* root = createNode();
  cout << endl;
  PreOrderTraversal(root);
  cout << endl;
  InOrderTraversal(root);
  cout << endl;
  PostOrderTraversal(root);
  cout << endl;
  levelOrderTraversal(root);
  return 0;
}



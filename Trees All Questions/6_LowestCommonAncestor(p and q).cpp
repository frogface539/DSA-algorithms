#include<iostream>
#include <queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* createTree(){
    int data;
    cout << "enter data: ";
    cin >> data;
    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    root -> left = createTree();
    root ->right = createTree();
    return root;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root == NULL){
        return NULL;
    }

    if(root == p){
        return p;
    }

    if(root == q){
        return q;
    }

    Node* leftAns = lowestCommonAncestor(root -> left , p , q);
    Node* rightAns = lowestCommonAncestor(root ->right , p , q);

    if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }

    if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }

    if(leftAns == NULL && rightAns == NULL){
        return NULL;
    }
    return root;
}


void levelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
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
  Node* root = createTree();
  cout << endl;
  levelOrder(root);
  cout << endl;
  lowestCommonAncestor(root, root->left, root->right);
  return 0;
}
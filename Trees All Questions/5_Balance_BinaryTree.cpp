#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
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
    root -> right = createTree();
    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    return max(height(root -> left) , height(root -> right)) + 1;
}

bool checkBalance(Node* root){

    if(root == NULL){
        return true;
    }

    int rightHeight = height(root -> right);
    int leftHeight = height(root -> left);
    bool diff = (abs(rightHeight - leftHeight)) <= 1;

    bool rightAns = checkBalance(root -> right);
    bool leftAns = checkBalance(root -> left);

    if(rightAns && leftAns && diff){
        return true;
    }
    return false;
}
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

int diameterofTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int option1 = diameterofTree(root -> left);
    int option2 = diameterofTree(root -> right);
    int option3 = height(root -> left) + height(root -> right);

    return max(option1 , max(option2 , option3));
}
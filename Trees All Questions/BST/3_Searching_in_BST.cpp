#include <iostream>
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

Node* insertIntoBST(Node* root , int data){
    if(root == NULL){
        return;
    }

    if(root -> data > data){
        root -> left = insertIntoBST(root -> left , data);
    }

    if(root -> data < data){
        root -> right = insertIntoBST(root -> right , data);
    }
    return root;
}

void createBST(Node* root){
    int data;
    cout << "enter data: ";
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root , data);
        cout << "enter data: ";
        cin >> data;
    }
}

bool searchInBST(Node* root , int target){
    if(root == NULL){
        return false;
    }

    if(root -> data == target){
        return true;
    }

    if(target > root -> data){
        return searchInBST(root -> right , target);
    }

    if(target < root -> data){
        return searchInBST(root -> left , target);
    }
    return false;
}
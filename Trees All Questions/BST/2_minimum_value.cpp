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

int minVal(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;
    while( !temp-> left){
        temp = temp -> left;
    }
    return temp -> data;
}

int maxVal(Node* root){
    if(root == NULL){
        return NULL;
    }
    
    Node* temp = root;
    while( !temp-> right){
        temp = temp -> right;
    }
    return temp -> data;
}

int main(){
    Node* root = NULL;
    createBST(root);
    cout << "Maximum Value of BST: " << endl;
    maxVal(root);
    cout << "Minimum Value of BST: " << endl;
    minVal(root);
    return 0;
}
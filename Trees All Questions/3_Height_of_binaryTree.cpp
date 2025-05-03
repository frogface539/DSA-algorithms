#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    
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
    root -> right = createTree();
    return root;

}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftAns = height(root -> left);
    int rightAns = height(root -> right);
    return max(leftAns , rightAns) + 1;
}

int main(){
    Node* root = createTree();
    cout << "Height of Tree is: " << height(root);
    return 0;
}
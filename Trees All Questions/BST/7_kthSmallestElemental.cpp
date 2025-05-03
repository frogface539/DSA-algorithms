#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }

    if (root->data < data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void createBST(Node *root)
{
    int data;
    cout << "enter data: ";
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "enter data: ";
        cin >> data;
    }
}

int kthSmallestElement(Node* root , int& k){
    if(root == NULL){
        return -1;
    }
    int leftAns = kthSmallestElement(root -> left , k);
    if(leftAns != -1){
        return leftAns;
    }
    k--;
    
    int rightAns = kthSmallestElement(root -> right , k);
    return rightAns;
}
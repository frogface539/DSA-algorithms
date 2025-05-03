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

Node* lowestCommonAncestor(Node* root , Node* p , Node* q){
    if(root == NULL){
        return NULL;
    }

    Node* rightAns = lowestCommonAncestor(root -> right , p , q);
    if(p -> data > root -> data && q -> data > root -> data){
        return rightAns;
    }

    Node* leftAns = lowestCommonAncestor(root -> left , p , q);
    if(p -> data < root -> data && q -> data < root -> data){
        return leftAns;
    }

    if(p -> data < root -> data && q -> data > root -> data){
        return root;
    }

    if(p -> data > root -> data && q -> data < root -> data){
        return root;
    }
}


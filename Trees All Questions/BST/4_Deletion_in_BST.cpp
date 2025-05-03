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
        return;
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

Node* maxVal(Node* root){
    if(root == NULL){
        return NULL;
    }
    
    Node* temp = root;
    while( !temp-> right){
        temp = temp -> right;
    }
    return temp;
}

Node *deleteNode(Node *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {

        // case 1 (leaf node)
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return root;
        }

        // case 2 (1 child = left)
        if (root->left != NULL && root->right == NULL)
        {
            Node *childSubTree = root->left;
            delete root;
            return root;
        }

        if(root->left == NULL && root->right != NULL){
            Node* childSubTree = root -> right;
            delete root;
            return root;
        }

        //*******************
        //case 3 (2 child)
        //Minimum value from RSB
        //Maximum value form LSB

        if(root->left == NULL && root->right == NULL){
            Node* maximum = maxVal(root -> left);
            root -> data = maximum -> data;
            root -> left = deleteNode(root -> left , maximum -> data);
            delete root;
            return root;
        }
    }
}
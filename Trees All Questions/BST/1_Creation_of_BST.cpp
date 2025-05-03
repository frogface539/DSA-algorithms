#include <iostream>
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

Node* insertIntoBST(Node* root , int data){
    if(root == NULL){
        return NULL;
    }

    if(root -> data > data){
        root -> left = insertIntoBST(root -> left , data);
    }

    else if(root -> data < data){
        root -> right = insertIntoBST(root -> right , data);
    }
    return root;
}

void createBST(Node* root){
    int data;
    cout << "enter data: ";
    cin >> data;

    if(data != -1){
        root = insertIntoBST(root , data);
        cout << "enter data: ";
        cin >> data;
    }
}

void levelOrderTraversal(Node* root){
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

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    return 0;
}
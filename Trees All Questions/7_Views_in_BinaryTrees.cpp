#include<iostream>
#include<vector>
#include<queue>
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

void LevelOrderTraversal(Node* root){
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
void solveRightView(Node* root , vector<int>ans , int level){
    if(root == NULL){
        return;
    }

    if(level == ans.size()){
        ans.push_back(root -> data);
    }

    solveRightView(root -> right , ans , level + 1);
    solveRightView(root  -> left, ans , level + 1);

}

vector<int> rightView(Node* root){
    vector<int>ans;
    int level = 0;
    solveRightView(root , ans , level);
    return ans;
}

int main() {
  Node* root = createTree();
  cout << endl;
  LevelOrderTraversal(root);
  cout << endl;
  cout << endl;
  cout << endl;
  rightView(root);
  cout<<endl;
  return 0;
}
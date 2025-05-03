#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void levelOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(nullptr); // Sentinel to mark the end of a level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl; // Print a newline to separate levels
            if (!q.empty()) {
                q.push(nullptr); // Add another sentinel for the next level
            }
        } else {
            cout << " " <<  temp->data << " ";
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
}

Node* createBST(vector<int>& inorder, int start, int end) {
    if (start > end) {
        return nullptr; // Base case: empty subtree
    }

    int mid = (start + end) / 2;
    Node* root = new Node(inorder[mid]);
    root->left = createBST(inorder, start, mid - 1);
    root->right = createBST(inorder, mid + 1, end);
    return root;
}

int main() {
    vector<int> inorder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node* root = createBST(inorder, 0, inorder.size() - 1);
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}
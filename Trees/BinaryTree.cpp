#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder); // LEFT
    root->right = buildTree(preorder); // RIGHT

    return root;
}

// pre order
void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left); // LEFT
    preorderTraversal(root->right); // RIGHT
}

// In order
void inorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);

}

// Post order
void postorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Level order
void levelOrder(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0) {
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            if(!q.empty()) {
                cout << endl;
                q.push(NULL);
                continue;
            } else {
                break;
            }
        }

        cout << curr->data << " ";

        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    // cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    cout << "Preorder = "; // root left right
    preorderTraversal(root);
    cout << endl;

    cout << "inorder = "; // left root right
    inorderTraversal(root);
    cout << endl;

    cout << "postorder = "; // left right root
    postorderTraversal(root);
    cout << endl;

    cout << "Level order = "; // every level
    levelOrder(root);
    cout << endl;

    return 0;
}
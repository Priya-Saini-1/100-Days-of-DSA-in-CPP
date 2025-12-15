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


// Kth level of a binary tree
void KLevel(Node* root, int k) {
    if(root == NULL) {
        return;
    }

    if(k == 1) {
        cout << root->data << " ";
        return;
    }

    KLevel(root->left, k-1);
    KLevel(root->right, k-1);
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int k = 3;
    Node* root = buildTree(preOrder);
    
    cout << "Kth elements are = ";
    KLevel(root, k);

    return 0;
}
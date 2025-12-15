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

//Height of a Tree
int height(Node* root) {
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt, rightHt) + 1;
}

//count of Nodes
int CountOfNodes(Node* root) {
    if(root == NULL){
        return 0;
    }

    int leftCnt = CountOfNodes(root->left);
    int rightCnt = CountOfNodes(root->right);
    return leftCnt + rightCnt + 1;
}

//Sum of Nodes
int Sum(Node* root) {
    if(root == NULL){
        return 0;
    }

    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);
    return leftSum + rightSum + root->data;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);

    cout <<"Height: " << height(root) << endl;
    cout <<"No. of Nodes: " << CountOfNodes(root) << endl;
    cout <<"Sum of Nodes: " << Sum(root) << endl;
    return 0;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }

        if(root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* leftCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightCA = lowestCommonAncestor(root->right, p, q);

        if(leftCA && rightCA) {
            return root;
        } else if(leftCA != NULL) {
            return leftCA;
        } else {
            return rightCA;
        }
    }
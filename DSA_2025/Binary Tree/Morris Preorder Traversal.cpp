



void morrisPreorder(TreeNode* root) {
    TreeNode* curr = root;
    while (curr) {
        if (!curr->left) {
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            TreeNode* pre = curr->left;
            while (pre->right && pre->right != curr)
                pre = pre->right;

            if (!pre->right) {
                cout << curr->val << " ";  // visit before left
                pre->right = curr;
                curr = curr->left;
            } else {
                pre->right = NULL;
                curr = curr->right;
            }
        }
    }
}

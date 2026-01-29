
void dfs(Node* root) {
    if (root == NULL) return;
    dfs(root->left);
    dfs(root->right);
    
    // Swap left and right children
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Function to convert a binary tree into its mirror
void mirror(Node* node) {
    if (node == NULL) return;
    dfs(node);
}

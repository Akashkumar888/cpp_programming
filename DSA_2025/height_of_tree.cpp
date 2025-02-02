
int level(Node* root) {
    if (root == NULL) return 0;
    return 1 + max(level(root->left), level(root->right));
}

int height(Node* node) {
    return level(node) - 1;  // Adjusting to count edges instead of nodes
}

class Solution {
public:
    int level(Node* root, int &maxdia) {
        if (root == NULL) return 0;
        int l = level(root->left, maxdia);
        int r = level(root->right, maxdia);
        maxdia = max(maxdia, l + r); // Update max diameter
        return 1 + max(l, r);
    }

    int diameter(Node* root) {
        if (root == NULL) return 0;
        int maxdia = 0;
        level(root, maxdia);
        return maxdia;
    }
};

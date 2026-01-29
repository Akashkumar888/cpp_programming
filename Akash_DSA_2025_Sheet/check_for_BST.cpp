#include <climits>

class Solution {
public:
    void inorder(Node* root, bool &flag, long long &prev) {
        if (root == NULL) return;
        
        inorder(root->left, flag, prev);
        
        if (root->data <= prev) {  // BST property violated
            flag = false;
            return;
        }
        
        prev = root->data; // Update previous value
        
        inorder(root->right, flag, prev);
    }

    bool isBST(Node* root) {
        bool flag = true;
        long long prev = LLONG_MIN; // Handle INT_MIN case
        inorder(root, flag, prev);
        return flag;
    }
};

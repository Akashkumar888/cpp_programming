
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        
        // Process the current node
        cout << node->val << " ";

        // Push the right child first so that the left child is processed first
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Preorder Traversal: ";
    preorder(root);

    return 0;
}

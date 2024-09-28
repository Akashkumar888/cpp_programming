
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top();
        s1.pop();
        s2.push(node);

        // Push left and right children to s1
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    // Print all elements in s2
    while (!s2.empty()) {
        TreeNode* node = s2.top();
        s2.pop();
        cout << node->val << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Postorder Traversal: ";
    postorder(root);

    return 0;
}

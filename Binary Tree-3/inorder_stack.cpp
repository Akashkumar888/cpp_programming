
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* curr = root;

    while (curr != NULL || !s.empty()) {
        // Reach the leftmost node of the current node
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        // Process the current node
        cout << curr->val << " ";

        // Visit the right subtree
        curr = curr->right;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}

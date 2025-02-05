
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node* solve(int &pre_idx, int st, int ed, vector<int>& preorder, unordered_map<int, int>& mp) {
    if (st > ed) return NULL;
    
    int val = preorder[pre_idx];
    pre_idx++;
    Node* root = new Node(val);
    
    int idx = mp[val];
    
    root->left = solve(pre_idx, st, idx - 1, preorder, mp);
    root->right = solve(pre_idx, idx + 1, ed, preorder, mp);
    
    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
    int n = inorder.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) 
        mp[inorder[i]] = i;

    int pre_idx = 0;
    return solve(pre_idx, 0, n - 1, preorder, mp);
}

// Utility function for inorder traversal (for testing)
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Node* root = buildTree(inorder, preorder);

    cout << "Inorder Traversal of Constructed Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

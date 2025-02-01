
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// BFS function to perform level order traversal
void bfs(Node* root, vector<vector<int>>& ans) {
    if (!root) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        vector<int> temp;
        
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            temp.push_back(node->data);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(temp);
    }
}

// Wrapper function
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    bfs(root, ans);
    return ans;
}

// Driver code
int main() {
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = levelOrder(root);

    // Printing the result
    cout << "Level Order Traversal: " << endl;
    for (auto level : result) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

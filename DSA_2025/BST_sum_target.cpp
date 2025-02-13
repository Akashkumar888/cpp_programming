
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

bool bfs(Node* root, unordered_set<int>& st, int& k) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            if (st.find(k - node->data) != st.end()) return true;
            st.insert(node->data);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return false;
}

bool findTarget(Node* root, int target) {
    if (root == NULL) return false;
    unordered_set<int> st;
    return bfs(root, st, target);
}

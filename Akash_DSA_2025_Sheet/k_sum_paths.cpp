
#include <bits/stdc++.h>
using namespace std;

// Tree Node Definition
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// DFS Function
int dfs(Node* root, int sum, int &cnt, int k, unordered_map<long long, long long> &mp) {
    if (root == NULL) return 0;

    // Update running sum
    sum += root->data;

    // Check if sum - k exists in map (valid subpaths)
    if (mp.find(sum - k) != mp.end()) 
        cnt += mp[sum - k];

    // Store current prefix sum
    mp[sum]++;

    // Recur for left and right subtrees
    dfs(root->left, sum, cnt, k, mp);
    dfs(root->right, sum, cnt, k, mp);

    // Backtrack - remove the current sum entry
    mp[sum]--;

    return cnt;
}

// Function to find paths with sum K
int sumK(Node *root, int k) {
    unordered_map<long long, long long> mp;
    int cnt = 0;
    
    // Base case: There is one way to get sum = k when the sum itself is k
    mp[0] = 1;
    
    dfs(root, 0, cnt, k, mp);
    return cnt;
}

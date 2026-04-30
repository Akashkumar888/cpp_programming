
class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        // code here
        // left 2*i+1
        // right 2*i+2
        //The given array represents the following tree. Each parent node is greater than or equal to its children, so the max-heap property holds.
        int n = arr.size();

        for(int i = 0; i < n; i++) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n && arr[left] > arr[i]) return false;
            if(right < n && arr[right] > arr[i]) return false;
        }
        return true;
    }
};



#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

TreeNode* buildTree(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return NULL;

    vector<TreeNode*> nodes;

    // create nodes
    for (int i = 0; i < n; i++) {
        nodes.push_back(new TreeNode(arr[i]));
    }

    // connect children
    for (int i = 0; i < n; i++) {
        if (2*i + 1 < n)
            nodes[i]->left = nodes[2*i + 1];
        if (2*i + 2 < n)
            nodes[i]->right = nodes[2*i + 2];
    }

    return nodes[0];
}
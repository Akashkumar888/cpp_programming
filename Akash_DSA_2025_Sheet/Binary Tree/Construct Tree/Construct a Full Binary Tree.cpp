
/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    Node* solve(int &preIdx, int left, int right,vector<int> &pre, vector<int> &preMirror,unordered_map<int,int> &mp) {
        if(preIdx >= pre.size() || left > right)return NULL;
        Node *root = new Node(pre[preIdx]);
        preIdx++;
        if(left == right || preIdx >= pre.size())return root;
        int idx = mp[pre[preIdx]];
        root->left = solve(preIdx, idx, right, pre, preMirror, mp);
        root->right = solve(preIdx, left + 1, idx - 1, pre, preMirror, mp);
        return root;
    }
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = pre.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++)mp[preMirror[i]] = i;
        int preIdx = 0;
        return solve(preIdx, 0, n - 1, pre, preMirror, mp);
    }
};
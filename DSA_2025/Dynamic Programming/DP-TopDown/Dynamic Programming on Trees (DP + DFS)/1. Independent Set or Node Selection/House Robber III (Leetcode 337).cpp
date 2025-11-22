

// In Tree DP problems, we almost always use DFS (Depth-First Search) — not BFS.
// 🧠 Why DFS is used for Tree DP
// Postorder traversal is natural for DP
// In Tree DP, a node’s value usually depends on its children’s results.
// DFS allows you to go down to children first, compute their DP values, then combine them upward.
// This fits perfectly with “bottom-up” dynamic programming.
// ✅ Example:
// int dfs(Node* root) {
//     if (!root) return 0;
//     int left = dfs(root->left);
//     int right = dfs(root->right);
//     return root->data + max(left, right);
// }
// This works because you get children’s results before using them.

// BFS (Level Order) goes top-down
// BFS traverses nodes level by level — it’s not suitable when you need children’s results first.
// It’s only used in some top-down DP problems, where parent → child transitions are defined (rare in trees).
// ⚙️ When BFS can be used (special cases)
// If the DP or computation depends on distance from root, shortest path, or levels, then BFS can be used.
// Example: finding minimum distance to a leaf, or sum at each level.
// queue<pair<Node*, int>> q;
// q.push({root, 0});

class Solution {
public:
int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
    if(root==NULL)return 0;
    int pick=root->val;
    int notpick=0;
    if(mp.find(root)!=mp.end())return mp[root];// if already it is solved // If already calculated, return stored value
    if(root->left && root->left->left)pick+=solve(root->left->left,mp);
    if(root->left && root->left->right)pick+=solve(root->left->right,mp);
    if(root->right && root->right->left)pick+=solve(root->right->left,mp);
    if(root->right && root->right->right)pick+=solve(root->right->right,mp);
    notpick+=solve(root->left,mp);
    notpick+=solve(root->right,mp);
    return mp[root]=max(pick,notpick); // Store best result for this node and return
}
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>mp;//it is use for memoizations in tree problem
        return solve(root,mp);
    }
};
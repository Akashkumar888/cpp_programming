
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


// You decide something (take / not take, cut / not cut, color / not color)
// Based on children’s results
// Combine children’s DP results to build the current node’s DP
// 🧠 Core Idea — Dynamic Programming on Trees (DP + DFS)
// We’ll use post-order traversal (DFS) and for each node, we calculate two values:
// For each node:
// Include (Take) this node → we cannot take its children.
// Exclude (Skip) this node → we can take or skip its children (whichever gives max sum).
// Let’s define:
// For a node root:
// include = root->data + sum of (exclude of left + exclude of right)
// exclude = max(include or exclude of left) + max(include or exclude of right)

// top down approach 
class Solution {
public:
int dfs(Node* root,unordered_map<Node*,int>&dp){
    if (root == NULL) return 0;
    if (dp.count(root)) return dp[root]; // ✅ check memoized
    int pick = root->data;
    if (root->left)pick+=dfs(root->left->left,dp) + dfs(root->left->right,dp);
    if (root->right)pick+=dfs(root->right->left,dp) + dfs(root->right->right,dp);
    int notpick = dfs(root->left,dp) + dfs(root->right,dp);

    return dp[root] = max(pick, notpick); // ✅ store result
}
    int getMaxSum(Node *root) {
        // code here
        unordered_map<Node*,int>dp;
        return dfs(root,dp);
    }
};
//Complexity without memo = O(2ⁿ), after memoization = O(n) time and O(n) space ✅
// pick notpick o(2^n)
// after memoization it is o(n) time and o(n) space 
// That means for every node you have two possible states:
// Pick the node
// Don’t pick the node
// ✅ So there are 2 states per node.


// 1. Independent Set / Node Selection
// You cannot take adjacent nodes (parent-child constraint).
// ✅ Example Problems:
// Maximum Sum of Non-Adjacent Nodes (you just studied!)
// Maximum Weight Independent Set in a Tree
// House Robber III (Leetcode 337)
// Core idea:
// Each node → include and exclude states.
// 2. Path-based Problems
// DP stores best values in each subtree for path sums, diameters, etc.
// ✅ Examples:
// Maximum Path Sum in a Binary Tree
// Diameter of a Binary Tree
// Longest Path with Even Sum / Equal Nodes / Specific Condition
// Core idea:
// Each node returns max gain path to its parent; combine left+right for overall max.
// 3. Subtree-based DP
// Compute something for every subtree, e.g., size, sum, count.
// ✅ Examples:
// Sum of all nodes in each subtree
// Count of nodes satisfying a condition
// Maximum Product of Splitting Binary Tree
// Core idea:
// Return computed values (sum, size, etc.) to parent.
// 4. Parent-Child Dependency DP
// State depends on whether parent has a certain property.
// ✅ Examples:
// Vertex Cover Problem in a Tree (choose minimum vertices so every edge is covered)
// Binary Tree Coloring Problem (Leetcode 1145)
// Minimum Cameras to Monitor All Nodes (Leetcode 968)
// Core idea:
// Multiple states per node: e.g. hasCamera, covered, needsCamera.
// 5. Counting / Combinatorial Tree DP
// Count ways of doing something for the whole tree.
// ✅ Examples:
// Number of ways to color a tree with K colors
// Count of Independent Sets in a Tree
// Number of ways to choose nodes satisfying conditions
// Core idea:
// Multiply combinations from children (product rule).
// 6. Rerooting / All-Nodes DP
// Compute DP for every node as root (re-rooting technique).
// ✅ Examples:
// Sum of distances from each node to all others (Leetcode 834)
// Count of nodes in each subtree & outside it
// Core idea:
// Use two DFS passes:
// First DFS → subtree information.
// Second DFS → use parent’s DP to update children’s results.


// bottom up approach 
class Solution {
public:
    int getMaxSum(Node *root) {
        if (!root) return 0;

        unordered_map<Node*, int> dp;  // Memo table
        queue<Node*> q;

        // Post-order traversal using stack (simulate DFS bottom-up inside BFS loop)
        vector<Node*> postOrder; 
        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            postOrder.push_back(node);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        // Now process in reverse (bottom-up order)
        for (int i = postOrder.size() - 1; i >= 0; i--) {
            Node* node = postOrder[i];
            int pick = node->data;
            
            if (node->left) {
                pick += (node->left->left ? dp[node->left->left] : 0);
                pick += (node->left->right ? dp[node->left->right] : 0);
            }
            if (node->right) {
                pick += (node->right->left ? dp[node->right->left] : 0);
                pick += (node->right->right ? dp[node->right->right] : 0);
            }

            int notpick = 0;
            if (node->left) notpick += dp[node->left];
            if (node->right) notpick += dp[node->right];

            dp[node] = max(pick, notpick);
        }

        return dp[root];
    }
};

// 🧩 Bonus Tip
// If you ever face multiple states (like dp[node][0 or 1] for include/exclude), you can memoize like this:
// unordered_map<Node*, array<int,2>> dp;
// // dp[node][0] → exclude
// // dp[node][1] → include
// This makes your Tree DP even cleaner for “two-state” problems such as Vertex Cover or Binary Tree Coloring.


class Solution {
  public:
  int dfs(Node*root,int &moves){
      if(root==NULL)return 0;
      int l=dfs(root->left,moves);
      int r=dfs(root->right,moves);
      // total moves made between the node and its children.
      moves+=abs(l)+abs(r); // child to parent moves +ve ,parent to child moves -ve
      // Positive value → extra candies to give to parent.
      // Negative value → candies needed from parent.
      // that's why we use abs value 
      return (l+r+root->data)-1; // ek isne apne pass rakha 
      //return ka mtlb uper bhejna baki sb remaining uper(parent) ko bej diya recusrion rewind ke time 
  }
    int distCandy(Node* root) {
        // code here
        // minimum number of moves required to ensure that
        //every node in the tree has exactly one candy
        // Give extra candies to its parent (if it has more than 1),
        // or Take candies from its parent (if it has fewer than 1).
        int moves=0;
        dfs(root,moves);
        return moves;
    }
};

// 🧠 Time & Space Complexity
// Time: O(N) — each node visited once
// Space: O(H) — recursion stack (H = height of tree)


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int dfs(Node*root,int &moves){
      if(root==NULL)return 0;
      int leftChild=dfs(root->left,moves);
      int rightChild=dfs(root->right,moves);
      // total moves made between the node and its children.
      moves+=abs(leftChild)+abs(rightChild); // child to parent moves +ve ,parent to child moves -ve
      // Positive value → extra candies to give to parent.
      // Negative value → candies needed from parent.
      // that's why we use abs value 
      return (leftChild+rightChild+root->data)-1; // ek isne apne pass rakha 
      //return ka mtlb uper bhejna baki sb remaining uper(parent) ko bej diya recusrion rewind ke time 
  }
    int distCandy(Node* root) {
        // code here
        // minimum number of moves required to ensure that
        //every node in the tree has exactly one candy
        // Give extra candies to its parent (if it has more than 1),
        // or Take candies from its parent (if it has fewer than 1).
        int moves=0;
        dfs(root,moves);
        return moves;
    }
};

// 🧠 The ONLY Correct Way to Choose Traversal
// 🔑 Golden Rule:
// 👉 Traversal depends on DATA DEPENDENCY (who needs whose result first)

// 🔵 1. POSTORDER (Left → Right → Node)
// ✅ Use when:
// 👉 Current node depends on results from children
// ✔️ Meaning:
// First solve left subtree
// First solve right subtree
// THEN process current node
// 🔥 Use in problems like:
// Height of tree
// Diameter
// Balanced tree
// Distribute Candies (your problem)
// Sum of subtree
// Any bottom-up computation

// 💡 Why your problem is POSTORDER:
// int l = dfs(root->left, moves);
// int r = dfs(root->right, moves);

// 👉 You NEED l and r first
// 👉 Then compute current node
// ✔️ So it's POSTORDER
// 🧠 One-line memory:
// 👉 “If node needs children → POSTORDER”

// 🟢 2. PREORDER (Node → Left → Right)
// ✅ Use when:
// 👉 Children depend on the current node (you pass info downward)
// ✔️ Meaning:
// Process node first
// Then go to children with updated data
// 🔥 Use in problems like:
// Path sum
// Root-to-leaf paths
// Passing constraints (min/max)
// Tree construction
// Backtracking
// 💡 Example:
// void dfs(node, sum) {
//     if (!node) return;
//     sum += node->val;   // use parent info first
//     dfs(node->left, sum);
//     dfs(node->right, sum);
// }
// 👉 You DON’T need children first
// 👉 You PASS info to them
// ✔️ So it's PREORDER
// 🧠 One-line memory:
// 👉 “If children need parent → PREORDER”

// 🟡 3. INORDER (Left → Node → Right)
// ✅ Use when:
// 👉 You need nodes in a specific order
// 🔥 Mainly used for:
// ✔️ Binary Search Trees (BST)
// Gives sorted order
// 💡 Use cases:
// Kth smallest element
// Validate BST
// Inorder traversal output
// Convert tree to sorted list
// 💡 Example:
// void inorder(node) {
//     if (!node) return;
//     inorder(node->left);
//     cout << node->val;   // processed in sorted order (BST)
//     inorder(node->right);
// }
// 🧠 One-line memory:
// 👉 “If order matters (especially BST) → INORDER”
// 🚫 Fix Your Incorrect Understanding
// You said:
// ❌ parent → child = post
// ❌ child → parent = pre
// This is wrong.
// ✅ Correct Mapping
// Situation	Correct Traversal
// Need children result first	POSTORDER
// Pass data from parent to child	PREORDER
// Need sorted/order traversal (BST)	INORDER
// 🔥 Final Intuition (VERY IMPORTANT)
// 🧱 POSTORDER
// 👉 Bottom-up
// 👉 “Solve children → then node”
// 🌊 PREORDER
// 👉 Top-down
// 👉 “Process node → go to children”
// 📊 INORDER
// 👉 “Left → Node → Right (ordering)”

// 🎯 Apply to Your Candy Problem
// int l = dfs(root->left, moves);
// int r = dfs(root->right, moves);
// moves += abs(l) + abs(r);
// return (l + r + root->data) - 1;
// ✔️ You need l and r
// ✔️ Then compute
// 👉 100% POSTORDER
// ⚡ Final Cheat Sheet
// 👉 POSTORDER = bottom-up (most important for trees)
// 👉 PREORDER = top-down (passing info)
// 👉 INORDER = ordering (BST)

// ✔️ POSTORDER
// ✔️ Combine left + right
// ✔️ Return info upward
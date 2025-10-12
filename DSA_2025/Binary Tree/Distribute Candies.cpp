
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
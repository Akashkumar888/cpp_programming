
class Solution {
  public:
  Node* dfs(Node*root,int l,int r){
      if(root==NULL)return NULL;
      // Include node if within range
      
      // Recursively fix left and right subtrees
      root->left = dfs(root->left, l, r);
      root->right = dfs(root->right, l, r);

      // Now handle the current node
      if (root->data < l)
          return root->right;  // discard current and left subtree
      if (root->data > r)
          return root->left;   // discard current and right subtree

      return root;  // keep node
  }
    Node* removekeys(Node* root, int l, int r) {
        // code here
        return dfs(root,l,r);
    }
};


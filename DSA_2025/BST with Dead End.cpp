

class Solution {
  public:
    bool dfs(Node* root,int low,int high) {
        if (root==NULL)return false;

        // Dead end condition
        if (low==high)return true;

        // Recurse for left and right subtree
        return dfs(root->left,low,root->data-1) || 
               dfs(root->right,root->data+1,high);
    }

    bool isDeadEnd(Node* root) {
        return dfs(root,1,INT_MAX);  // BST values ≥ 1
    }
};


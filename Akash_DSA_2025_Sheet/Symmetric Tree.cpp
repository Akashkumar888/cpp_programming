
// symmetric tree in cpp
class Solution {
  public:
  bool dfs(Node*root1,Node*root2){
      if(root1==NULL && root2==NULL)return true;
      if (root1 == NULL || root2 == NULL) return false;
      if(root1->data!=root2->data)return false;
      return dfs(root1->left,root2->right) && dfs(root1->right,root2->left);
  }
    bool isSymmetric(Node* root) {
        // Code here
        return dfs(root->left,root->right);
    }
};

// invert tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return NULL;
        // Swap left and right children
        swap(root->left, root->right);
        
        // Recurse on children
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

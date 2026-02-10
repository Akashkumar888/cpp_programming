
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  // inorder traversal for sorted
  void inorder(TreeNode*root,vector<int>&ans){
    if(root==NULL)return ;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
  }
  TreeNode* buildTree(int l,int r,vector<int>&ans){
    if(l>r)return NULL;
    int mid=l+(r-l)/2;
    TreeNode*root=new TreeNode(ans[mid]);
    root->left=buildTree(l,mid-1,ans);
    root->right=buildTree(mid+1,r,ans);
    return root;
  }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        return buildTree(0,n-1,ans);
    }
};

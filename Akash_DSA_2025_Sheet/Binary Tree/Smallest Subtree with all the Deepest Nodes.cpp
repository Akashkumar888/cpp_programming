
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
//Deepest Leaves ko store krne ke liye map use 
void dfs(TreeNode*root,unordered_map<int,vector<TreeNode*>>&mp,int level,int &maxlevel){
    if(root==NULL)return ;
    maxlevel=max(maxlevel,level);
    mp[level].push_back(root);
    dfs(root->left,mp,level+1,maxlevel);
    dfs(root->right,mp,level+1,maxlevel);
}

TreeNode* solve(TreeNode*root,TreeNode* p,TreeNode* q){
if(root==NULL)return NULL;
if(root==p ||root==q)return root;
TreeNode*leftSub=solve(root->left,p,q);
TreeNode*rightSub=solve(root->right,p,q);
if(leftSub!=NULL && rightSub!=NULL)return root;
if(leftSub!=NULL && rightSub==NULL)return leftSub;
// if(leftSub==NULL && rightSub!=NULL)return rightSub;
return rightSub;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<int,vector<TreeNode*>>mp;
        int maxlevel=0;
        dfs(root,mp,0,maxlevel);
        TreeNode*p=mp[maxlevel].front();
        TreeNode*q=mp[maxlevel].back();
    return solve(root,p,q);
    }
};

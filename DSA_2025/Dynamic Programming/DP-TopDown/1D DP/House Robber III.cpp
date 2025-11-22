
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

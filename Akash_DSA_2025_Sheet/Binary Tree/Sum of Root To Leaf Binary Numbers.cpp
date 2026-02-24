

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
void dfs(TreeNode*root,int currsum,int &binarySum){
    if(root==NULL)return;
    currsum = (currsum<<1) | root->val;
    if(root->left==NULL && root->right==NULL){
        binarySum+=currsum;
        return;
    }
    dfs(root->left,currsum,binarySum);
    dfs(root->right,currsum,binarySum);
}
    int sumRootToLeaf(TreeNode* root) {
     int binarySum=0;
     dfs(root,0,binarySum);
     return binarySum;   
    }
}; 



class Solution {
public:
int dfs(TreeNode*root,int currSum){
    if(root==NULL)return 0;
    currSum = (currSum<<1) + root->val;
    if(root->left==NULL && root->right==NULL){
        return currSum;
    }
    return dfs(root->left,currSum) + dfs(root->right,currSum);
    // left sum
    // right sum
    // whole sum
}
    int sumRootToLeaf(TreeNode* root) {
     return dfs(root,0); 
    }
}; 
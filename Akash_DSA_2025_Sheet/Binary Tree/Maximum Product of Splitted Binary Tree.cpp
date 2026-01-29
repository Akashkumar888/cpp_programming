
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
int MOD=1e9+7;
int solve(TreeNode* root){
    if(root==NULL)return 0;
    int leftSubTreeSum=solve(root->left);
    int rightSubTreeSum=solve(root->right);
    int sum=root->val + leftSubTreeSum + rightSubTreeSum;
    return sum;
}
int find(TreeNode* root,int &totalSum,long long &maxProd){
    if(root==NULL)return 0;
    int leftSubTreeSum=find(root->left,totalSum,maxProd);
    int rightSubTreeSum=find(root->right,totalSum,maxProd);
    int sum=root->val + leftSubTreeSum + rightSubTreeSum;
    int remaingSum=totalSum - sum;
    maxProd=max(maxProd,1LL * sum * remaingSum);
    return sum;  // ✅ return subtree sum
}
    int maxProduct(TreeNode* root) {
        int totalSum=solve(root);
        long long maxProd=LLONG_MIN;
        find(root,totalSum,maxProd);
        return maxProd % MOD;
    }
};


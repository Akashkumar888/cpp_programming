

class Solution {
public:
// ✅ Correct:
// middleIdx = l + (e - l) / 2 binary search vala 
// or simply:
// int mid = (l + e) / 2;
TreeNode*solve(int l,int e,vector<int>&nums){
    if(l>e)return NULL;
    int middleIdx=(l + e)/2;
    TreeNode*root=new TreeNode(nums[middleIdx]);
    root->left=solve(l,middleIdx-1,nums);
    root->right=solve(middleIdx+1,e,nums);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(0,n-1,nums);
    }
};

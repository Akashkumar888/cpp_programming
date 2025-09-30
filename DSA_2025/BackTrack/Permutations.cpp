
class Solution {
public:
void f(int idx,int n,vector<int>&nums,vector<vector<int>>&ans){
if(idx>=n){
    ans.push_back(nums);
    return ;
}
for(int j=idx;j<n;j++){
    swap(nums[idx],nums[j]);
    f(idx+1,n,nums,ans);
    swap(nums[idx],nums[j]);
}
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        f(0,n,nums,ans);
        return ans;
    }
};


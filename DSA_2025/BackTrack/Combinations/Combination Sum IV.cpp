
class Solution {
public:
    int solve(vector<int>&nums,int tr,vector<int>&dp){
    if(tr==0)return 1;
    if(tr<0 )return 0;
    if(dp[tr]!=-1)return dp[tr];
    int count=0;
    // Note that different sequences are counted as different combinations.
    // then it start from j=0; 
    for(int j=0;j<nums.size();j++){
        count+=solve(nums,tr-nums[j],dp);
    }
    return dp[tr]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return solve(nums,target,dp);
    }
};
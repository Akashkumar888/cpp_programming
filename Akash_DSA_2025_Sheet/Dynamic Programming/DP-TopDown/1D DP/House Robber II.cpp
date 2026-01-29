
class Solution {
public:
int solve(int i,vector<int>&nums,vector<int>&dp){
    if(i==0)return nums[0];
    if(dp[i]!=-1)return dp[i];
    int pick=nums[i];
    if(i>1)pick+=solve(i-2,nums,dp);
    int notpick=0+solve(i-1,nums,dp);
    return dp[i]=max(pick,notpick);
} 
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>nums1,nums2;
        for(int i=0;i<nums.size();i++){
            if(i==0)nums1.push_back(nums[i]);
            else if(i==nums.size()-1)nums2.push_back(nums[i]);
            else{
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        int n=nums1.size();
        vector<int>dp1(n,-1),dp2(n,-1);
        return max(solve(n-1,nums1,dp1),solve(n-1,nums2,dp2));
    }
};


class Solution {
public:
int solve(vector<int>&nums){
        int n=nums.size();
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=dp[i-2];
            int notpick=0+dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
} 
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>nums1,nums2;
        for(int i=0;i<nums.size();i++){
            if(i==0)nums1.push_back(nums[i]);
            else if(i==nums.size()-1)nums2.push_back(nums[i]);
            else{
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        return max(solve(nums1),solve(nums2));
    }
};

class Solution {
public:
int solve(vector<int>&nums){
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)pick+=prev2;
            int notpick=0+prev1;
            int curr=max(pick,notpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
} 
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>nums1,nums2;
        for(int i=0;i<nums.size();i++){
            if(i==0)nums1.push_back(nums[i]);
            else if(i==nums.size()-1)nums2.push_back(nums[i]);
            else{
                nums1.push_back(nums[i]);
                nums2.push_back(nums[i]);
            }
        }
        return max(solve(nums1),solve(nums2));
    }
};
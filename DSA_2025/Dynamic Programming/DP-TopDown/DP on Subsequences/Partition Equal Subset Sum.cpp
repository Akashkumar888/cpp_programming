
class Solution {
public:
bool solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
      if(target==0)return true;
      if(i==0)return (nums[0]==target);
      if(dp[i][target]!=-1)return dp[i][target];
      bool notpick=solve(i-1,nums,target,dp);
      bool pick=false;
      if(nums[i]<=target)pick=solve(i-1,nums,target-nums[i],dp);
      return dp[i][target]=pick | notpick;
  }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;// if totalSum is odd 
        int sum=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,nums,sum,dp);
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;// if totalSum is odd 
        int sum=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        // base case 
        for(int i=0;i<n;i++)dp[i][0]=true;
        for(int target=1;target<=sum;target++){
            dp[0][target]=(nums[0]==target);
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)pick=dp[i-1][target-nums[i]];
                dp[i][target]=pick | notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;// if totalSum is odd 
        int sum=totalSum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        // base case 
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=sum)dp[0][nums[0]]=true;//if(i==0)return (nums[0]==target);
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)pick=dp[i-1][target-nums[i]];
                dp[i][target]=pick | notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum%2)return false;// if totalSum is odd 
        int sum=totalSum/2;
        vector<bool>prev(sum+1,0),temp(sum+1,0);
        // base case 
        prev[0]=true;
        temp[0]=true;
        
        if(nums[0]<=sum)prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=prev[target];
                bool pick=false;
                if(nums[i]<=target)pick=prev[target-nums[i]];
                temp[target]=pick | notpick;
            }
            prev=temp;
        }
        return prev[sum];
    }
};

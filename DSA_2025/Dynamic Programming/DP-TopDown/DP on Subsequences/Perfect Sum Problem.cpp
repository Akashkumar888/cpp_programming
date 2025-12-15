
class Solution {
  public:
  int solve(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
      // Correct base cases
        if(i == 0) { // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
            if(target == 0 && nums[0] == 0) return 2;  // {} and {0}
            if(target == 0) return 1;                 // empty subset
            if(nums[0] == target) return 1;           // single element subset
            return 0;
        }
      if(dp[i][target]!=-1)return dp[i][target];
      int notpick=solve(i-1,nums,target,dp);
      int pick=0;
      if(nums[i]<=target)pick=solve(i-1,nums,target-nums[i],dp);
      return dp[i][target]=pick + notpick;
  }
    int perfectSum(vector<int>& nums, int sum) {
        // code here
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,nums,sum,dp);
    }
};


class Solution {
  public:
    int perfectSum(vector<int>& nums, int sum) {
        // code here
        int n=nums.size();
        // dp[i][target] = number of ways to make target using first i elements
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && nums[0] == 0)dp[0][target] = 2;     // {} and {0}
            else if (target == 0)dp[0][target] = 1;     // empty subset {}
            else if (nums[0] == target)dp[0][target] = 1;     // single element subset
            else dp[0][target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
              // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
                int notpick=dp[i-1][target];
                int pick=0;
                if(nums[i]<=target)pick=dp[i-1][target-nums[i]];
                dp[i][target]=pick + notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    int perfectSum(vector<int>& nums, int sum) {
        // code here
        int n=nums.size();
        // dp[i][target] = number of ways to make target using first i elements
        vector<int>prev(sum + 1,0),temp(sum+1,0);
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && nums[0] == 0)prev[target] = 2;     // {} and {0}
            else if (target == 0)prev[target] = 1;     // empty subset {}
            else if (nums[0] == target)prev[target] = 1;     // single element subset
            else prev[target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
                int notpick=prev[target];
                int pick=0;
                if(nums[i]<=target)pick=prev[target-nums[i]];
                temp[target]=pick + notpick;
            }
            prev=temp;
        }
        return prev[sum];
    }
};
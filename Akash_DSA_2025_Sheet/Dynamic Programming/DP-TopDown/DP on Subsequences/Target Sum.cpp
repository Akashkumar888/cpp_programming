
class Solution {
public:
int solve(int i,vector<int>&arr,int tr,vector<vector<int>>&dp){
      // Correct base cases
      if(i == 0) { // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
            if(tr == 0 && arr[0] == 0) return 2;  // {} and {0}
            if(tr == 0) return 1;                 // empty subset
            if(arr[0] == tr) return 1;           // single element subset
            return 0;
      }
      if(dp[i][tr]!=-1)return dp[i][tr];
      int notpick=solve(i-1,arr,tr,dp);
      int pick=0;
      if(arr[i]<=tr)pick=solve(i-1,arr,tr-arr[i],dp);
      return dp[i][tr]=pick + notpick;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        // Code here
        // s1 assign->  +(s1)
        // s2 assign -> -(s2)
        // s1-s2=target
        // s1>=s2
        // s1-s2=target; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=target;
        // s2=(totalSum-target)/2;
        // it should be +ve and even also 
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if((totalSum-target)<0 || (totalSum-target)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,nums,sum,dp);
    }
};

//Back-end complete function Template for C++
class Solution {
  public:
    long long solve(int i,vector<int>&arr,int tr,vector<vector<long long>>&dp){
          // Correct base cases
          if(i == 0) { // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
                if(tr == 0 && arr[0] == 0) return 2;  // {} and {0}
                if(tr == 0) return 1;                 // empty subset
                if(arr[0] == tr) return 1;           // single element subset
                return 0;
          }
          if(dp[i][tr]!=-1)return dp[i][tr];
          int notpick=solve(i-1,arr,tr,dp);
          int pick=0;
          if(arr[i]<=tr)pick=solve(i-1,arr,tr-arr[i],dp);
          return dp[i][tr]=pick + notpick;
      }
    long long findTargetSumWays(int n, vector<int>& arr, int target) {
        // Your code here
        // Code here
        // s1 assign->  +(s1)
        // s2 assign -> -(s2)
        // s1-s2=target
        // s1>=s2
        // s1-s2=target; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=target;
        // s2=(totalSum-target)/2;
        // it should be +ve and even also 
        long long totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-target)<0 || (totalSum-target)%2)return 0;// if totalSum is odd 
        long long sum=(totalSum-target)/2;
        vector<vector<long long>>dp(n,vector<long long>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // Code here
        // s1 assign->  +(s1)
        // s2 assign -> -(s2)
        // s1-s2=target
        // s1>=s2
        // s1-s2=target; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=target;
        // s2=(totalSum-target)/2;
        // it should be +ve and even also 
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if((totalSum-target)<0 || (totalSum-target)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-target)/2;
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
    int findTargetSumWays(vector<int>& nums, int target) {
        // Code here
        // s1 assign->  +(s1)
        // s2 assign -> -(s2)
        // s1-s2=target
        // s1>=s2
        // s1-s2=target; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=target;
        // s2=(totalSum-target)/2;
        // it should be +ve and even also 
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if((totalSum-target)<0 || (totalSum-target)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-target)/2;
        vector<int>prev(sum+1,0),temp(sum+1,0);
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


class Solution {
  public:
  int solve(int i,vector<int>&arr,int target,vector<vector<int>>&dp){
      // Correct base cases
      if(i == 0) { // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
            if(target == 0 && arr[0] == 0) return 2;  // {} and {0}
            if(target == 0) return 1;                 // empty subset
            if(arr[0] == target) return 1;           // single element subset
            return 0;
      }
      if(dp[i][target]!=-1)return dp[i][target];
      int notpick=solve(i-1,arr,target,dp);
      int pick=0;
      if(arr[i]<=target)pick=solve(i-1,arr,target-arr[i],dp);
      return dp[i][target]=pick + notpick;
  }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        vector<vector<int>>dp(n,vector<int>(sum + 1, 0));
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && arr[0] == 0)dp[0][target] = 2;     // {} and {0}
            else if (target == 0)dp[0][target] = 1;     // empty subset {}
            else if (arr[0] == target)dp[0][target] = 1;     // single element subset
            else dp[0][target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
              // 1 ≤ arr.size() ≤ 10^3 , 0 ≤ arr[i] ≤ 10^3 , 0 ≤ target ≤ 10^3
                int notpick=dp[i-1][target];
                int pick=0;
                if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
                dp[i][target]=pick + notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        // s1-s2=diff
        // s1>=s2
        // s1-s2=diff; equations 1
        // s1=totalSum-s2; put this value in equations 1
        // totalSum-s2-s2=diff;
        // s2=(totalSum-diff)/2;
        // it should be +ve and even also 
        int n=arr.size();
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        if((totalSum-diff)<0 || (totalSum-diff)%2)return 0;// if totalSum is odd 
        int sum=(totalSum-diff)/2;
        // dp[i][target] = number of ways to make target using first i elements
        vector<int>prev(sum+1,0),temp(sum+1,0);
        // ---- Base Case for i = 0 (only nums[0] available) ----
        // because this array contains 0 elements also
        for (int target = 0; target <= sum; target++) {
            if (target == 0 && arr[0] == 0)prev[target] = 2;     // {} and {0}
            else if (target == 0)prev[target] = 1;     // empty subset {}
            else if (arr[0] == target)prev[target] = 1;     // single element subset
            else prev[target] = 0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=sum;target++){// because this array contains 0 elements also
                int notpick=prev[target];
                int pick=0;
                if(arr[i]<=target)pick=prev[target-arr[i]];
                temp[target]=pick + notpick;
            }
            prev=temp;
        }
        return prev[sum];
    }
};

class Solution {
  public:
  bool solve(int i,vector<int>&arr,int target,vector<vector<int>>&dp){
      if(target==0)return true;
      if(i==0)return (arr[0]==target);
      if(dp[i][target]!=-1)return dp[i][target];
      bool notpick=solve(i-1,arr,target,dp);
      bool pick=false;
      if(arr[i]<=target)pick=solve(i-1,arr,target-arr[i],dp);
      return dp[i][target]=pick | notpick;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,0));
        // base case 
        for(int i=0;i<n;i++)dp[i][0]=true;
        for(int target=1;target<=sum;target++){
            dp[0][target]=(arr[0]==target);
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
                dp[i][target]=pick | notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        // base case 
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=sum)dp[0][arr[0]]=true;//if(i==0)return (arr[0]==target);
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
                dp[i][target]=pick | notpick;
            }
        }
        return dp[n-1][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        vector<bool>prev(sum+1,0),temp(sum+1,0);
        // base case 
        prev[0]=true;
        temp[0]=true;
        
        if(arr[0]<=sum)prev[arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=prev[target];
                bool pick=false;
                if(arr[i]<=target)pick=prev[target-arr[i]];
                temp[target]=pick | notpick;
            }
            prev=temp;
        }
        return prev[sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // dp[i][target] = whether we can make 'target' using first i elements
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base case 1: target = 0 → always TRUE (take no elements)
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // Base case 2: for i = 0 (only first element)
        // We can form target = arr[0] ONLY if arr[0] == target
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        // Fill DP table
        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= sum; target++) {

                // OPTION 1 → Don't take arr[i]
                bool notpick = dp[i - 1][target];

                // OPTION 2 → Take arr[i] if possible
                bool pick = false;
                if (arr[i] <= target)
                    pick = dp[i - 1][target - arr[i]];

                // Result for dp[i][target]
                dp[i][target] = pick | notpick;
            }
        }

        // Final answer
        return dp[n - 1][sum];
    }
};

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();

        // prev[target]  = DP result for previous index (i-1)
        // temp[target]  = DP result for current index (i)
        vector<bool> prev(sum + 1, false), temp(sum + 1, false);

        // Base case: target = 0 → always true
        prev[0] = true;
        temp[0] = true;

        // Base case for first element
        if (arr[0] <= sum)
            prev[arr[0]] = true;

        // Build DP row by row
        for (int i = 1; i < n; i++) {

            for (int target = 1; target <= sum; target++) {

                // OPTION 1 → Not pick arr[i]
                bool notpick = prev[target];

                // OPTION 2 → Pick arr[i]
                bool pick = false;
                if (arr[i] <= target)
                    pick = prev[target - arr[i]];

                temp[target] = pick | notpick;
            }

            // Shift current row → previous row
            prev = temp;
        }

        return prev[sum];
    }
};

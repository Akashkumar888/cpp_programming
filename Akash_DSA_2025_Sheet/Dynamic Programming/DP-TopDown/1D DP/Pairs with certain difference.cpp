

// find maximum pair sum
// Pair difference should be less than k.
// Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
// Sum of p pairs means sum of 2p elements in the result.
// If no valid pairs can be formed, return 0.
class Solution {
  public:
    int solve(int i,vector<int>&arr,int k,vector<int>&dp){
        // no element left
        if(i<=0){
            return 0;
        }
        // memoization
        if(dp[i]!=-1){
            return dp[i];
        }
        // option 1 -> skip
        int notPick=solve(i-1,arr,k,dp);
        int pick=0;
        // valid pair
        if(arr[i]-arr[i-1] < k){
            pick=arr[i]+arr[i-1];
            // add previous non-overlapping pair answer
            pick+=solve(i-2,arr,k,dp);
        }
        return dp[i]=max(pick,notPick);
    }
    int sumDiffPairs(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,-1);
        return solve(n-1,arr,k,dp);
    }
};


class Solution {
  public:
    int sumDiffPairs(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            // option 1 -> skip
            int notPick=dp[i-1];
            int pick=0;
            // valid pair
            if(arr[i]-arr[i-1] < k){
                pick=arr[i]+arr[i-1];
                // add previous non-overlapping pair answer
                pick+=dp[i-2];
            }
            dp[i]=max(pick,notPick);
        }
        return dp[n-1];
    }
};

class Solution {
  public:
// find maximum pair sum
// Pair difference should be less than k.
// Pairs should be disjoint. For example if (x, y) is a result pair, then neither x nor y should appear in any other result pair.
// Sum of p pairs means sum of 2p elements in the result.
// If no valid pairs can be formed, return 0.
    int sumDiffPairs(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            // skip current pair
            dp[i]=dp[i-1];
            // valid pair
            if(arr[i]-arr[i-1] < k){
                int pairSum=arr[i]+arr[i-1];
                // include previous non-overlapping answer
                if(i>=2){
                    pairSum+=dp[i-2];
                }
                dp[i]=max(dp[i],pairSum);
            }
        }
        return dp[n-1];
    }
};
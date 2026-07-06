
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {

        int n = arr.size();

        vector<int> dp0(n); // no deletion
        vector<int> dp1(n); // one deletion

        dp0[0] = arr[0];
        dp1[0] = 0;

        int ans = arr[0];

        for(int i = 1; i < n; i++){

            // Normal Kadane
            dp0[i] = max(arr[i], dp0[i-1] + arr[i]);

            // Delete current OR already deleted before
            dp1[i] = max(dp0[i-1], dp1[i-1] + arr[i]);

            ans = max(ans, max(dp0[i], dp1[i]));
        }

        return ans;
    }
};


class Solution {
  public:
//   ✅ Correct way (minimum DP, interview-standard)
// Idea
// For every index:
// keep[i] → max subarray sum ending at i (no deletion)
// skip[i] → max subarray sum ending at i (one deletion allowed)
// Formula
// keep[i] = max(arr[i], keep[i-1] + arr[i])
// skip[i] = max(skip[i-1] + arr[i], keep[i-1])  // delete arr[i]
    int maxSumSubarray(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int keep = arr[0];      // no deletion
        int skip = 0;           // one deletion
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            skip = max(skip + arr[i], keep); // delete current
            keep = max(arr[i], keep + arr[i]);
            ans = max(ans, max(keep, skip));
        }
        return ans;
    }
};


class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];

        vector<int> forward(n);
        vector<int> backward(n);
        // Kadane from left
        forward[0] = arr[0];
        int ans = arr[0];
        for(int i = 1; i < n; i++){
            forward[i] = max(arr[i], forward[i-1] + arr[i]);
            ans = max(ans, forward[i]);
        }
        // Kadane from right
        backward[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--){
            backward[i] = max(arr[i], backward[i+1] + arr[i]);
        }
        // Delete one element
        for(int i = 1; i < n-1; i++){
            ans = max(ans, forward[i-1] + backward[i+1]);
        }
        return ans;
    }
};



class Solution {
public:
    int solve(int i, int del, vector<int>& arr, vector<vector<int>>& dp) {
        if(i == 0) {
            if(del == 0) return arr[0];
            return INT_MIN / 2;   // impossible (can't delete the only element)
        }
        if(dp[i][del] != INT_MIN) return dp[i][del];
        if(del == 0) {
            return dp[i][0] = max(arr[i], arr[i] + solve(i - 1, 0, arr, dp));
        }
        return dp[i][1] = max( solve(i - 1, 0, arr, dp),           // delete current
                arr[i] + solve(i - 1, 1, arr, dp)   // deletion already used
        );
    }
    int maxSumSubarray(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
        int ans = arr[0];
        for(int i = 0; i < n; i++) {
            ans = max(ans, solve(i, 0, arr, dp));
            ans = max(ans, solve(i, 1, arr, dp));
        }
        return ans;
    }
};
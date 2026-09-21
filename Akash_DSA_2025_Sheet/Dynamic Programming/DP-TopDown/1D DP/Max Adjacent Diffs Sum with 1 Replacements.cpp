
class Solution {
  public:
    long long solve(int i, int prev, vector<int>& arr,vector<vector<long long>>& dp) {

        int n = arr.size();

        // No more elements
        if(i == n)
            return 0;

        if(dp[i][prev] != -1)
            return dp[i][prev];


        long long ans = 0;


        // ------------------------------------
        // Choice 1: Keep arr[i]
        // ------------------------------------

        if(prev == 0) {
            // Previous element was arr[i-1]

            ans = max(ans,
                      llabs(1LL * arr[i] - arr[i-1])
                      + solve(i+1, 0, arr, dp));
        }
        else {
            // Previous element was 1

            ans = max(ans,
                      llabs(1LL * arr[i] - 1)
                      + solve(i+1, 0, arr, dp));
        }


        // ------------------------------------
        // Choice 2: Replace arr[i] by 1
        // ------------------------------------

        if(prev == 0) {
            // Previous element was arr[i-1]

            ans = max(ans,
                      llabs(1LL * arr[i-1] - 1)
                      + solve(i+1, 1, arr, dp));
        }
        else {
            // Previous element was 1

            ans = max(ans,
                      0LL + solve(i+1, 1, arr, dp));
        }


        return dp[i][prev] = ans;
    }


    int maxDiffSum(vector<int>& arr) {

        int n = arr.size();

        if(n <= 1)
            return 0;

        vector<vector<long long>> dp(n, vector<long long>(2, -1));

        // We need to handle index 0 separately.
        // At index 0 we can either keep arr[0]
        // or replace it by 1.

        long long keep =
            solve(1, 0, arr, dp);

        long long replace =
            solve(1, 1, arr, dp);

        return (int)max(keep, replace);
    }
};




class Solution {
  public:

    int maxDiffSum(vector<int>& arr) {

        int n = arr.size();

        if(n <= 1)
            return 0;


        // dp0 = current maximum when
        //       current element is original

        // dp1 = current maximum when
        //       current element is replaced by 1

        long long dp0 = 0;
        long long dp1 = 0;


        for(int i = 1; i < n; i++) {

            long long curr0;
            long long curr1;


            // Current element is kept as arr[i]

            curr0 = max(
                dp0 + llabs(1LL * arr[i] - arr[i-1]),
                dp1 + llabs(1LL * arr[i] - 1)
            );


            // Current element is changed to 1

            curr1 = max(
                dp0 + llabs(1LL * arr[i-1] - 1),
                dp1
            );


            dp0 = curr0;
            dp1 = curr1;
        }


        return (int)max(dp0, dp1);
    }
};



class Solution {
public:
    bool solve(int i, int sum, bool taken, vector<int>& arr, int k){
        if(i < 0){
            if(taken && sum % k == 0) return true;
            return false;
        }
        // Pick
        if(solve(i - 1, sum + arr[i], true, arr, k)) return true;

        // Not Pick
        if(solve(i - 1, sum, taken, arr, k)) return true;
        return false;
    }
    bool divisibleByK(vector<int>& arr, int k) {
        int n=arr.size();
        return solve(n - 1, 0, false, arr, k);
    }
};


class Solution {
  public:
    bool solve(int i, int rem, bool taken, vector<int>& arr, int k,vector<vector<vector<int>>> &dp){
        if(i < 0){
            return taken && rem == 0;
        }
        if(dp[i][rem][taken] != -1)return dp[i][rem][taken];
        
        // Pick
        bool pick = solve(i - 1, (rem + arr[i]) % k,true,arr,k,dp);

        // Not Pick
        bool notPick = solve(i - 1,rem,taken,arr,k,dp);
        
        return dp[i][rem][taken] = pick || notPick;
    }
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k,vector<int>(2,-1)));
        
        return solve(n - 1, 0, false, arr, k,dp);
    }
};



class Solution {
  public:
    bool divisibleByK(vector<int>& arr, int k) {
        int n = arr.size();

        if(n > k) return true;

        vector<vector<bool>> dp(n + 1, vector<bool>(k, false));
        for(int i = 1; i <= n; i++) {
            int x = arr[i - 1] % k;

            // Take current element alone
            dp[i][x] = true;
            for(int rem = 0; rem < k; rem++) {

                // Don't take
                if(dp[i - 1][rem]) dp[i][rem] = true;

                // Take
                if(dp[i - 1][rem]) dp[i][(rem + x) % k] = true;
            }
        }
        return dp[n][0];
    }
};

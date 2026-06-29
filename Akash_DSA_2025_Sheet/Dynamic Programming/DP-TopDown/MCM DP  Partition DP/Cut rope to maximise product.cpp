
class Solution {
  public:
    int solve(int n, vector<int>& dp){
        if(n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        
        int ans = 0;
        for(int i = 1; i < n; i++){
            ans = max(ans,max(i * (n - i), i * solve(n - i, dp)));
        }
        return dp[n] = ans;
    }
    int maxProduct(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};


class Solution {
  public:
    int maxProduct(int n) {
        vector<int> dp(n + 1, 0);
        dp[1]=1;
        for(int len=2;len<=n;len++){
            int ans = 0;
        for(int i = 1; i < len; i++){
            ans = max(ans,max(i * (len - i), i * dp[len-i]));
        }
        dp[len] = ans;
        }
        return dp[n];
    }
};


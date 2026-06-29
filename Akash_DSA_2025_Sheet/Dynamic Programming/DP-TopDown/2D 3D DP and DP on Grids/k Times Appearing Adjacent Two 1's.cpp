
class Solution {
  public:
    int MOD = 1e9 + 7;
    int solve(int len,int cnt,int last,int n,int k,vector<vector<vector<int>>>&dp){
        if(cnt > k) return 0;
        if(len == n) return (cnt == k);
        
        if(dp[len][cnt][last] != -1) return dp[len][cnt][last];
        
        long long ans = 0;
        // Place 0
        ans += solve(len + 1, cnt, 0, n, k, dp);
        // Place 1
        if(last == 1){
            ans += solve(len + 1, cnt + 1, 1, n, k, dp);
        }
        else{
            ans += solve(len + 1, cnt, 1, n, k, dp);
        }
        return dp[len][cnt][last] = ans % MOD;
    }
    int countStrings(int n, int k) {
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(k + 1,vector<int>(2, -1)));
        long long ans = 0;
        // First bit = 0
        ans += solve(1,0,0,n,k,dp);
        // First bit = 1
        ans += solve(1,0,1,n,k,dp);
        return ans % MOD;
    }
};


class Solution {
  public:
    int MOD = 1e9 + 7;
    int countStrings(int n, int k) {
        vector<vector<vector<long long>>> dp(n + 1,vector<vector<long long>>(k + 1,vector<long long>(2,0)));

        // Length = 1
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        for(int len = 1; len < n; len++){
            for(int cnt = 0; cnt <= k; cnt++){
                // Previous bit = 0
                if(dp[len][cnt][0]){
                    // Put 0
                    dp[len+1][cnt][0] = (dp[len+1][cnt][0] + dp[len][cnt][0]) % MOD;

                    // Put 1
                    dp[len+1][cnt][1] = (dp[len+1][cnt][1] + dp[len][cnt][0]) % MOD;
                }

                // Previous bit = 1
                if(dp[len][cnt][1]){

                    // Put 0
                    dp[len+1][cnt][0] = (dp[len+1][cnt][0] + dp[len][cnt][1]) % MOD;

                    // Put 1
                    if(cnt + 1 <= k){
                        dp[len+1][cnt+1][1] = (dp[len+1][cnt+1][1] + dp[len][cnt][1]) % MOD;
                    }
                }
            }
        }
        return (dp[n][k][0] + dp[n][k][1]) % MOD;
    }
};
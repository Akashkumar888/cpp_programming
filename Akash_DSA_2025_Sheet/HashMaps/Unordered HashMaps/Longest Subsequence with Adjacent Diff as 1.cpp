
class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[x] = longest subsequence
        //         ending with value x
        vector<int> dp(1000002, 0);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int x = arr[i];
            // Current x can be attached after
            // x-1 or x+1
            dp[x] = max(dp[x-1], dp[x+1]) + 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};



class Solution {
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        vector<int> dp(n, 1);
        int maxi = 0;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(abs(a[i] - a[j]) == 1 and dp[i] < 1 + dp[j])
                    dp[i] = 1 + dp[j];
                    
                maxi = max(maxi, dp[i]);
            }
        }
        
        return maxi;
    }
};


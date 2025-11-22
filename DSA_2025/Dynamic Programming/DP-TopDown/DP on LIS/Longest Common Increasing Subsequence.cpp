class Solution {
public:
// Longest Common Increasing Subsequence
// Longest Increasing Subsequence -> array me hai gfg and leetcode pr 
// Longest Common Subsequence  -> string me hai gfg and leetcode pr 

    int LCIS(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> dp(m, 0);// Longest Increasing Subsequence me dp(m,1) ho skta but Longest Common Increasing Subsequence me nhi hoga isliye dp(m,0 
        int lcis=0;
        // jisme dp bhra hai uske oppsite vale array me traverse krna hai 
        for (int i = 0; i < n; i++) {
            int currentMax = 0;
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    dp[j] = currentMax + 1;
                    lcis=max(lcis,dp[j]);
                } 
                else if (a[i] > b[j]) {
                    currentMax = max(currentMax, dp[j]);
                }
            }
        }
        return lcis;
    }
};


class Solution {
public:
// Longest Common Increasing Subsequence
// Longest Increasing Subsequence -> array me hai gfg and leetcode pr 
// Longest Common Subsequence  -> string me hai gfg and leetcode pr 

    int LCIS(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        vector<int> dp(n, 0);// Longest Increasing Subsequence me dp(m,1) ho skta but Longest Common Increasing Subsequence me nhi hoga isliye dp(m,0 
        int lcis=0;
        // jisme dp bhra hai uske oppsite vale array me traverse krna hai 
        for (int i = 0; i < m; i++) {
            int currentMax = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == b[i]) {
                    dp[j] = currentMax + 1;
                    lcis=max(lcis,dp[j]);
                } 
                else if (a[j] < b[i]) {
                    currentMax = max(currentMax, dp[j]);
                }
            }
        }
        return lcis;
    }
};


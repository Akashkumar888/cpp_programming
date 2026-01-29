
class Solution {
public:
    bool f(int i,int j,string &p,string &s,vector<vector<int>>&dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(j < 0){
            // if pattern has only stars like a*, b*, etc.
            if(p[i] == '*') return f(i-2, j, p, s, dp);
            else return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i] == s[j] || p[i] == '.'){
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        }
        if(p[i] == '*'){
            bool zeroOccur = f(i-2, j, p, s, dp);
            bool oneOrMore = false;
            if(p[i-1] == s[j] || p[i-1] == '.'){
                oneOrMore = f(i, j-1, p, s, dp);
            }
            return dp[i][j] = (zeroOccur || oneOrMore);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m-1, n-1, p, s, dp);
    }
};

class Solution {
public:
    bool f(int i,int j,string &p,string &s,vector<vector<int>>&dp){
        if(i == 0 && j == 0) return true;
        if(i == 0 && j >= 1) return false;
        if(j == 0){
            // if pattern has only stars like a*, b*, etc.
            if(p[i-1] == '*') return f(i-2, j, p, s, dp);
            else return false;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(p[i-1] == s[j-1] || p[i-1] == '.'){
            return dp[i][j] = f(i-1, j-1, p, s, dp);
        }
        if(p[i-1] == '*'){
            bool zeroOccur = f(i-2, j, p, s, dp);
            bool oneOrMore = false;
            if(p[i-2] == s[j-1] || p[i-2] == '.'){
                oneOrMore = f(i, j-1, p, s, dp);
            }
            return dp[i][j] = (zeroOccur || oneOrMore);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = p.size();
        int n = s.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return f(m, n, p, s, dp);
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // empty string matches empty pattern
        dp[0][0] = true;

        // pattern like a*, a*b*, a*b*c* can match empty string
        for (int j = 2; j <= m; j++) {
            if (p[j-1] == '*')
                dp[0][j] = dp[0][j-2];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // case 1: direct match or '.'
                if (p[j-1] == s[i-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                }

                // case 2: '*'
                else if (p[j-1] == '*') {

                    // zero occurrence of preceding character
                    dp[i][j] = dp[i][j-2];

                    // one or more occurrence
                    if (p[j-2] == s[i-1] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                }

                // else dp[i][j] remains false
            }
        }

        return dp[n][m];
    }
};

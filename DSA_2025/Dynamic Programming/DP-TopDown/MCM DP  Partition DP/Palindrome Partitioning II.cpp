
class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
int solve(int i,int j,string &s,vector<vector<int>>&dp){
    if(i>=j)return 0;  // single char or empty
        if(isPalindrome(i,j,s)) return 0; // already palindrome
        if(dp[i][j]!=-1)return dp[i][j];
        int minCuts=INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(i, k, s)){  // left part must be palindrome left=1;
                int left=1;
                int right=solve(k+1,j,s,dp);
                minCuts=min(minCuts,left+right);
            }
        }
    return dp[i][j]=minCuts;
}
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,n-1,s,dp);
    }
};



class Solution {
public:
bool isPalindrome(int i,int j,string &s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        // base case for length = 1 -> 0 cuts
        for(int i = 0; i < n; i++)dp[i][i] = 0;
        // bottom-up: increasing substring length
        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;
                if(isPalindrome(i, j, s)){
                    dp[i][j] = 0;
                    continue;
                }
                int minCuts = INT_MAX;
                for(int k = i; k < j; k++){
                    if(isPalindrome(i, k, s)){
                        int left = 1;
                        int right = dp[k+1][j];
                        minCuts = min(minCuts, left + right);
                    }
                }
                dp[i][j] = minCuts;
            }
        }
        return dp[0][n-1];
    }
};

class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n, 0);

        // ----------- PRECOMPUTE PALINDROME TABLE ------------
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] && (j - i <= 2 || pal[i+1][j-1])){
                    pal[i][j] = true;
                }
            }
        }

        // -------------------- DP ----------------------------
        for(int i = 0; i < n; i++){
            if(pal[0][i]){    // entire substring 0..i is palindrome
                dp[i] = 0;
                continue;
            }

            int minCuts = INT_MAX;

            for(int k = 0; k < i; k++){
                if(pal[k+1][i]){
                    minCuts = min(minCuts, dp[k] + 1);
                }
            }

            dp[i] = minCuts;
        }

        return dp[n-1];
    }
};

class Solution {
  public:
// '?' – matches any single character
// '*' – matches any sequence of characters (including the empty sequence).
int solve(int i,string &pat,int j,string &txt,vector<vector<int>>&dp){
    if(i<0 && j<0)return true;
    if(i<0 && j>=0)return false;
    if(j<0 && i>=0){
        for(int k=i;k>=0;k--){
            if(pat[k]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pat[i]==txt[j] || pat[i]=='?')return dp[i][j]= solve(i-1,pat,j-1,txt,dp);
    else if(pat[i]=='*')return dp[i][j]=solve(i,pat,j-1,txt,dp) || solve(i-1,pat,j,txt,dp);
    return dp[i][j]=false;
}
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=pat.size();
        int m=txt.size();
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(n-1,pat,m-1,txt,dp);
    }
};


class Solution {
  public:
// '?' – matches any single character
// '*' – matches any sequence of characters (including the empty sequence).
// after doing indexing 
// recursion me hr jagah i to i-1 or j to j-1 not in dp
// dp size increase [n+1][m+1] or [m+1][n+1]
int solve(int i,string &pat,int j,string &txt,vector<vector<int>>&dp){
    if(i==0 && j==0)return true;
    if(i==0 && j>=1)return false;
    if(j==0 && i>=1){
        for(int k=i;k>=1;k--){
            if(pat[k-1]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pat[i-1]==txt[j-1] || pat[i-1]=='?')return dp[i][j]= solve(i-1,pat,j-1,txt,dp);
    else if(pat[i-1]=='*')return dp[i][j]=solve(i,pat,j-1,txt,dp) || solve(i-1,pat,j,txt,dp);
    return dp[i][j]=false;
}
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=pat.size();
        int m=txt.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,pat,m,txt,dp);// after doing indexing 
    }
};


class Solution {
  public:
// '?' – matches any single character
// '*' – matches any sequence of characters (including the empty sequence).
// after doing indexing 
// recursion me hr jagah jaha pr string check ho raha hai vaha function me nhi i to i-1 or j to j-1 not in dp
// dp size increase [n+1][m+1] or [m+1][n+1]
int solve(int i,string &pat,int j,string &txt,vector<vector<int>>&dp){
    if(i==0 && j==0)return true;
    if(i==0 && j>=1)return false;
    if(j==0 && i>=1){
        for(int k=i;k>=1;k--){
            if(pat[k-1]!='*')return false;
        }
        return true;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    if(pat[i-1]==txt[j-1] || pat[i-1]=='?')return dp[i][j]= solve(i-1,pat,j-1,txt,dp);
    else if(pat[i-1]=='*')return dp[i][j]=solve(i,pat,j-1,txt,dp) || solve(i-1,pat,j,txt,dp);
    return dp[i][j]=false; // else condition hai 
}
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=pat.size();
        int m=txt.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,false));
        // Base cases
        dp[0][0] = true;

        // Pattern empty -> cannot match non-empty text
        for (int j = 1; j <= m; j++)
            dp[0][j] = false;

        // Text empty -> only matches if pattern up to i is all '*'
        for (int i = 1; i <= n; i++) {
            bool allStar = true;
            for (int k = i; k >= 1; k--) {
                if (pat[k - 1] != '*') {
                    allStar = false;
                    break;
                }
            }
            dp[i][0] = allStar;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pat[i-1]==txt[j-1] || pat[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(pat[i-1]=='*')dp[i][j]= dp[i][j-1]+dp[i-1][j];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};

// 🧠 Concept: Why We Do Index Shifting
// When we write recursive solutions for problems like pattern matching, LCS, edit distance, etc.,
// we often use 0-based indexing (because strings and arrays in C++ are 0-based).
// That means:
// The first character is at index 0
// The last character is at index n-1
// However, when we convert this recursive solution into a tabulated DP (bottom-up) version,
// it becomes more convenient to use 1-based indexing for the DP table.
// This process is called index shifting.
// 🧩 The Problem Without Shifting (0-based recursion)

// Let’s look at your original recursion (before shifting):
// if (i < 0 && j < 0) return true;
// if (i < 0 && j >= 0) return false;
// if (j < 0 && i >= 0) {
//     for (int k = i; k >= 0; k--) {
//         if (pat[k] != '*') return false;
//     }
//     return true;
// }

// Here, we treat:
// i as the index of the current character in pat
// j as the index in txt
// When we reach i = -1 or j = -1, it means we’ve processed all characters.
// That’s fine for recursion, but it causes issues for bottom-up DP:
// We can’t make a table of size n x m and then try to access dp[-1][something] — that’s invalid.
// 🎯 The Solution: Shift Indices by +1
// So instead of saying:
// “When i = -1, pattern is empty”
// We say:
// “When i = 0, pattern is empty.”
// In other words:

// We shift every i and j one step forward.
// The new index represents the length of the processed prefix, not the index itself.
// 💡 After Shifting
// Meaning	                         Old (0-based)	                       New (1-based, shifted)
// End of both strings	             i < 0 && j < 0	                       i == 0 && j == 0
// Pattern empty	                   i < 0	                               i == 0
// Text empty	                       j < 0	                               j == 0
// Current character in pattern	     pat[i]	                               pat[i-1]
// Current character in text	       txt[j]	                               txt[j-1]

// 🧩 Changes Needed in Code
// When we move from recursion (0-based) → tabulation (1-based), we make three systematic changes:
// Why this change?
// Because now i and j represent lengths, not indices.
// So when i == 0, it means the pattern has no characters left — same meaning as i == -1 before.
// Why subtract 1?
// Because even after shifting, string characters are still 0-based in C++.
// So when i == 1, it refers to the first character, i.e., pat[0].
// 3️⃣ DP Table Size and Loops
// Old recursion uses i and j up to n-1 and m-1,
// so we make DP of size n x m.
// After shifting, we must make DP of size (n+1) x (m+1) because:
// We need an extra row and column to represent the “empty” pattern and “empty” text cases.

// ✅ Correct:
// vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
// 🔄 Summary of Changes (Step-by-Step Flow in Words)
// Start from recursion (0-based): indices run from 0 → n-1.
// Base cases involve negative indices (i < 0 or j < 0).
// Add +1 shift: represent the processed prefix length.
// Now i == 0 means "empty prefix" instead of i == -1.
// Adjust base cases:
// Replace all conditions involving i < 0 or j < 0 with i == 0 or j == 0.
// Access strings carefully:
// Since pat and txt are still 0-based, use pat[i-1] and txt[j-1].
// Resize DP:
// Create dp[n+1][m+1] instead of dp[n][m].
// Initialize the first row and column:
// Handle “empty pattern” and “empty text” scenarios explicitly.
// 💬 In Summary (Theoretical Explanation)
// When you shift indices in recursion or DP:
// You replace negative base cases (i < 0, j < 0) with 0-based ones (i == 0, j == 0).
// You increase the DP table size by +1 to include the "empty prefix" cases.
// You access string characters using pat[i-1], txt[j-1] since strings remain 0-indexed.
// You make recursion → DP conversion seamless and avoid invalid negative indices.
// This approach makes transitions clean, especially for problems involving strings or subsequences.

class Solution {
public:
bool palindrome(int i,int j,string &s,vector<vector<int>>&dp){
      if(i>=j)return true;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==s[j])return dp[i][j]= palindrome(i+1,j-1,s,dp);
      return dp[i][j]=false;
  }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int start=0;
        int maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palindrome(i,j,s,dp)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }
    return s.substr(start,maxlen);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n <= 1) return s;

        int start = 0, maxLen = 1;

        auto expand = [&](int l, int r) {
            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }
                l--; r++;
            }
        };

        for(int i = 0; i < n; i++) {
            expand(i, i);     // odd length
            expand(i, i + 1); // even length
        }

        return s.substr(start, maxLen);
    }
};


class Solution {
  public:
  bool isPalindrome(int i,int j,string &s){
      while(i<j){
          if(s[i]!=s[j])return false;
          i++,j--;
      }
      return true;
  }
    int countPS(string &s) {
        // code here
        int count=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j-i+1>=2 &&isPalindrome(i,j,s))count++;
            }
        }
        return count;
    }
};



class Solution {
  public:
  bool palindrome(int i,int j,string &s,vector<vector<int>>&dp){
      if(i>=j)return true;
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==s[j])return dp[i][j]= palindrome(i+1,j-1,s,dp);
      return dp[i][j]=false;
  }
    int countPS(string &s) {
        // code here
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j-i+1>=2 &&palindrome(i,j,s,dp))count++;
            }
        }
        return count;
    }
};


class Solution {
public:
    int countPS(string &s) {
        int n = s.size();
        int count = 0;

        // Function to expand from the center and count palindromes
        auto expand = [&](int left, int right) {
            int cnt = 0;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2) cnt++; // length >= 2
                left--;
                right++;
            }
            return cnt;
        };

        // Odd length palindromes
        for (int center = 0; center < n; center++) {
            count += expand(center, center);
        }

        // Even length palindromes
        for (int center = 0; center < n - 1; center++) {
            count += expand(center, center + 1);
        }

        return count;
    }
};

// Complexity
// Time: O(n²) — worst case when all characters are the same.

// Space: O(1) — only variables for counting, no big DP table.


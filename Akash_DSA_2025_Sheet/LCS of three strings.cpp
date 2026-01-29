
class Solution {
  public:
  int lcs(int i,int j,int k,string &s1,string&s2,string &s3,vector<vector<vector<int>>>&dp){
      if(i<0 || j<0||k<0)return 0;
      if(dp[i][j][k]!=-1)return dp[i][j][k];
      if(s1[i]==s2[j] && s2[j]==s3[k]){
          return dp[i][j][k]= 1+lcs(i-1,j-1,k-1,s1,s2,s3,dp);
      }
      // 2 string 2!=2 combination
      // 3 string 3!=6 combination 
    return dp[i][j][k] = max({
    lcs(i-1, j, k, s1, s2, s3, dp),
    lcs(i, j-1, k, s1, s2, s3, dp),
    lcs(i, j, k-1, s1, s2, s3, dp),
    lcs(i-1, j-1, k, s1, s2, s3, dp),
    lcs(i-1, j, k-1, s1, s2, s3, dp),
    lcs(i, j-1, k-1, s1, s2, s3, dp)
});
  }
    int lcsOf3(string& s1, string& s2, string& s3) {
        // Code here
        int l=s1.size();
        int m=s2.size();
        int n=s3.size();
        vector<vector<vector<int>>>dp(l,vector<vector<int>>(m,vector<int>(n,-1)));
        return lcs(l-1,m-1,n-1,s1,s2,s3,dp);
    }
};



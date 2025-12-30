
class Solution {
  public:
  int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int minCost=INT_MAX;
      for(int mid=i;mid<=j;mid++){
          int cost=(cuts[j+1]-cuts[i-1])+solve(i,mid-1,cuts,dp) 
          + solve(mid+1,j,cuts,dp);
          minCost=min(minCost,cost);
      }
      return dp[i][j]=minCost;
  }
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end()); // non overlapping cuts 

        // cuts.size() = k + 2
        // indices: 0 1 2 ... k k+1
        // But:
        // Actual cut positions are only from 1 to k
        // cuts[k+1] = n is a boundary, NOT a cut
        // int m = cuts.size();   // m = original number of cuts
        // cuts.insert(cuts.begin(), 0);
        // cuts.push_back(n);
        // ...
        // return solve(1, m, cuts, dp);

        vector<vector<int>>dp(m+2,vector<int>(m+2,-1));
        return solve(1,m,cuts,dp);
    }
};


class Solution {
  public:
    int minCutCost(int n, vector<int>& cuts) {
        // code here
        int m=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end()); // non overlapping cuts 

        vector<vector<int>>dp(m+2,vector<int>(m+2,0));
        for(int i=m;i>=1;i--){
            for(int j=1;j<=m;j++){
                if(i>j)continue;
                int minCost=INT_MAX;
              for(int mid=i;mid<=j;mid++){
                  int cost=(cuts[j+1]-cuts[i-1])+dp[i][mid-1] 
                  + dp[mid+1][j];
                  minCost=min(minCost,cost);
              }
              dp[i][j]=minCost;
            }
        }
        return dp[1][m];
    }
};


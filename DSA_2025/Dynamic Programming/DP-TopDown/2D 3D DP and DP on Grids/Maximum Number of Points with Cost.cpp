
class Solution {
public:
long long solve(int i,int j,vector<vector<int>>&points,vector<vector<long long>>&dp){
      if(i<0||j<0 || i>=points.size() || j>=points[0].size())return LLONG_MIN;
      if (i==0)return points[0][j];
      if(dp[i][j]!=-1)return dp[i][j];
      int n = points[0].size();
      long long maxPoints = LLONG_MIN;
        // try all possible previous columns k
        for (int k = 0; k < n; k++) {
            long long prev = solve(i - 1, k, points, dp);
            if (prev == LLONG_MIN) continue;
            long long curr = prev - abs(j - k);
            maxPoints = max(maxPoints, curr);
        }
        return dp[i][j] = maxPoints + points[i][j];
  }
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n+1,-1));
        long long maxSum = LLONG_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,solve(m-1,j,points,dp));
        }
        return maxSum;
    }
};


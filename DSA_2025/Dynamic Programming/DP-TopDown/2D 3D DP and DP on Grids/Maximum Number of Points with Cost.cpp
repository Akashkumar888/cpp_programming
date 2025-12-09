class Solution {
public:
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
// x for x >= 0.
// -x for x < 0.
long long solve(int i,int j,vector<vector<int>>&points,vector<vector<long long>>&dp){
      if(i<0||j<0 || i>=points.size() || j>=points[0].size())return LLONG_MIN;
      if (i==0)return points[0][j];
      if(dp[i][j]!=-1)return dp[i][j];
      long long maxPoints=LLONG_MIN;
        // try all possible previous columns k
        for(int k=0;k<points[0].size();k++){
            long long prev=solve(i-1,k,points,dp);
            if(prev==LLONG_MIN)dp[i][j]=LLONG_MIN;
            long long curr=prev-abs(j-k);
            maxPoints=max(maxPoints,curr);
        }
        return dp[i][j]=maxPoints+points[i][j];
  }
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n+1,-1));
        long long maxSum=LLONG_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,solve(m-1,j,points,dp));
        }
        return maxSum;
    }
};

class Solution {
public:
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
// x for x >= 0.
// -x for x < 0.
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n+1,0));
        // base case 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0)dp[0][j]=points[0][j];
                else{
                long long maxPoints=LLONG_MIN;
            // try all possible previous columns k
            for(int k=0;k<points[0].size();k++){
                long long prev=dp[i-1][k];
                if(prev==LLONG_MIN)dp[i][j]=LLONG_MIN;
                long long curr=prev-abs(j-k);
                maxPoints=max(maxPoints,curr);
            }
            dp[i][j]=maxPoints+points[i][j];
                }
            }
        }
        long long maxSum=LLONG_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,dp[m-1][j]);
        }
        return maxSum;
    }
};

class Solution {
public:
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
// x for x >= 0.
// -x for x < 0.
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<vector<long long>>dp(m,vector<long long>(n+1,0));
        // base case 
        for(int j=0;j<n;j++)dp[0][j]=points[0][j];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                
                long long maxPoints=LLONG_MIN;
            // try all possible previous columns k
            for(int k=0;k<points[0].size();k++){
                long long prev=dp[i-1][k];
                if(prev==LLONG_MIN)dp[i][j]=LLONG_MIN;
                long long curr=prev-abs(j-k);
                maxPoints=max(maxPoints,curr);
            }
            dp[i][j]=maxPoints+points[i][j];
            }
        }
        long long maxSum=LLONG_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,dp[m-1][j]);
        }
        return maxSum;
    }
};

class Solution {
public:
// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.
// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.
// Return the maximum number of points you can achieve.
// abs(x) is defined as:
// x for x >= 0.
// -x for x < 0.
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<long long>prev(n,LLONG_MIN),temp(n,LLONG_MIN);
        // base case 
        for(int j=0;j<n;j++)prev[j]=points[0][j]; // base start from first prev then curr or temp
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                
            long long maxPoints=LLONG_MIN;
            // try all possible previous columns k
            for(int k=0;k<points[0].size();k++){
                long long curr=LLONG_MIN;
                if(i-1>=0) curr=prev[k];
                if(curr==LLONG_MIN)temp[j]=LLONG_MIN;
                long long value=curr-abs(j-k);
                maxPoints=max(maxPoints,value);
            }
            temp[j]=maxPoints+points[i][j];
            }
            prev=temp;
        }
        long long maxSum=LLONG_MIN;
        for(int j=0;j<n;j++){
            maxSum=max(maxSum,prev[j]);
        }
        return maxSum;
    }
};


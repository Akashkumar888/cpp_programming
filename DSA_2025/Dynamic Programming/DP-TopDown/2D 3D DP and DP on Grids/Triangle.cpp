
class Solution {
public:
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// From (i, j) → next row:(i+1, j) (i+1, j+1)
// i use top down then 
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    if(i<0 || j<0 ||j >= triangle[i].size())return INT_MAX;
    if(i==0 && j==0)return triangle[0][0];
    if(dp[i][j]!=-1)return dp[i][j];
    // Move from top row: (i-1, j) or (i-1, j-1)
    int dia=solve(i-1,j-1,triangle,dp);
    int up=solve(i-1,j,triangle,dp);
    // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
    if(dia==INT_MAX && up==INT_MAX)return dp[i][j]=INT_MAX;
    int minPathSum=min(dia,up)+triangle[i][j];
    return dp[i][j]=minPathSum;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m);
        // DP shape exactly matches triangle
        for(int i = 0; i < m; i++)dp[i].resize(triangle[i].size(),-1);
        
        int minSum=INT_MAX;
        for(int j=0;j<triangle[m-1].size();j++){// because dynamic colomn size
            minSum=min(minSum,solve(m-1,j,triangle,dp));
        }
        return minSum;
    }
};

class Solution {
public:
    // if you are on index i on the current row, you may move to either index i
    // or index i + 1 on the next row. From (i, j) → next row:(i+1, j) (i+1,
    // j+1) i use top down then
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // thumb rule for bottom up
        // bottom up is a opposite of recurive solution
        vector<vector<int>> dp(m);
        // DP shape exactly matches triangle
        // ✔ dp shape must match triangle
        for (int i = 0; i < m; i++)
            dp[i].resize(triangle[i].size(), 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = triangle[0][0];
                else {
                    // Move from top row: (i-1, j) or (i-1, j-1)
                    int dia = INT_MAX, up = INT_MAX;
                    if (i > 0 && j > 0)
                        dia = dp[i - 1][j - 1];
                    if (i > 0 && j < dp[i - 1].size())
                        up = dp[i - 1][j];
                    // if both directions impossible → return INT_MAX (do NOT
                    // add grid[i][j])
                    if (dia == INT_MAX && up == INT_MAX)
                        return dp[i][j] = INT_MAX;
                    int minPathSum = min(dia, up) + triangle[i][j];
                    dp[i][j] = minPathSum;
                }
            }
        }
        // ✔ return the minimum value in last row
        int ans = INT_MAX;
        for (int j = 0; j < dp[m - 1].size(); j++) {
            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
};


class Solution {
public:
    // if you are on index i on the current row, you may move to either index i
    // or index i + 1 on the next row. From (i, j) → next row:(i+1, j) (i+1,
    // j+1) i use top down then
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        // thumb rule for bottom up
        // bottom up is a opposite of recurive solution
        // prev will store dp of previous row
        vector<int> prev = {triangle[0][0]}; // row 0 has 1 element
        // DP shape exactly matches triangle
        // ✔ dp shape must match triangle

        for (int i = 0; i < m; i++) {
            vector<int> temp(triangle[i].size(), 0);
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i == 0 && j == 0)
                    temp[j] = triangle[0][0];
                else {
                    // Move from top row: (i-1, j) or (i-1, j-1)
                    int dia = INT_MAX, up = INT_MAX;
                    if (j > 0)
                        dia = prev[j - 1];
                    if (j < prev.size())
                        up = prev[j];
                    // if both directions impossible → return INT_MAX (do NOT
                    // add grid[i][j])
                    if (dia == INT_MAX && up == INT_MAX)
                        return temp[j] = INT_MAX;
                    int minPathSum = min(dia, up) + triangle[i][j];
                    temp[j] = minPathSum;
                }
            }
            prev = temp;
        }
        // ✔ return the minimum value in last row
        int ans = INT_MAX;
        for (int j = 0; j < prev.size(); j++) {
            ans = min(ans, prev[j]);
        }
        return ans;
    }
};

class Solution {
public:
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// From (i, j) → next row:(i+1, j) (i+1, j+1)
// i use top down then 
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    if(i==triangle.size()-1)return triangle[triangle.size()-1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    // Move from top row: (i-1, j) or (i-1, j-1)
    int dia=solve(i+1,j+1,triangle,dp);
    int up=solve(i+1,j,triangle,dp);
    // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
    if(dia==INT_MAX && up==INT_MAX)return dp[i][j]=INT_MAX;
    int minPathSum=min(dia,up)+triangle[i][j];
    return dp[i][j]=minPathSum;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m);
        // DP shape exactly matches triangle
        for(int i = 0; i < m; i++)dp[i].resize(triangle[i].size(),-1);
        return solve(0,0,triangle,dp);// always start from fixed points it is easy to write code 
    }
};

class Solution {
public:
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// From (i, j) → next row:(i+1, j) (i+1, j+1)
// i use top down then 
int solve(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    if(i==triangle.size()-1)return triangle[triangle.size()-1][j];
    if(dp[i][j]!=-1)return dp[i][j];
    // Move from top row: (i-1, j) or (i-1, j-1)
    int dia=solve(i+1,j+1,triangle,dp);
    int up=solve(i+1,j,triangle,dp);
    // if both directions impossible → return INT_MAX (do NOT add grid[i][j])
    if(dia==INT_MAX && up==INT_MAX)return dp[i][j]=INT_MAX;
    int minPathSum=min(dia,up)+triangle[i][j];
    return dp[i][j]=minPathSum;
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        // thumb rule for bottom up
        // bottom up is a opposite of recurive solution
        vector<vector<int>> dp(m);
        // DP shape exactly matches triangle
        // ✔ dp shape must match triangle
        for (int i = 0; i < m; i++)dp[i].resize(triangle[i].size(), INT_MAX);
        for (int i = m-1; i >=0; i--) {
            for (int j = 0; j <triangle[i].size() ; j++){
                if (i == m-1)dp[m-1][j] = triangle[m-1][j];
                else {
                    // Move from top row: (i+1, j) or (i+1, j+1)
                    int dia = dp[i + 1][j + 1];
                    int down = dp[i + 1][j];
                    // if both directions impossible → return INT_MAX (do NOT
                    // add grid[i][j])
                    if (dia == INT_MAX && down == INT_MAX)return dp[i][j] = INT_MAX;
                    int minPathSum = min(dia, down) + triangle[i][j];
                    dp[i][j] = minPathSum;
                }
            }
        }
        return dp[0][0];// always start from fixed points it is easy to write code 
    }
};


class Solution {
public:
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// From (i, j) → next row:(i+1, j) (i+1, j+1)
// i use top down then 
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        // thumb rule for bottom up
        // bottom up is a opposite of recurive solution
        vector<vector<int>> dp(m);
        // DP shape exactly matches triangle
        // ✔ dp shape must match triangle
        for (int i = 0; i < m; i++)dp[i].resize(triangle[i].size(), INT_MAX);
        for(int j=0;j<triangle[m-1].size();j++)dp[m-1][j] = triangle[m-1][j];
        for (int i = m-2; i >=0; i--) {
            for (int j = 0; j <triangle[i].size() ; j++){
                    // Move from top row: (i+1, j) or (i+1, j+1)
                    int dia = dp[i + 1][j + 1];
                    int down = dp[i + 1][j];
                    // if both directions impossible → return INT_MAX (do NOT
                    // add grid[i][j])
                    if (dia == INT_MAX && down == INT_MAX)return dp[i][j] = INT_MAX;
                    int minPathSum = min(dia, down) + triangle[i][j];
                    dp[i][j] = minPathSum;
            }
        }
        return dp[0][0];// always start from fixed points it is easy to write code 
    }
};

class Solution {
public:
// if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// From (i, j) → next row:(i+1, j) (i+1, j+1)
// i use top down then 
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        // thumb rule for bottom up
        // bottom up is a opposite of recurive solution
        vector<int> prev(m,INT_MAX);
        // DP shape exactly matches triangle
        // ✔ dp shape must match triangle
        for(int j=0;j<triangle[m-1].size();j++)prev[j] = triangle[m-1][j];
        for (int i = m-2; i >=0; i--) {
            vector<int>temp(triangle[i].size(),INT_MAX);
            for (int j = 0; j <triangle[i].size() ; j++){
                    // Move from top row: (i+1, j) or (i+1, j+1)
                    int dia = prev[j + 1];
                    int down = prev[j];
                    // if both directions impossible → return INT_MAX (do NOT
                    // add grid[i][j])
                    if (dia == INT_MAX && down == INT_MAX)return temp[j] = INT_MAX;
                    int minPathSum = min(dia, down) + triangle[i][j];
                    temp[j] = minPathSum;
            }
            prev=temp;
        }
        return prev[0];// always start from fixed points it is easy to write code 
    }
};
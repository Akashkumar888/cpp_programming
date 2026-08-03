
class Solution {
  public:
    int maximumSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        vector<vector<int>> preSum(n, vector<int>(n, 0));
        // Prefix Sum
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                preSum[i][j] = mat[i][j];
                if(i > 0) preSum[i][j] += preSum[i - 1][j];
                if(j > 0) preSum[i][j] += preSum[i][j - 1];
                if(i > 0 && j > 0) preSum[i][j] -= preSum[i - 1][j - 1];
            }
        }
        int maxSum = INT_MIN;
        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= n - k; j++) {
                int r1 = i;
                int c1 = j;
                int r2 = i + k - 1;
                int c2 = j + k - 1;
                int sum = preSum[r2][c2];
                if(r1 > 0) sum -= preSum[r1 - 1][c2];
                if(c1 > 0) sum -= preSum[r2][c1 - 1];
                if(r1 > 0 && c1 > 0) sum += preSum[r1 - 1][c1 - 1];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};
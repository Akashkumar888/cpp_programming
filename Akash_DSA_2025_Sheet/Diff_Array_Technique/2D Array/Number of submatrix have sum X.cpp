
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>preSum(n,vector<int>(m, 0));
        
        // Build prefix sum
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                preSum[i][j]=mat[i][j];
                if(i-1 >= 0)preSum[i][j] += preSum[i-1][j];
                if(j-1 >= 0)preSum[i][j] += preSum[i][j-1];
                if(i-1 >= 0 && j-1 >= 0)preSum[i][j] -= preSum[i-1][j-1];
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int size = 1;size<=min(n-i, m-j);size++){
                    int r1 = i;
                    int c1 = j;
                    int r2 = i + size - 1;
                    int c2 = j + size - 1;
                    int sum=preSum[r2][c2];
                    if(r1-1 >= 0)sum -= preSum[r1-1][c2];
                    if(c1-1 >= 0)sum -= preSum[r2][c1-1];
                    if(r1-1 >= 0 && c1-1 >= 0)sum += preSum[r1-1][c1-1];
                    if(sum == x)count++;
                }
            }
        }
        return count;
    }
};
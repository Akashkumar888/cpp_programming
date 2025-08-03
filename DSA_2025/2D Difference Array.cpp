
class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<opr.size();i++){
            int v=opr[i][0];
            int r1=opr[i][1];
            int c1=opr[i][2];
            int r2=opr[i][3];
            int c2=opr[i][4];
            diff[r1][c1]+=v;
            if(c2+1<n)diff[r1][c2+1]-=v;
            if(r2+1<m)diff[r2+1][c1]-=v;
            if(r2+1<m&&c2+1<n)diff[r2+1][c2+1]+=v;
        }
        // Prefix sum over rows and columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) diff[i][j] += diff[i - 1][j];// add value from top
                if (j > 0) diff[i][j] += diff[i][j - 1];  // add value from left
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];// subtract the overcounted top-left
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j]+=diff[i][j];
            }
        }
        return mat;
    }
};


// ⏱ Time Complexity
// O(m * n) — you traverse the entire matrix once to compute the prefix sum.
// O(m * n) — again for adding to mat[i][j].

// So overall:
// ✅ Time: O(m * n + k)
// (where k = number of operations)
// ✅ Space: O(m * n) — for the diff matrix



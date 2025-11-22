class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(auto &que:opr){
            int val=que[0];
            int r1=que[1];
            int c1=que[2];
            int r2=que[3];
            int c2=que[4];
            for(int r=r1;r<=r2;r++){
                diff[r][c1]+=val;
                if(c2+1<n)diff[r][c2+1]-=val;
            }
        }
        // Prefix sum over rows 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diff[i][j]+=diff[i][j-1];
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
                if (i > 0) diff[i][j] += diff[i - 1][j];
                if (j > 0) diff[i][j] += diff[i][j - 1];
                if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
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


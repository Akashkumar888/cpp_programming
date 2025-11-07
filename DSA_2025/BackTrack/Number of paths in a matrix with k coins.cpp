
class Solution {
  public:
  int dx[2]={1,0};
  int dy[2]={0,1};
  int solve(int i,int j,int n,int m,int &sum,int k,vector<vector<int>>&mat){
      if(i<0 || j<0 || i>=n || j>=m ||mat[i][j]==-1)return 0;
      if(i==n-1 && j==m-1){
          if(sum==k)return 1;
          return 0;
      }
      int ways=0;
      int temp=mat[i][j];
      mat[i][j]=-1;
      for(int l=0;l<2;l++){
          int new_i=i+dx[l];
          int new_j=j+dy[l];
          // these below case beacause here i access matrix element 
          // But you NEVER check:
          // whether (new_i, new_j) is inside bounds
          // whether mat[new_i][new_j] is 0 (visited)
          // So you may do mat[-1][0] → runtime error / wrong answer.
          // ✅ Fix
          // Add checks before using mat[new_i][new_j]:
          if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m) continue;
          if(mat[new_i][new_j] == -1) continue;
          sum+=mat[new_i][new_j];
          ways+=solve(new_i,new_j,n,m,sum,k,mat);
          sum-=mat[new_i][new_j];
      }
      mat[i][j]=temp;
      return ways;
  }
    int numberOfPath(vector<vector<int>>& mat, int k) {
        // Code Here
        int n=mat.size();
        int m=mat[0].size();
        int sum = mat[0][0];   // FIXED
        // You NEVER add the starting cell value (0,0) to sum
        return solve(0,0,n,m,sum,k,mat);
    }
};
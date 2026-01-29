
class Solution {
  public:
  bool solve(int n,vector<vector<int>>&mat,int tr){
      int l=0,r=n*n-1;
      while(l<=r){
          int mid=l+(r-l)/2;
          int row=mid/n;
          int col=mid%n;
          if(mat[row][col]==tr)return true;
          else if(mat[row][col]<tr)l=mid+1;
          else r=mid-1;
      }
      return false;
  }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(solve(n,mat2,x-mat1[i][j]))count++;
            }
        }
        return count;
    }
};




class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int n=mat1.size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tr=x-mat1[i][j];
                int row=0,col=n-1;
                while(row<n && col>=0){
                    if(mat2[row][col]==tr){
                        count++;
                        break;
                    }
                    else if(mat2[row][col]<tr)row++;
                    else col--;
                }
            }
        }
        return count;
    }
};


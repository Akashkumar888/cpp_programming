
class Solution {
  public:
  int partition(int l,int r,int n,vector<vector<int>>&mat){
      while(l<r){
          int mid=l+(r-l)/2;
          int row=mid/n;
          int col=mid%n;
          if(mat[row][col]>mat[r/n][r%n]){
              l=mid+1;
          }
          else r=mid;
      }
      return r;
  }
  bool binarySearch(int l,int r,int n,vector<vector<int>>&mat,int x){
      while(l<=r){
          int mid=l+(r-l)/2;
          int row=mid/n;
          int col=mid%n;
          if(mat[row][col]==x)return true;
          else if(mat[row][col]<x)l=mid+1;
          else if(mat[row][col]>x)r=mid-1;
      }
      return false;
  }
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int l=0,r=m*n-1;
        int pivotIdx=partition(l,r,n,mat);
        if(binarySearch(0,pivotIdx-1,n,mat,x))return true;
        return binarySearch(pivotIdx,r,n,mat,x);
    }
};



// Time Complexity:
// O(log(m*n))
// (because we do a couple of binary searches on a flattened size m*n array)

// Space Complexity:
// O(1)
// (no extra memory, just variables)


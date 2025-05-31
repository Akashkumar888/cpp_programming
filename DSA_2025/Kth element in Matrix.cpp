
class Solution {
  public:
  bool isPossible(vector<vector<int>>&mat,int n,int k,int mid){
      int count=0;
      int row=n-1,col=0;
      while(row>=0 && col<n){
          if(mat[row][col]<=mid){
              count+=row+1;
              col++;
          }
          else row--;
      }
      return count>=k;
  }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n=matrix.size();
        int l=matrix[0][0],r=matrix[n-1][n-1];
        int ans=matrix[n-1][n-1];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(matrix,n,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};

 
class Solution {
  public:
//   matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix
bool isPossible(vector<vector<int>>&mat,int n,int k,int mid){
  int count=0;
  // Version 1: Bottom-left traversal ✅
      int row=n-1;
      int col=0;
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
        int l=matrix[0][0];
        int r=matrix[n-1][n-1];
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




class Solution {
  public:
//   matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix
  bool isPossible(vector<vector<int>>&mat,int n,int k,int mid){
      int count = 0;
      // Version 2: Top-right traversal ✅ (Most common)
      int row = 0;
      int col = n - 1;
    // traverse from the top-right corner
    while (row < n && col >= 0) {
        if (mat[row][col] <= mid) {
            // if current element is less than 
            // or equal to mid, all elements in this
            // row up to the current column are <= mid
            count += (col + 1);
            row++;
        } 
        else{
            // move left in the mat
            col--;
        }
    }
    return count>=k;
  }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        int n=matrix.size();
        int l=matrix[0][0];// min element of matrix
        int r=matrix[n-1][n-1];// max element of matrix
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





// function to count the number of elements 
// less than or equal to x
int countSmallerEqual(vector<vector<int>>& mat, int x) {
    int n = mat.size();
    int count = 0;
    int row = 0;
    int col = n - 1;

    // traverse from the top-right corner
    while (row < n && col >= 0) {
        if (mat[row][col] <= x) {
            
            // if current element is less than 
            // or equal to x, all elements in this
            // row up to the current column are <= x
            count += (col + 1);
            row++;
        } 
        else{
            // move left in the mat
            col--;
        }
    }

    return count;
}

// function to find the kth smallest 
// element in a sorted 2D mat
int kthSmallest(vector<vector<int>>& mat, int k) {
    int n = mat.size();
    int low = mat[0][0];
    int high = mat[n - 1][n - 1];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // count elements less than or equal to mid
        int count = countSmallerEqual(mat, mid);

        if (count < k) {
            
            // if there are less than k elements
            // <= mid, the kth smallest is larger
            low = mid + 1;
        } else {
            
            // otherwise, mid might be the answer, 
            // but we need to check for smaller values
            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}


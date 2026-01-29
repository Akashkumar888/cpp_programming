
class Solution {
  public:
  int kadane(vector<int>&nums){
      int sum=0;
      int maxSum=INT_MIN;
      for(int &num:nums){
          sum+=num;
          maxSum=max(maxSum,sum);
          if(sum<0)sum=0;
      }
      return maxSum;
  }
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int maxSumSubmatrix=INT_MIN;
        // column compression: into 1d array
        for(int start=0;start<n;start++){ // column
            vector<int>temp(m,0);
            for(int end=start;end<n;end++){// column
                for(int row=0;row<m;row++)temp[row]+=mat[row][end];
            maxSumSubmatrix=max(maxSumSubmatrix,kadane(temp));
            }
        }
        return maxSumSubmatrix;
    }
};

// ✅ Final Answer:
// Time Complexity: O(n^2 * m)

// Space Complexity: O(m)
// If the matrix is m x n (m rows, n columns), and you compress columns → the time complexity is O(n^2 * m).
// If you instead compress rows (fixing rows instead of columns), the time becomes O(m^2 * n).


class Solution {
  public:
  int kadane(vector<int>&nums){
      int sum=0;
      int maxSum=INT_MIN;
      for(int &num:nums){
          sum+=num;
          maxSum=max(maxSum,sum);
          if(sum<0)sum=0;
      }
      return maxSum;
  }
    int maxRectSum(vector<vector<int>> &mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        int maxSumSubmatrix=INT_MIN;
        // row compression: into 1d array
        for(int start=0;start<m;start++){ // row
            vector<int>temp(n,0);
            for(int end=start;end<m;end++){// row
                for(int col=0;col<n;col++)temp[col]+=mat[end][col];
            maxSumSubmatrix=max(maxSumSubmatrix,kadane(temp));
            }
        }
        return maxSumSubmatrix;
    }
};

// ✅ Final Answer
// Time Complexity: O(m^2 * n)

// Space Complexity: O(n)
// Let me know if you want the column compression version (i.e., O(n^2 * m)).

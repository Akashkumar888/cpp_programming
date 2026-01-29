
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

class Solution {
public:
    int kadane(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for (int x : nums) {
            sum += x;
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }

    int maxRectSum(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxSumSubmatrix = INT_MIN;

        // COLUMN COMPRESSION
        for (int left = 0; left < n; left++) {
            vector<int> temp(m, 0);

            for (int right = left; right < n; right++) {
                // compress rows for columns left..right
                for (int row = 0; row < m; row++)
                    temp[row] += mat[row][right];

                // apply kadane on compressed 1D array
                maxSumSubmatrix = max(maxSumSubmatrix, kadane(temp));
            }
        }
        return maxSumSubmatrix;
    }
};

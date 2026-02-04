
// User function Template for C++

class Solution {
  public:
  // Inverse Kadane’s: minimum subarray sum (non-circular case)
  int minNegativeSum(vector<int>&arr){
      int minSum=INT_MAX;
      int sum=0;
      for(int &num:arr){
          sum+=num;
          minSum=min(minSum,sum);
          if(sum>0)sum=0;
      }
      return minSum;
  }
    int smallestSumSubarray(vector<int>& arr) {
        // Code here
        int minSum=minNegativeSum(arr);
        return minSum;
    }
};

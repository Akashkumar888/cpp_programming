
// Maximum Sum Circular Subarray
class Solution {
public:
    // Standard Kadane’s: maximum subarray sum (non-circular case)
    int kadaneMax(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for (int &num : nums) {
            sum += num;
            maxsum = max(sum, maxsum);
            if (sum < 0) sum = 0;
        }
        return maxsum;
    }

    // Inverse Kadane’s: minimum subarray sum (non-circular case)
    int kadaneMin(vector<int>& nums) {
        int sum = 0;
        int minsum = INT_MAX;
        for (int &num : nums) {
            sum += num;
            minsum = min(minsum, sum);
            if (sum > 0) sum = 0;
        }
        return minsum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNormal = kadaneMax(nums);   // best non-circular subarray
        int minNormal = kadaneMin(nums);   // worst non-circular subarray
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge case: all numbers are negative → just return maxNormal
        if (totalSum == minNormal) return maxNormal;

        // Either take normal Kadane or wrap-around case
        return max(maxNormal, totalSum - minNormal);
    }
};

class Solution {
  public:
  // Standard Kadane’s: maximum subarray sum (non-circular case)
  int maxPositiveSum(vector<int>&arr){
      int maxSum=INT_MIN;
      int sum=0;
      for(int &num:arr){
          sum+=num;
          maxSum=max(maxSum,sum);
          if(sum<0)sum=0;
      }
      return maxSum;
  }
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
    int maxCircularSum(vector<int> &arr) {
        // code here
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int maxSum=maxPositiveSum(arr);
        int minSum=minNegativeSum(arr);
        // Edge case: all numbers are negative → just return maxNormal
        if (totalSum == minSum) return maxSum;
        // Either take normal Kadane or wrap-around case
        return max(maxSum,totalSum-minSum);
    }
};



// Maximum Sum Circular Subarray
class Solution {
public:
int maxpositiveSum(vector<int>&nums){
        int sum=0;
        int maxsum=INT_MIN;
        for(int &num:nums){
            sum+=num;
            maxsum=max(sum,maxsum);
            if(sum<0)sum=0;
        }
        return maxsum;
}
int maxnegativeSum(vector<int>&nums){ 
        int sum=0;
        int minsum=INT_MAX;
        for(int &num:nums){
            sum+=num;
            minsum=min(minsum,sum);
            if(sum>0)sum=0;
        }
        return minsum;
}
    int maxSubarraySumCircular(vector<int>& nums) {
        int pos=maxpositiveSum(nums);
        int neg=maxnegativeSum(nums);//This is the inverse Kadane’s algorithm → it returns the minimum subarray sum (non-circular case).
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        // If all elements are negative, return the maximum element
        if (totalSum == neg)return pos;
        return max(pos,totalSum-neg);
    }
};


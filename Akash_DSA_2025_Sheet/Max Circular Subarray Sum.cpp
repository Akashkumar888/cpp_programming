class Solution {
  public:
  int maxPositiveSum(vector<int>&arr){
      int maxSum=INT_MIN;
        int sum=0;
        for(int &num:arr){
            sum+=num;
            maxSum=max(maxSum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxSum;
  }
  int maxNegativeSum(vector<int>&arr){
      int minSum=INT_MAX;
        int sum=0;
        for(int &num:arr){
            sum+=num;
            minSum=min(minSum,sum);
            if(sum>0){
                sum=0;
            }
        }
        return minSum;
  }
    int maxCircularSum(vector<int> &arr) {
        // code here
        // kadane algorithm use here 
        int totalSum=accumulate(arr.begin(),arr.end(),0);
        int maxSum=maxPositiveSum(arr);
        int minSum=maxNegativeSum(arr);
        // If all elements are negative, return the maximum element
        // But if all elements are negative, totalSum == minSum, so totalSum - minSum == 0.
       // In this case, return the maximum element (which is maxSum from Kadane).
        if(totalSum==minSum)return maxSum;

        // If all elements are negative, return max element (Kadane's result)
        // if(maxSum < 0) return maxSum;

        return max(maxSum,totalSum - minSum ); 
    }
};

// Subtract the minimum subarray sum from the total:
// totalSum - minSum
// This gives the maximum sum of the subarray that includes wrap-around elements.

// ❗ Corner Case: All Elements Are Negative
// If all elements are negative:
// maxSum is the largest (least negative) number.
// minSum will equal totalSum.

// So you return maxSum, not totalSum - minSum (which would be 0).
// if (totalSum == minSum) return maxSum;
// ✅ Final Return:
// return max(maxSum, totalSum - minSum);
// This picks the better of the two cases:
// Non-wrapped maximum (maxSum)
// Wrapped maximum (totalSum - minSum)


// ✅ Time Complexity:
// int totalSum = accumulate(arr.begin(), arr.end(), 0); // O(n)
// int maxSum = maxPositiveSum(arr);                     // O(n)
// int minSum = maxNegativeSum(arr);                     // O(n)
// Each helper function (maxPositiveSum and maxNegativeSum) loops through the array once.
// 🔹 Total time: O(n)

// ✅ Space Complexity:
// No extra space is used besides a few integer variables (sum, maxSum, minSum, totalSum).
// You're not using any additional data structures.
// 🔹 Total space: O(1)


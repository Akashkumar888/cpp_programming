
// A subarray is a contiguous part of the array. So for an array of size n, total number of subarrays is:n*(n+1)/2;

// Given an array arr[], find the sum of all the subarrays of the given array.
// Note: It is guaranteed that the total sum will fit within a 32-bit integer range.

class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int left=(i+1);
            int right=(n-1-i+1);
            sum+=(left*right)*arr[i];
        }
        return sum;
    }
};

// ✅ Code Logic Summary:
// For each element arr[i], it contributes to multiple subarrays. Specifically, it appears in:
// left = i + 1 choices for starting index
// right = n - i choices for ending index
// So, total subarrays including arr[i] = left * right, and its contribution = arr[i] * left * right.
// Hence, sum += arr[i] * (i + 1) * (n - i).

// ⏰ Time Complexity:
// O(n)
// A single loop runs from 0 to n - 1, and all operations inside the loop are constant time.

// 💾 Space Complexity:
// O(1)
// Only a few variables (n, sum, left, right) are used — no additional data structures proportional to input size.


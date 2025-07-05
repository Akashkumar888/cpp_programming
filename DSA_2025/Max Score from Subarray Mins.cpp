
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int maxSum=0;
        // two large values that are close together
        //  find the smallest and second smallest elements
        //  any subarray of arr[] with length at least 2.
        for(int i=0;i<n-1;i++){
            maxSum=max(maxSum,arr[i]+arr[i+1]);
        }
        return maxSum;
    }
};

// 🕒 Time Complexity: O(n)
// You loop once from i = 0 to i = n-2 ⇒ n - 1 iterations.
// Each iteration does constant time operations (+, max).
// ✅ Total time = O(n)

// 🧠 Space Complexity: O(1)
// You're using only a few variables: n, maxSum, i.
// No additional data structures or memory is allocated.
// ✅ Total space = O(1) (constant)


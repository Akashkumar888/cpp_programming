
class Solution {
  public:
//   You have to count the number of subarrays that contain exactly k odd numbers.
// Exactly K = AtMost(K) − AtMost(K−1)
// This is the BEST sliding-window approach.
// Your Current Method (Sliding Window – BEST)
// Idea
// Count subarrays with at most K odd
// Subtract subarrays with at most (K−1) odd
// Complexity
// Time: O(n)
// Space: O(1)
// ✅ Optimal
// ✅ Works for large constraints
// This is the most preferred solution.

  int solve(vector<int>&arr,int k){
      int n=arr.size();
        int countOdd=0;
        int i=0,j=0;
        int count=0;
        while(j<n){
            if(arr[j]%2)countOdd++;
            while(countOdd>k){
                if(arr[i]%2)countOdd--;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
  }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return solve(arr,k) - solve(arr,k-1);
    }
};
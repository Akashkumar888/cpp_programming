
class Solution {
  public:
//   ✅ Key Concept (Most Important)
// A number arr[i] appears in total XOR only if it appears odd number of times in all subarray XORs.
// Number of subarrays containing arr[i] = (i+1)×(n−i)
// If this value is odd, include arr[i] in the final XOR.
// If even, it cancels out.
    int subarrayXor(vector<int>& arr) {
        // code here
        int n=arr.size();
        int totalXor=0;
        for(int i=0;i<n;i++){
            int left=(i+1);
            int right=(n-i);
            if((left*right)%2)totalXor^=arr[i];
            // If this value is odd, include arr[i] in the final XOR.
        }
        return totalXor;
    }
};

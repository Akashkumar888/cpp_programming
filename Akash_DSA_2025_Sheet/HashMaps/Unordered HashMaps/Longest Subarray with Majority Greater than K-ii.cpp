
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=-1; // when index store for subarray length 
        int preSum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(arr[i]>k)preSum+=1;
            else preSum-=1;
            if(preSum>0)maxlen=i+1;
            else{
            if(mp.find(preSum-1)!=mp.end())maxlen=max(maxlen,i-mp[preSum-1]);
            if(mp.find(preSum)==mp.end())mp[preSum]=i;
            }
        }
        return maxlen;
    }
};


// ⏱ Time Complexity: O(n)
// You traverse the array once (for loop) → O(n)
// All operations with unordered_map are average-case constant time (O(1)), so each prefix sum insertion and lookup is O(1) on average.

// 🔁 Total = O(n) time
// 💾 Space Complexity: O(n)
// In the worst case, the prefix sum will be unique at every index, so the unordered_map could store up to n different prefix sums.
// 📦 Total = O(n) space


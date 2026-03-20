
// its length is at least two, and
// the sum of the elements of the subarray is a multiple of k.

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=-1; // when index store for subarray length  // important for subarray starting from index 0
        int prefixSum=0;
        int maxLen=0;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int mod = (prefixSum % k); 
            // If array contains only POSITIVE numbers
            // → x % k is enough
            if(mp.find(mod)!=mp.end()){
                maxLen=max(maxLen,i-mp[mod]);
                if(maxLen>=2)return true;
            }
            if(mp.find(mod)==mp.end())mp[mod]=i;
        }
        return false;
    }
};



// 1️⃣ Normal Mod
// int mod = prefixSum % k;
// Use this when:
// All numbers are NON-NEGATIVE
// Example problems:
// Continuous Subarray Sum
// Subarray Sum Equals K (if array positive)
// prefix sum problems with only positive values
// Example:
// prefixSum = 17
// k = 5
// 17 % 5 = 2
// Everything works fine.

// 2️⃣ Safe Mod (handles negatives)
// int mod = ((prefixSum % k) + k) % k;
// Use this when:
// array may contain negative numbers
// Example problem:
// Subarray Sums Divisible by K
// Example:
// prefixSum = -3
// k = 5
// Normal mod:
// -3 % 5 = -3   ❌
// But we want 0 → k-1 range
// Safe mod:
// ((-3 % 5) + 5) % 5
// (-3 + 5) % 5
// 2 % 5 = 2   ✅
// Now it works correctly.

// 3️⃣ Why This Matters
// Hashmap keys must match.
// Example:
// prefix mod values
// -3
// 2
// They represent the same remainder class, but hashmap sees them different.
// So subarray detection fails.
// Safe mod fixes this.

// 4️⃣ Rule for Interviews
// Remember this simple rule:
// If array may contain NEGATIVE numbers
// → use ((x % k) + k) % k
// If array contains only POSITIVE numbers
// → x % k is enough
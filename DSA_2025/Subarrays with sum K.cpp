
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int count=0;
        for(int &num:arr){
            sum+=num;
            // If sum - k has occurred before (i.e., there is a subarray with sum = sum - (sum - k) = k), then we can count it.
                //Current prefix sum up to index i is sum
                // You want to check if there's a previous prefix sum rem such that:
                // sum - rem = k   ⟹  rem = sum - k

            int rem=sum-k;
            if(mp.find(rem)!=mp.end())count+=mp[rem];
            mp[sum]++;
        }
        return count;
    }
};

// k - sum means: you're checking if rem - sum == k, which is logically incorrect.
// You're trying to find a past prefix sum that makes the difference with the current prefix sum equal to k, not the other way around.



// ✅ So, Total Time Complexity = O(n)
// This loop runs once over the array → O(n).

// ✅ Space Complexity
// We use an unordered_map<int, int> mp to store prefix sums.
// ✅ Total Space Complexity = O(n)




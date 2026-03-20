
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
            if(mp.find(mod)!=mp.end()){
                maxLen=max(maxLen,i-mp[mod]);
                if(maxLen>=2)return true;
            }
            if(mp.find(mod)==mp.end())mp[mod]=i;
        }
        return false;
    }
};
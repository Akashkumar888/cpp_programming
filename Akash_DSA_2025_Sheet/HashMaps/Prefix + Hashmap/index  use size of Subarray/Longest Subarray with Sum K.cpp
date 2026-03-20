
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mp;
        mp[0]=-1; // when index store for subarray length 
        int preSum=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            preSum+=arr[i];
            if(mp.find(preSum-k)!=mp.end())maxlen=max(maxlen,i-mp[preSum-k]);
            if(mp.find(preSum)==mp.end())mp[preSum]=i;
        }
        return maxlen;
    }
};

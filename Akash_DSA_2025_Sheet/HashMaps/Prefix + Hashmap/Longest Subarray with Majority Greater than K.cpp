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
            if(arr[i]>k)preSum+=1;//count of elements greater than k
            else preSum-=1;//count of elements less than or equal to k.
            
            if(preSum>0)maxlen=i+1;
            else{
            if(mp.find(preSum-1)!=mp.end())maxlen=max(maxlen,i-mp[preSum-1]);
            if(mp.find(preSum)==mp.end())mp[preSum]=i;
            }
        }
        return maxlen;
    }
};

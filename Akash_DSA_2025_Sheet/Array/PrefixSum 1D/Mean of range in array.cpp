class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<int>preSum(n);
        preSum[0]=arr[0];
        for(int i=1;i<n;i++)preSum[i]=preSum[i-1]+arr[i];
        vector<int>result;
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            int width=r-l+1;
            int value=(preSum[r]- (l>=1 ? preSum[l-1]:0));
            result.push_back(floor(value/width));
        }
        return result;
    }
};

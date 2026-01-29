
class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n=arr.size();
        int maxSum=INT_MIN; // subsequence ordering matters 
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=arr[i];
            maxSum=max(dp[i],maxSum);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && dp[i]<dp[j]+arr[i]){ // jaha pr uska kitna hai like 1, dp[i] 
                    dp[i]=dp[j]+arr[i];
                }
            }
            if(maxSum<dp[i]){
                maxSum=dp[i];
            }
        }
        return maxSum;
    }
};

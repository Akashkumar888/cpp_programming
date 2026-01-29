
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);   // FIXED: count must start at 1
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // found a longer LIS ending at i
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];   // FIXED
                    }
                    // found another way to make same LIS length
                    else if(dp[i] == dp[j] + 1){
                        count[i] += count[j];  // FIXED
                    }
            }
        }
        if(maxi<dp[i]){
            maxi =dp[i];
         }         
    }
    int maxCount=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi)maxCount += count[i];
    }
    return maxCount;
    }
};
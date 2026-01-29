class Solution {
public:
    int lengthOfLDS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) {
                    if(dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                 }
            }
        }
        if(maxi<dp[i]){
            maxi =dp[i];
         }         
        }
    return maxi;
    }
};
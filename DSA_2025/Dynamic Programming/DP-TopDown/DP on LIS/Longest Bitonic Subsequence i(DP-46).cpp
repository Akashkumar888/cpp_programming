
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
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

// mixture of both code for mountain or biotonic point
// biotonic left to right increasing LIS
// right to left decreasing LDS 
class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp1(n, 1);// for lis
        vector<int> dp2(n, 1);// for lds
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if(dp1[i] < dp1[j] + 1){
                    dp1[i] = dp1[j] + 1;
                 }
            }
        }
        }
        for (int i = n-2; i >=0 ; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    if(dp2[i] < dp2[j] + 1){
                    dp2[i] = dp2[j] + 1;
                 }
            }
        }
        }
    int maxLength=0;
    for(int i=0;i<n;i++){
        // boitonic itself that why -1
        // ✅ BOTH increasing & decreasing required
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxLength = max(maxLength, dp1[i] + dp2[i] - 1);
            }
    }
    return maxLength;
    }
};

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
    // custom lower_bound: first index where arr[idx] >= target
    int lowerBound(vector<int>& arr, int target) {
        int l = 0, r = arr.size() - 1;
        int idx = arr.size();

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) {
                idx = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }
        return idx;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> temp;
        temp.push_back(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                // extend LIS
                temp.push_back(nums[i]);
            } 
            else {
                // replace using custom lower_bound
                int idx = lowerBound(temp, nums[i]);
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};

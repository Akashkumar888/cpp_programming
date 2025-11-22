
// max_postive sum 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum=0;
        int maxsum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0)sum=0;
        }
        return maxsum;
    }
};



// 1. Maximum Subarray Sum (classic Kadane)
// Maximum Subarray Sum (Kadane's Algorithm)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;  // reset when sum becomes negative
        }
        return maxSum;
    }
};


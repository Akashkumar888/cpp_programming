
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

class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        
        int mid =left + (right - left) / 2; //Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
        
        int leftMax = helper(nums, left, mid);
        int rightMax = helper(nums, mid + 1, right);
        
        // Max crossing sum
        int sum = 0, leftSum = INT_MIN;
        for (int i = mid; i >= left; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        sum = 0;
        int rightSum = INT_MIN;
        for (int i = mid + 1; i <= right; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        
        return max({leftMax, rightMax, leftSum + rightSum});
    }
    
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        return helper(nums, 0,  n- 1);
    }
};

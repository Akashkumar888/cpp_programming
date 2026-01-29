
// min_negative_sum 
class Solution {
public:
    int minSubArray(vector<int>& nums) {
       int sum=0;
        int minsum=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minsum=min(sum,minsum);
            if(sum>0)sum=0;
        }
        return minsum;
    }
};



// 2. Minimum Subarray Sum (Kadane’s inverted)
// Minimum Subarray Sum
class Solution {
public:
    int minSubArray(vector<int>& nums) {
        int sum = 0;
        int minSum = INT_MAX;
        for (int num : nums) {
            sum += num;
            minSum = min(minSum, sum);
            if (sum > 0) sum = 0;  // reset when sum becomes positive
        }
        return minSum;
    }
};


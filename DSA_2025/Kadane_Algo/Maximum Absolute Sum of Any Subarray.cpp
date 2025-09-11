// Maximum Absolute Sum of Any Subarray
class Solution {
public:
    // Kadane’s maximum subarray sum
    int kadaneMax(vector<int>& nums) {
        int sum = 0;
        int maxsum = INT_MIN;
        for (int num : nums) {
            sum += num;
            maxsum = max(maxsum, sum);
            if (sum < 0) sum = 0;
        }
        return maxsum;
    }

    // Kadane’s minimum subarray sum
    int kadaneMin(vector<int>& nums) {
        int sum = 0;
        int minsum = INT_MAX;
        for (int num : nums) {
            sum += num;
            minsum = min(minsum, sum);
            if (sum > 0) sum = 0;
        }
        return minsum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int maxSub = kadaneMax(nums);          // maximum subarray sum
        int minSub = kadaneMin(nums);          // minimum subarray sum
        return max(maxSub, abs(minSub));       // absolute maximum
    }
};



// Maximum Absolute Sum of Any Subarray
class Solution {
public:
int maxpositiveSum(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0)sum=0;
        }
        return maxsum;
}
int maxnegativeSum(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        int minsum=INT_MAX;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minsum=min(minsum,sum);
            if(sum>0)sum=0;
        }
        return minsum;
}
    int maxAbsoluteSum(vector<int>& nums) {
        int pos=maxpositiveSum(nums);
        int neg=maxnegativeSum(nums);
        return max(pos,abs(neg));
    }
};



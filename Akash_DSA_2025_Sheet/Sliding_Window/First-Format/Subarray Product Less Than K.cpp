
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)return 0;
        int i=0,j=0;
        int count=0;
        int prod=1;
        while(j<n){
         prod=prod*nums[j];
         while(i<=j && prod>=k){
            prod=prod/nums[i];
            i++;
         }
         count+=(j-i+1);// count unique subarray
         j++;
        }
        return count;
    }
};
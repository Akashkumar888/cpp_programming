
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=k-1;
        int minDiff=INT_MAX;
        while(j<n){
         int mini=nums[i];
         int maxi=nums[j];
         minDiff=min(minDiff,maxi-mini);
         i++;
         j++;
        }
        return minDiff;
    }
};

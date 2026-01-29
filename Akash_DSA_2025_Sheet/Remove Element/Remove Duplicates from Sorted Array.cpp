
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // nums is sorted in non-decreasing order.
        int n=nums.size();
        if(n<=1)return 1;
        int k=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[k-1]){
            nums[k]=nums[i];
            k++;
            }
        }
        return k;
    }
};



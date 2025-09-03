
class Solution {
public:
    void cyclicSort(vector<int>& nums, int n) {
        int i = 0;
        while (i < n) { // containing elements from the range 1 to n
            int val = nums[i];
            if (val >= 1 && val <= n && nums[i] != nums[val - 1]) {
                swap(nums[i], nums[val - 1]);
            } else
                i++;
        }
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // where nums[i] is in the range [1, n], return an array of all the
        // integers in the range [1, n]
        int n=nums.size(); 
        cyclicSort(nums,n); 
        vector<int>ans; 
        for(int i=0;i<n;i++){ 
            if(nums[i]!=i+1)ans.push_back(i+1); 
            } 
        return ans;
    }
};


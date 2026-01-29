
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
    vector<int> findErrorNums(vector<int>& nums) {
        // numbers from 1 to n
        // results in repetition of one number and loss of another number.
        // number that occurs twice and the number that is missing and return them in the form of an array
        int n=nums.size(); 
        cyclicSort(nums,n); 
        vector<int>ans; 
        for(int i=0;i<n;i++){ 
            if(nums[i]!=i+1){
            ans.push_back(nums[i]); 
            ans.push_back(i+1);
            }
            } 
        return ans;
    }
};
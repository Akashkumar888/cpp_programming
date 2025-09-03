
class Solution {
public:
void cyclicSort(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int val = nums[i];
            // valid numbers in range [0, n-1] for swapping
            if (val >= 0 && val < n && nums[i] != nums[val]) {
                swap(nums[i], nums[val]);
            } else {
                i++;
            }
        }
    }
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        // distinct numbers in the range [0, n]
        cyclicSort(nums);
        for(int i=0;i<n;i++){
            if(nums[i]!=i)return i;
        }
        return n;// if all numbers 0 to n-1 are present, missing number is n
    }
};


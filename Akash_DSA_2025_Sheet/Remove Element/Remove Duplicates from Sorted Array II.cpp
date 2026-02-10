
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int k = 2;
        int j = 2;

        while (j < n) {
            if (nums[j] != nums[k - 2]) {
                nums[k] = nums[j];
                k++;
            }
            j++;
        }

        return k;
    }
};



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //  each unique element appears at most twice. The relative order of the elements should be kept the same.
        int n = nums.size();
        if(n <= 2) return n; // already valid
        int k = 2; // first two always allowed
        for(int i = 2; i < n; i++) {
            if(nums[i] != nums[k-2]) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};



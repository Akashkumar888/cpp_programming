
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int i = 0;   // slow pointer
        int j = 1;   // fast pointer

        while (j < n) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }

        return i + 1; // number of unique elements
    }
};



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



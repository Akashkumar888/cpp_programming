class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;  // fast pointer
        int j = 0;  // position to place valid element

        while (i < n) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int k=0;  // position for placing next valid element
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];  // overwrite unwanted elements
                k++;
            }
        }
        return k;
    }
};





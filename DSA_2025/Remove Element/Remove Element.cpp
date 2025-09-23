
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




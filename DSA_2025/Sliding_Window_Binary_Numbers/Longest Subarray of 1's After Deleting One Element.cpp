
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // you should delete one element 0 or 1 from it.
        // This problem asks you to delete exactly one element (not “flip at most one zero”).
        int k=1;
        int n=nums.size();
        int maxLen=0;
        int i=0,j=0;
        int countZero=0;
        while(j<n){
            if(nums[j]==0)countZero++;
            while(countZero>k){// k se ek zyada count 
                if(nums[i]==0)countZero--;
                i++;
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen - 1; // delete exactly one element
    }
};



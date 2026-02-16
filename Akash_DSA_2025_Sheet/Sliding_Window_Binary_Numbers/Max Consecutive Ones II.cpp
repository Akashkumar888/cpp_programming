

// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        // you can flip at most one 0
        int n=nums.size();
        int i=0,j=0;
        int maxLen=0;
        int zero=0;
        while(j<n){
          if(nums[j]==0)zero++;
          while(zero>1){
              if(nums[i]==0)zero--;
              i++;
          }
          maxLen=max(maxLen,j-i+1);
          j++;
        }
        return maxLen;
    }
};
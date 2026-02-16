
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // you can flip at most k 0
        int n=nums.size();
        int i=0,j=0;
        int maxLen=0;
        int zero=0;
        while(j<n){
          if(nums[j]==0)zero++;
          while(zero>k){
              if(nums[i]==0)zero--;
              i++;
          }
          maxLen=max(maxLen,j-i+1);
          j++;
        }
        return maxLen;
    }
};
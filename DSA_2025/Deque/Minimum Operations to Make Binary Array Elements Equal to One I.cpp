
class Solution {
public:
    int minOperations(vector<int>& nums) {
      int n=nums.size();
      int k=3;
      int cnt=0;
        for(int i=0;i<n-2;i++){
           if(nums[i]==1)continue;
           for(int j=i;j<i+k;j++){
            nums[j]=nums[j] ^ 1; // 1-> 0 or 0->1
           }
           cnt++;
        }
        if(nums[n-2]==0 || nums[n-1]==0)return -1;
        return cnt;
    }
};


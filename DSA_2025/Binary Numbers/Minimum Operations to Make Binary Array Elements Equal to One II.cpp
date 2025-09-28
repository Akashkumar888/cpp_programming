
class Solution {
public:
    int minOperations(vector<int>& nums) {
       int n=nums.size();
       // 0 ko 1 banana target hai start to end tk 
       int times=0;
       for(int i=0;i<n;i++){
        if((nums[i]==1 && times%2==1) || (nums[i]==0 && times%2==0))times++;
       }
       return times;
    }
};

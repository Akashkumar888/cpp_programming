
class Solution {
  public:
    int minDifference(vector<int>& nums) {
        // Your code goes here
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int sum=totalSum/2;
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        // base case 
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=sum)dp[0][nums[0]]=true;//if(i==0)return (nums[0]==target);
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=dp[i-1][target];
                bool pick=false;
                if(nums[i]<=target)pick=dp[i-1][target-nums[i]];
                dp[i][target]=pick | notpick;
            }
        }
        int minSum=INT_MAX;
        for(int target=0;target<=sum;target++){
        if(dp[n-1][target]==true){
            int s1=target;
            int s2=totalSum-target;
            minSum=min(minSum,abs(s1-s2));
            }
        }
        return minSum;
    }
};

class Solution {
  public:
    int minDifference(vector<int>& nums) {
        // Your code goes here
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int sum=totalSum/2;
        vector<bool>prev(sum+1,0),temp(sum+1,0);
        // base case 
        prev[0]=true;
        temp[0]=true;
        
        if(nums[0]<=sum)prev[nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool notpick=prev[target];
                bool pick=false;
                if(nums[i]<=target)pick=prev[target-nums[i]];
                temp[target]=pick | notpick;
            }
            prev=temp;
        }
        int minSum=INT_MAX;
        for(int target=0;target<=sum;target++){
        if(prev[target]==true){
            int s1=target;
            int s2=totalSum-target;
            minSum=min(minSum,abs(s1-s2));
            }
        }
        return minSum;
    }
};

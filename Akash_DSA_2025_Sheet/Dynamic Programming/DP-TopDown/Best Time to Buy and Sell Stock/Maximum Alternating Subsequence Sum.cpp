
class Solution {
public:
long long solve(int i,int n,bool even,vector<int>&nums,vector<vector<long long>>&dp){
      if(i>=n)return 0;
      if(dp[i][even]!=-1)return dp[i][even];
      long long pick=0;
      long long notpick=0;
      if(even){ // sell conditions 
          pick=solve(i+1,n,false,nums,dp)+nums[i]; //maximum alternating sum
          notpick=solve(i+1,n,true,nums,dp);
      }
      else{ // buy conditions 
          pick=solve(i+1,n,true,nums,dp)-nums[i]; //maximum alternating sum
          notpick=solve(i+1,n,false,nums,dp);
      }
      return dp[i][even]=max(pick,notpick);
}
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        bool even=true;
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solve(0,n,even,nums,dp);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        // dp size = n+1 to safely use dp[i+1]
        // return solve(0,n,even,nums,dp);
        for(int i=n-1;i>=0;i--){
            for(int even=0;even<2;even++){
                long long pick=0;
                long long notpick=0;
                if(even){ // sell conditions 
                    pick=dp[i+1][0]+nums[i]; //maximum alternating sum
                    notpick=dp[i+1][1];
                }
                else{ // buy conditions 
                    pick=dp[i+1][1]-nums[i]; //maximum alternating sum
                    notpick=dp[i+1][0];
                }
                dp[i][even]=max(pick,notpick);
            }
        }
        return dp[0][1];
    }
};
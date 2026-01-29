
class Solution {
public:
  int solve(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
      if(i>j)return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int maxCoins=INT_MIN;
      for(int k=i;k<=j;k++){// you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array
         int coins=(nums[i-1]*nums[k]*nums[j+1])+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
         maxCoins=max(maxCoins,coins);
      }
    return dp[i][j]=maxCoins;  
  }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);//then treat it as if there is a balloon with a 1 painted on it.
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));// n+2 because if there is a balloon with a 1 painted on it.
        return solve(1,n,nums,dp);
    }
};


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);//then treat it as if there is a balloon with a 1 painted on it.
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));// n+2 because if there is a balloon with a 1 painted on it.
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j)continue;
                int maxCoins=INT_MIN;
                for(int k=i;k<=j;k++){// you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array
                    int coins=(nums[i-1]*nums[k]*nums[j+1])+dp[i][k-1]+dp[k+1][j];
                    maxCoins=max(maxCoins,coins);
                }
                dp[i][j]=maxCoins;  
            }
        }
        return dp[1][n];
    }
};


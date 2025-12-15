
class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
int solve(int i,vector<int>&coins,int target,vector<vector<int>>&dp){
    if(i==0){
       if((target%coins[0])==0)return (target/coins[0]);//multiple use
       else return 1e8;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notpick=0+solve(i-1,coins,target,dp);
    int pick=1e8;
    if(coins[i]<=target)pick=1+solve(i,coins,target-coins[i],dp);
    return dp[i][target]=min(pick,notpick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result=solve(n-1,coins,amount,dp);
        if(result==1e8)return -1;
        return result;
    }
};

class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e8));
        for(int target=0;target<=amount;target++){
            if((target%coins[0])==0)dp[0][target]=(target/coins[0]);//multiple use
            else dp[0][target]=1e8;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int notpick=0+dp[i-1][target];
                int pick=1e8;
                if(coins[i]<=target)pick=1+dp[i][target-coins[i]];
                dp[i][target]=min(pick,notpick);
            }
        }
        int result=dp[n-1][amount];
        if(result==1e8)return -1;
        return result;
    }
};

class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,1e8),temp(amount+1,1e8);
        for(int target=0;target<=amount;target++){
            if((target%coins[0])==0)prev[target]=(target/coins[0]);//multiple use
            else prev[target]=1e8;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int notpick=0+prev[target];
                int pick=1e8;
                if(coins[i]<=target)pick=1+temp[target-coins[i]];
                temp[target]=min(pick,notpick);
            }
            prev=temp;
        }
        int result=prev[amount];
        if(result==1e8)return -1;
        return result;
    }
};
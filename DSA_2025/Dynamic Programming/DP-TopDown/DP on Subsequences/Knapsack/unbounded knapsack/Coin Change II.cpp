

class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
// time comp greater than 2^n exponentials 
int solve(int i,vector<int>&coins,int target,vector<vector<int>>&dp){
    if(i==0){
       if((target%coins[0])==0)return 1;//multiple use
       else return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notpick=solve(i-1,coins,target,dp);
    int pick=0;
    if(coins[i]<=target)pick=solve(i,coins,target-coins[i],dp);
    return dp[i][target]=pick+notpick;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result=solve(n-1,coins,amount,dp);
        return result;
    }
};

class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
// time comp greater than 2^n exponentials 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int target=0;target<=amount;target++){
            if((target%coins[0])==0)dp[0][target]=1;//multiple use
            else dp[0][target]=0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int notpick=dp[i-1][target];
                int pick=0;
                if(coins[i]<=target)pick=dp[i][target-coins[i]];
                dp[i][target]=pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};

class Solution {
public:
// You may assume that you have an infinite number of each kind of coin.
// multiple use then same idx i,
// time comp greater than 2^n exponentials 
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int>prev(amount+1,0),temp(amount+1,0);
        for(int target=0;target<=amount;target++){
            if((target%coins[0])==0)prev[target]=1;//multiple use
            else prev[target]=0;
        }
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int notpick=prev[target];
                int pick=0;
                if(coins[i]<=target)pick=temp[target-coins[i]];
                temp[target]=pick + notpick;
            }
            prev=temp;
        }
        return prev[amount];
    }
};


class Solution {
public:
int solve(int idx,vector<int>&arr,int sum,int x,vector<vector<int>>&dp){
    if(sum==0)return 1;
    if(sum<0 || idx>=arr.size())return 0;
    if(dp[idx][sum]!=-1)return dp[idx][sum];
    int pick=0,notpick=0;
    if(pow(arr[idx],x)<=sum){
    pick=solve(idx+1,arr,sum-pow(arr[idx],x),x,dp);
    }
    notpick=solve(idx+1,arr,sum,x,dp);
    return dp[idx][sum]=pick+notpick;
}
    int numberOfWays(int n, int x) {
        vector<int>arr(n);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)arr[i]=i+1;
        return solve(0,arr,n,x,dp);
    }
};

class Solution {
public:
    int solve(int num, int sum, int x, vector<int>& dp) {
        if (sum == 0) return 1;
        if (sum < 0 || num == 0) return 0;
        if (dp[sum] != -1) return dp[sum];

        // either pick num^x (if possible) or move to smaller num
        int pick = 0;
        int power = pow(num, x);
        if (power <= sum) {
            pick = solve(num - 1, sum - power, x, dp);
        }
        int notpick = solve(num - 1, sum, x, dp);

        return dp[sum] = pick + notpick;
    }

    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1, -1);  // only depends on "sum"
        return solve(n, n, x, dp);
    }
};

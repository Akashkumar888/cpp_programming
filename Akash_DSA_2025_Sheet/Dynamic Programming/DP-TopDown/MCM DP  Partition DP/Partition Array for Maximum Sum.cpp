
class Solution {
public:
// forward partition or front partition
int solve(int i,int n,int k,vector<int>&arr,vector<int>&dp){
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int maxCost=INT_MIN;
    int maxi=INT_MIN;
    int len=0;
    for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int cost=(len*maxi)+solve(j+1,n,k,arr,dp);
            maxCost=max(maxCost,cost);
    }
    return dp[i]=maxCost;
}
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,k,arr,dp);
    }
};


class Solution {
public:
// forward partition or front partition
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxCost=INT_MIN;
            int maxi=INT_MIN;
            int len=0;
            for(int j=i;j<min(n,i+k);j++){
                    len++;
                    maxi=max(maxi,arr[j]);
                    int cost=(len*maxi)+dp[j+1];
                    maxCost=max(maxCost,cost);
            }
            dp[i]=maxCost;
        }
        return dp[0];
    }
};


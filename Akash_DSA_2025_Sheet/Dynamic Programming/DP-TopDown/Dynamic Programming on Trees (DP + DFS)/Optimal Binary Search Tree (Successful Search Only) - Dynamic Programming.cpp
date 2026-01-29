
class Solution {
public:
    /*
        Recurrence Used:
        C[i][j] = min( C[i][k-1] + C[k+1][j] ) + wt(i,j)
        for every k in [i, j]
    */
    // Function to compute sum of frequencies freq[i..j]
    // wt(i, j) = sum of frequencies from freq[i] to freq[j]
    // Mathematical Formula:
    //      wt(i, j) = Σ freq[k]   for k = i to j
    // Example: wt(1, 4) = freq[1] + freq[2] + freq[3] + freq[4]
    int wt(int i,int j,vector<int>&freq){
        int sum=0;
        for(int k=i;k<=j;k++)sum+=freq[k];
        return sum;
    }
    int solve(int i,int j,vector<int>&keys,vector<int>&freq,vector<vector<int>> &dp) {
        // Base cases
        if(i>j)return 0;       // empty tree → cost = 0
        if(i==j)return freq[i]; // one key only → cost = freq[i]
        if(dp[i][j]!=-1)return dp[i][j];
        int cost=INT_MAX;
        int weight=wt(i,j,freq);
        // Try every key as root
        for(int k=i;k<=j;k++) {
            int left=solve(i,k-1,keys,freq,dp);
            int right=solve(k+1,j,keys,freq,dp);
            int curr=left+right+weight;
            cost=min(cost,curr);
        }
        return dp[i][j]=cost;
    }

    int minCost(vector<int> &keys, vector<int> &freq) {
        int n=keys.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0,n-1,keys,freq,dp);
    }
};

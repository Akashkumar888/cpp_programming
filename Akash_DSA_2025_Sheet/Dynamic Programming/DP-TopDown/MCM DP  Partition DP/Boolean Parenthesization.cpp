
// User function Template for C++
class Solution {
  public:
  int solve(int i,int j,bool isTrue,string &expression,vector<vector<vector<int>>>&dp){
    if(i>j)return 0;
    if(i==j){
      if(isTrue)return expression[i]=='T';
      else return expression[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    int ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        int leftPartitionTrue=solve(i,k-1,true,expression,dp);
        int leftPartitionFalse=solve(i,k-1,false,expression,dp);
        int rightPartitionTrue=solve(k+1,j,true,expression,dp);
        int rightPartitionFalse=solve(k+1,j,false,expression,dp);
        if(expression[k]=='&'){// when both are true then true otherwise false 
            // for logical and &
            // T&T=T, T&F=F, F&T=F, F&F=F 
            if(isTrue)ways+=(leftPartitionTrue*rightPartitionTrue);
            else ways+=(rightPartitionTrue*leftPartitionFalse)+(rightPartitionFalse*leftPartitionTrue)+(leftPartitionFalse*rightPartitionFalse);
        }
        else if(expression[k]=='|'){// when anyone true then gives true otherwise false 
            // for logical or |
            // T|T=T, T|F=T, F|T=T, F|F=F 
            if(isTrue)ways+=(leftPartitionTrue*rightPartitionTrue)+(leftPartitionTrue*rightPartitionFalse)+(leftPartitionFalse*rightPartitionTrue);
        else ways+=(leftPartitionFalse*rightPartitionFalse);
        }
        else{// odd number of true then true otherwise false
            // for logical xor ^
            // T^T=F, T^F=T, F^T=T, F^F=F 
            if(isTrue)ways+=(leftPartitionTrue*rightPartitionFalse)+(leftPartitionFalse*rightPartitionTrue);
            else ways+=(leftPartitionTrue*rightPartitionTrue)+(leftPartitionFalse*rightPartitionFalse);
        }
    }
    return dp[i][j][isTrue]=ways;
}
    int countWays(string &expression) {
        // code here
        int n=expression.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,n-1,true,expression,dp);
    }
};



class Solution {
  public:
    int countWays(string &expression) {
        int n = expression.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        // ✅ base case
        for(int i = 0; i < n; i++){
            dp[i][i][1] = (expression[i] == 'T');
            dp[i][i][0] = (expression[i] == 'F');
        }

        // ✅ interval DP by length (odd length only)
        for(int len = 3; len <= n; len += 2){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                dp[i][j][0] = dp[i][j][1] = 0;

                for(int k = i + 1; k <= j - 1; k += 2){
                    int leftPartitionTrue  = dp[i][k - 1][1];
                    int leftPartitionFalse = dp[i][k - 1][0];
                    int rightPartitionTrue = dp[k + 1][j][1];
                    int rightPartitionFalse= dp[k + 1][j][0];

                    if(expression[k] == '&'){
                        dp[i][j][1] += leftPartitionTrue * rightPartitionTrue;
                        dp[i][j][0] += leftPartitionTrue * rightPartitionFalse
                                     + leftPartitionFalse * rightPartitionTrue
                                     + leftPartitionFalse * rightPartitionFalse;
                    }
                    else if(expression[k] == '|'){
                        dp[i][j][1] += leftPartitionTrue * rightPartitionTrue
                                     + leftPartitionTrue * rightPartitionFalse
                                     + leftPartitionFalse * rightPartitionTrue;
                        dp[i][j][0] += leftPartitionFalse * rightPartitionFalse;
                    }
                    else{ // '^'
                        dp[i][j][1] += leftPartitionTrue * rightPartitionFalse
                                     + leftPartitionFalse * rightPartitionTrue;
                        dp[i][j][0] += leftPartitionTrue * rightPartitionTrue
                                     + leftPartitionFalse * rightPartitionFalse;
                    }
                }
            }
        }
        return dp[0][n - 1][1];
    }
};

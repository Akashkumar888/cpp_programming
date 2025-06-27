
class Solution {
  public:
  typedef long long ll;
//   Add "no move" (stay on same key)
  vector<vector<int>> directions = {
    {0,-1},{-1,0},{1,0},{0,1},{0,0}  // 👈 Added (0,0)
};

  ll solve(int i,int j,int len,int n,vector<vector<char>>&keypad,vector<vector<vector<ll>>>&dp){
      if(i<0 || j<0 || i>=4 || j>=3 || keypad[i][j]==' ')return 0;
      if(len==n)return 1;
      if(dp[i][j][len]!=-1)return dp[i][j][len];
      ll count=0;
      for(auto &dir:directions){
          int new_i=i+dir[0];
          int new_j=j+dir[1];
          // increase len+1 each time 
          count=count+solve(new_i,new_j,len+1,n,keypad,dp);
      }
       dp[i][j][len]=count;  // ✅ correct
       return dp[i][j][len];   // ✅ returns correct value
  }
    int getCount(int n) {
        // code here
        vector<vector<char>>keypad ={
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
            {' ', '0', ' '}
            };
            ll total=0;
        vector<vector<vector<ll>>>dp(4,vector<vector<ll>>(3,vector<ll>(n+1,-1)));
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(keypad[i][j]!=' '){
                    total=total+solve(i,j,1,n,keypad,dp);
                }
            }
        }
        return (int)total;
    }
};

✅ Final Time Complexity:O(n)

✅ Final Space Complexity:O(n)  // both memo and call stack


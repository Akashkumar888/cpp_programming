
// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// Function to find the total number
// of ways to tile a 2*N board using
// the given types of tile
int numTilings(int N)
{
    // If N is less than 3
    if (N < 3) {
        return N;
    }

    // Store all dp-states
    vector<vector<long long> > dp(
        N + 1, vector<long long>(3, 0));

    // Base Case
    dp[0][0] = dp[1][0] = 1;
    dp[1][1] = dp[1][2] = 1;

    // Traverse the range [2, N]
    for (int i = 2; i <= N; i++) {

        // Update the value of dp[i][0]
        dp[i][0] = (dp[i - 1][0]
                    + dp[i - 2][0]
                    + dp[i - 2][1]
                    + dp[i - 2][2])
                   % MOD;

        // Update the value of dp[i][1]
        dp[i][1] = (dp[i - 1][0]
                    + dp[i - 1][2])
                   % MOD;

        // Update the value of dp[i][2]
        dp[i][2] = (dp[i - 1][0]
                    + dp[i - 1][1])
                   % MOD;
    }

    // Return the number of ways as
    // the value of dp[N][0]
    return dp[N][0];
}

// Driver Code
int main()
{
    int N = 3;
    cout << numTilings(N);

    return 0;
}

#include<bits/stdc++.h>
#include<iostream>
#define ll long long
ll mod=1e9+7;
using namespace std;

void the_solver(int n){
      vector<ll>dp(n+1,0);
      dp[0]=1;
      dp[1]=1;dp[2]=2;dp[3]=5;
      if(n<=3){
        cout<<dp[n]<<endl;
        return;
      }
      for(int i=4;i<=n;i++){
          dp[i]=2*(dp[i-1])+dp[i-3];
          dp[i]%=mod;
      }
      cout<<dp[n]<<endl;
      return;
}

signed main(){
   int n=3;
   the_solver(n);
    return 0;
}

class Solution {
public:
// You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
// Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.
// Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.
int MOD=1e9+7;
    int numTilings(int n) {
        if(n==1 ||n==2)return n;
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=((2*dp[i-1])%MOD+(dp[i-3])%MOD)%MOD;
        }
        return dp[n]%MOD;
    }
};

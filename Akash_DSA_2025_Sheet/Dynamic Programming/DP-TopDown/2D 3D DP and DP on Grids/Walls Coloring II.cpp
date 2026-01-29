
class Solution {
  public:
  int solve(int curr,int last,int m,vector<vector<int>>&costs,vector<vector<int>>&dp){
      if(curr==0){
          int value=INT_MAX;
          for(int k=0;k<m;k++){
              if(k!=last)value=min(value,costs[curr][k]);
          }
        return value;
      }
      if(dp[curr][last]!=-1)return dp[curr][last];
      int pick=INT_MAX;
      for(int k=0;k<m;k++){
          if(k!=last)pick=min(pick,costs[curr][k]+solve(curr-1,k,m,costs,dp)); 
      }
      return dp[curr][last]=pick;
  }
    int minCost(vector<vector<int>> &costs) {
        // code here
        int n=costs.size();
        int m=costs[0].size();
        // 🚨 CRITICAL INVALID CONDITION
        // if there is one color available and more 
        // than 1 wall then we can't paint two 
        // adjancent walls with different colors
        if(m == 1 && n > 1) return -1;
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        int curr=n-1,last=m;
        return solve(curr,last, m, costs, dp);
    }
};



class Solution {
  public:
    int minCost(vector<vector<int>> &costs) {
        // code here
        int n=costs.size();
        int m=costs[0].size();
        // 🚨 CRITICAL INVALID CONDITION
        if(m == 1 && n > 1) return -1;
        vector<vector<int>>dp(n,vector<int>(m+1,INT_MAX));
        // Base case 
        for(int j=0;j<m;j++){
            int value=INT_MAX;
          for(int k=0;k<m;k++){
              if(k!=j)value=min(value,costs[0][k]);
          }
         dp[0][j]=value;
        }

        // ⭐ CRITICAL FIX ⭐
        int best = INT_MAX;
        for(int k = 0; k < m; k++)
            best = min(best, costs[0][k]);
        dp[0][m] = best;

        for(int curr=1;curr<n;curr++){
            for(int last=0;last<=m;last++){
                int pick=INT_MAX;
                  for(int k=0;k<m;k++){
                      if(k != last){
                        if(dp[curr-1][k] != INT_MAX)
                            pick = min(pick, costs[curr][k] + dp[curr-1][k]);
                    }
                  }
                  dp[curr][last]=pick;
            }
        }
        return dp[n-1][m];
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int n = costs.size();
        int m = costs[0].size();

        if(m == 1 && n > 1) return -1;

        vector<int> prev(m + 1), temp(m + 1);

        // ---------------- BASE CASE ----------------
        for(int last = 0; last <= m; last++){
            int value = INT_MAX;
            for(int k = 0; k < m; k++){
                if(k != last)
                    value = min(value, costs[0][k]);
            }
            prev[last] = value;
        }

        // ---------------- BUILD ROW BY ROW ----------------
        for(int curr = 1; curr < n; curr++){
            for(int last = 0; last <= m; last++){

                int pick = INT_MAX;

                for(int k = 0; k < m; k++){
                    if(k != last && prev[k] != INT_MAX){
                        pick = min(pick, costs[curr][k] + prev[k]);
                    }
                }

                temp[last] = pick;
            }

            prev = temp;  // move forward
        }

        return prev[m];
    }
};



class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int m = costs[0].size();

        if(m == 1 && n > 1) return -1;

    // prevMin1 = smallest dp value for previous row
    // prevMin2 = second smallest dp value
    // idx = index of color giving prevMin1
    int prevMin1 = INT_MAX, prevMin2 = INT_MAX, idx = -1;

    // process first wall
    for(int color = 0; color < m; color++){
        int value = costs[0][color];

        if(value < prevMin1){
            prevMin2 = prevMin1;
            prevMin1 = value;
            idx = color;
        }
        else if(value < prevMin2){
            prevMin2 = value;
        }
    }

    // process remaining walls
    for(int curr = 1; curr < n; curr++){

        int currMin1 = INT_MAX, currMin2 = INT_MAX, currIdx = -1;

        for(int color = 0; color < m; color++){

            int pick;

            // cannot use prevMin1 if color same as idx
            if(color == idx) pick = costs[curr][color] + prevMin2;
            else             pick = costs[curr][color] + prevMin1;

            // update currMin1 & currMin2
            if(pick < currMin1){
                currMin2 = currMin1;
                currMin1 = pick;
                currIdx = color;
            }
            else if(pick < currMin2){
                currMin2 = pick;
            }
        }

        // shift current row → previous row
        prevMin1 = currMin1;
        prevMin2 = currMin2;
        idx = currIdx;
    }

    return prevMin1; // minimum cost for last wall
    }
};



class Solution {
public:
    int minCost(vector<vector<int>>& costs) {

        int n = costs.size();
        int m = costs[0].size();

        if(m == 1 && n > 1) return -1;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // ------------ BASE CASE ----------------
        for(int j = 0; j < m; j++){
            dp[0][j] = costs[0][j];
        }

        // ------------ DP BUILD O(n*m) ----------
        for(int i = 1; i < n; i++){

            // find min1, min2 and index of min1 in prev row
            int min1 = INT_MAX, min2 = INT_MAX, idx = -1;

            for(int j = 0; j < m; j++){
                if(dp[i-1][j] < min1){
                    min2 = min1;
                    min1 = dp[i-1][j];
                    idx = j;
                }
                else if(dp[i-1][j] < min2){
                    min2 = dp[i-1][j];
                }
            }

            // fill dp[i][j]
            for(int j = 0; j < m; j++){
                if(j == idx) dp[i][j] = costs[i][j] + min2;
                else         dp[i][j] = costs[i][j] + min1;
            }
        }

        // final answer
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(ans, dp[n-1][j]);

        return ans;
    }
};



class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int m = costs[0].size();

        // invalid condition
        if(m == 1 && n > 1) return -1;

        // dp[j] = best cost if current row uses color j
        vector<int> dp(m), newdp(m);

        // ------------------ BASE CASE --------------------
        for(int j = 0; j < m; j++){
            dp[j] = costs[0][j];
        }

        // ------------------ BUILD DP ---------------------
        for(int i = 1; i < n; i++){

            // find min1, min2, and index of min1
            int min1 = INT_MAX, min2 = INT_MAX, idx = -1;

            for(int j = 0; j < m; j++){
                if(dp[j] < min1){
                    min2 = min1;
                    min1 = dp[j];
                    idx = j;
                } else if(dp[j] < min2){
                    min2 = dp[j];
                }
            }

            // fill newdp for row i
            for(int j = 0; j < m; j++){
                if(j == idx) newdp[j] = costs[i][j] + min2;
                else         newdp[j] = costs[i][j] + min1;
            }

            dp = newdp;  // move to next iteration
        }

        // ------------------ ANSWER -----------------------
        int ans = INT_MAX;
        for(int j = 0; j < m; j++)
            ans = min(ans, dp[j]);

        return ans;
    }
};


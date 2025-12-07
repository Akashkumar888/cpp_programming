
class Solution {
  public:
  int solve(int curr,int last,vector<vector<int>>&arr,vector<vector<int>>&dp){
      if(curr==0){
          int maxi=0;
          for(int k=0;k<3;k++){
              if(k!=last)maxi=max(maxi,arr[curr][k]);
          }
          return maxi;
      }
      if(dp[curr][last]!=-1)return dp[curr][last];
      int pick=0;
      for(int k=0;k<3;k++){
          if(last!=k)pick=max(pick,arr[curr][k]+solve(curr-1,k,arr,dp));
      }
      return dp[curr][last]=pick;      
  }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        int curr=n-1,last=3;
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return solve(curr,last,arr,dp);
    }
};


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        // dp[curr][last] : max points till day curr, last activity = last
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // Base case: curr = 0
        for(int last = 0; last < 4; last++){
            int maxi = 0;
            for(int k = 0; k < 3; k++){
                if(k != last){
                    maxi = max(maxi, arr[0][k]);
                }
            }
            dp[0][last] = maxi;
        }
        // Build bottom-up
        for(int curr = 1; curr < n; curr++){
            for(int last = 0; last < 4; last++){
                int pick = 0;
                for(int k = 0; k < 3; k++){
                    if(k != last){
                        pick = max(pick, arr[curr][k] + dp[curr-1][k]);
                    }
                }
                dp[curr][last] = pick;
            }
        }
        return dp[n-1][3];  // answer when last = 3 (free choice)
    }
};


class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        vector<int>prev(4, 0),temp(4,0);
        // Base case: curr = 0
        for(int last = 0; last < 4; last++){
            int maxi = 0;
            for(int k = 0; k < 3; k++){
                if(k != last){
                    maxi = max(maxi, arr[0][k]);
                }
            }
            prev[last]= maxi;
        }
        // Build bottom-up
        for(int curr = 1; curr < n; curr++){
            for(int last = 0; last < 4; last++){
                int pick = 0;
                for(int k = 0; k < 3; k++){
                    if(k != last){
                        pick = max(pick, arr[curr][k] + prev[k]);
                    }
                }
                temp[last] = pick;
            }
            prev=temp;
        }
        return prev[3];  // answer when last = 3 (free choice)
    }
};
// ✅ 1️⃣ TSP using Graph + DP + Bitmask (Optimal DP Algorithm)
// Time: O(n × 2ⁿ)
// Space: O(n × 2ⁿ)

class Solution {
  public:
  // Solves TSP using DP + Bitmask
    // mask = set of visited cities (bitmask)
    // pos  = current city
  int solve(int mask,int pos,int n,vector<vector<int>>&cost,vector<vector<int>>&dp){
      // If all cities are visited -> return cost to go back to city 0
      if(mask==((1<<n)-1))return cost[pos][0];
      // If already computed, return memoized value
      if(dp[mask][pos]!=-1)return dp[mask][pos];
      int totalCost=INT_MAX;
      // Try visiting every unvisited city
      for(int city=0;city<n;city++){
          // If 'city' is not visited in mask
          if((mask&(1<<city))==0){
              // Go from pos -> city and mark city as visited
              int newCost=cost[pos][city] + solve(mask | (1<<city) ,city,n,cost,dp);
              totalCost=min(totalCost,newCost);
          }
      }
      return dp[mask][pos]=totalCost;
  }
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n=cost.size();
        // if 1111 it is 15 visite array size 1<<n or total subsets
        vector<vector<int>> dp(1<<n, vector<int>(n, -1));
        // dp[mask][pos]
         /*
           We start with:

           mask = 1  →  binary 0001 (only city 0 is visited)
           pos  = 0  →  starting city

           Why start solve(1, 0)?

           ✔ TSP always starts from a fixed city (we choose city 0).
           ✔ Initially, only city 0 is visited.
              So mask = 1 << 0 = 1.

           Meaning:
               mask = 0001  (city 0 visited)
               pos  = 0     (current city is 0)

           Now the solve() function will:
               - Try going to every unvisited city
               - Build all possible tours
               - Return minimum Hamiltonian cycle cost
        */
        return solve(1,0,n,cost,dp);
    }
};





class Solution {
  public:
    int tsp(vector<vector<int>>& cost) {
        // code here
        int n=cost.size();
        // if 1111 it is 15 visite array size 1<<n or total subsets
        vector<vector<int>> dp(1<<n, vector<int>(n, 0));
        // dp[mask][pos]
         /*
           We start with:

           mask = 1  →  binary 0001 (only city 0 is visited)
           pos  = 0  →  starting city

           Why start solve(1, 0)?

           ✔ TSP always starts from a fixed city (we choose city 0).
           ✔ Initially, only city 0 is visited.
              So mask = 1 << 0 = 1.

           Meaning:
               mask = 0001  (city 0 visited)
               pos  = 0     (current city is 0)

           Now the solve() function will:
               - Try going to every unvisited city
               - Build all possible tours
               - Return minimum Hamiltonian cycle cost
        */
        int fullMask = (1<<n) - 1;
        for(int pos = 0; pos < n; pos++) {
            dp[fullMask][pos] = cost[pos][0];
        }
        for(int mask=fullMask-1;mask>=0;mask--){
            for(int pos=0;pos<n;pos++){
                int totalCost=INT_MAX;
              // Try visiting every unvisited city
              for(int city=0;city<n;city++){
                  // If 'city' is not visited in mask
                  if((mask&(1<<city))==0){
                      // Go from pos -> city and mark city as visited
                      int newCost=cost[pos][city] + dp[mask | (1<<city)][city];
                      totalCost=min(totalCost,newCost);
                  }
              }
              dp[mask][pos]=totalCost;
            }
        }
         // Start from mask=1 (only city 0 visited), position 0
        return dp[1][0];
    }
};




class Solution {
public:
    int solve(int mask, int pos, int n,
              vector<vector<int>>& cost,
              vector<vector<int>>& dp,
              int startCity) {

        int fullMask = (1<<n) - 1;

        // base case: return to startCity (n-1)
        if(mask == fullMask)
            return cost[pos][startCity];

        if(dp[mask][pos] != -1)
            return dp[mask][pos];

        int totalCost = INT_MAX;

        for(int city = 0; city < n; city++) {

            if((mask & (1<<city)) == 0) {  // unvisited

                int newCost = cost[pos][city] +
                              solve(mask | (1<<city), city,
                                    n, cost, dp, startCity);

                totalCost = min(totalCost, newCost);
            }
        }

        return dp[mask][pos] = totalCost;
    }


    int tsp(vector<vector<int>>& cost) {

        int n = cost.size();

        int startCity = n - 1;          // start from city n-1
        int startMask = 1 << startCity; // only n-1 visited initially

        vector<vector<int>> dp(1<<n, vector<int>(n, -1));

        return solve(startMask, startCity, n, cost, dp, startCity);
    }
};

class Solution {
public:
    int tsp(vector<vector<int>>& cost) {

        int n = cost.size();
        int fullMask = (1<<n) - 1;

        int startCity = n-1;                // start at city n-1
        int startMask = 1 << startCity;     // only city n-1 visited

        // dp[mask][pos] -> min cost when at pos with visited = mask
        vector<vector<int>> dp(1<<n, vector<int>(n, INT_MAX));

        // -------------------------------
        // Base Case (same as top-down)
        // If all cities are visited -> return to startCity (n-1)
        // dp[fullMask][pos] = cost[pos][startCity]
        // -------------------------------
        for(int pos = 0; pos < n; pos++){
            dp[fullMask][pos] = cost[pos][startCity];
        }

        // -------------------------------
        // Bottom-Up Filling
        // mask goes from fullMask-1 down to 0
        // -------------------------------
        for(int mask = fullMask-1; mask >= 0; mask--){

            for(int pos = 0; pos < n; pos++){

                // INVALID state: pos must already be visited in mask
                if((mask & (1<<pos)) == 0) continue;

                int totalCost = INT_MAX;

                // Try visiting every unvisited city
                for(int city = 0; city < n; city++){

                    if((mask & (1<<city)) == 0){     // not visited

                        int newMask = mask | (1<<city);
                        int newCost = cost[pos][city] + dp[newMask][city];

                        totalCost = min(totalCost, newCost);
                    }
                }

                dp[mask][pos] = totalCost;
            }
        }

        // -------------------------------
        // FINAL ANSWER
        // startMask = only n-1 visited
        // startCity = n-1
        // same as top-down's solve(startMask, startCity)
        // -------------------------------
        return dp[startMask][startCity];
    }
};

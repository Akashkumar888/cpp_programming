
// User function template for C++
// Convert adjacency matrix → adjacency list.
// Use DP on number of edges.
// dp[0][u] = 1
// For each edge count from 1 to k:
// For each node:
// For each outgoing neighbor:
// Add ways.
// Answer = dp[k][v].
class Solution {
  public:
  int Mod=1e9+7;
  int dfs(int u,int v,int k,unordered_map<int,vector<int>>&adj,vector<vector<int>>&dp){
      if(u==v && k==0)return 1;
      if(dp[u][k]!=-1)return dp[u][k];
      int countPath=0;
      for(auto &ngbr:adj[u]){
          countPath=(countPath%Mod+dfs(ngbr,v,k-1,adj,dp)%Mod)%Mod;
      }
      return dp[u][k]=countPath;
  }
    int MinimumWalk(vector<vector<int>>& graph, int u, int v, int k) {
        // Code here
        //✅ Correct Code to Convert Adjacency Matrix → Adjacency List
        unordered_map<int, vector<int>> adj;
        int n=graph.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){   // Only push if edge exists
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return dfs(u,v,k,adj,dp);
    }
};


// User function template for C++
// Convert adjacency matrix → adjacency list.
// Use DP on number of edges.
// dp[0][u] = 1
// For each edge count from 1 to k:
// For each node:
// For each outgoing neighbor:
// Add ways.
// Answer = dp[k][v].
class Solution {
  public:
  int Mod=1e9+7;
    int MinimumWalk(vector<vector<int>>& graph, int u, int v, int k) {
        // Code here
        //✅ Correct Code to Convert Adjacency Matrix → Adjacency List
        unordered_map<int, vector<int>> adj;
        int n=graph.size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(graph[i][j]==1){   // Only push if edge exists
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        // Base case: exactly 0 steps → only v can be reached from v
        dp[v][0] = 1;
        // Bottom-up DP for edges = 1...k
        for(int steps = 1; steps <= k; steps++){
            for(int u = 0; u < n; u++){
                int countPath=0;
                  for(auto &ngbr:adj[u]){
                      countPath=(countPath%Mod+dp[ngbr][steps-1]%Mod)%Mod;
                  }
                  dp[u][steps]=countPath;
            }
        }
        // We need number of walks from u to v with exactly k edges
        return dp[u][k];
    }
};
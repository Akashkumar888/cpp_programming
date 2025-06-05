


class Solution {
  public:
  int dfs(unordered_map<int,vector<int>>&adj,int src,int dest,vector<int>&dp){
      if(src==dest)return 1;
      if(dp[src]!=-1)return dp[src];
      int countPath=0;
      for(auto &ngbr:adj[src]){
           countPath+=dfs(adj,ngbr,dest,dp);
      }
      dp[src]=countPath;
      return countPath;
  }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<int>dp(V,-1);
        return dfs(adj,src,dest,dp);
    }
};




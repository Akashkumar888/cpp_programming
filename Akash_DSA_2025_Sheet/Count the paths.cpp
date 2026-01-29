
// dfs solution 

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

// bfs solution 
class Solution {
public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        queue<pair<int, vector<bool>>> q;
        vector<bool> visited(V, false);
        int count = 0;

        // start with src node and fresh visited state
        visited[src] = true;
        q.push({src, visited});

        while (!q.empty()) {
            auto [node, vis] = q.front();
            q.pop();

            if (node == dest) {
                count++;
                continue;
            }

            for (int neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    vector<bool> newVis = vis;
                    newVis[neighbor] = true;
                    q.push({neighbor, newVis});
                }
            }
        }

        return count;
    }
};


















// Your graph has cycles → then we need a visited[] + backtracking version only.

// You want to list all paths, not just count.

class Solution {
  public:
  void dfs(unordered_map<int,vector<int>>& adj, vector<bool>& visited, int src, int dest, int &countPath) {
      if (src == dest) {
          countPath++;
          return;
      }

      visited[src] = true;
      for (auto &ngbr : adj[src]) {
          if (!visited[ngbr]) {
              dfs(adj, visited, ngbr, dest, countPath); // ✅ Fix here
          }
      }
      visited[src] = false; // backtrack
  }

  int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
      unordered_map<int,vector<int>> adj;
      for (auto &edge : edges) {
          int u = edge[0];
          int v = edge[1];
          adj[u].push_back(v);
      }

      vector<bool> visited(V, false);
      int countPath = 0;
      dfs(adj, visited, src, dest, countPath);
      return countPath;
  }
};


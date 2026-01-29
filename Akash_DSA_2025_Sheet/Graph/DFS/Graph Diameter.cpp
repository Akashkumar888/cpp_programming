class Solution {
  public:
  
  // DFS returns farthest node and its distance
  void dfs(int u, int dist, vector<bool>& visited, unordered_map<int, vector<int>>& adj, int &maxDist, int &farthestNode) {
      visited[u] = true;
      if (dist > maxDist) {
          maxDist = dist;
          farthestNode = u;
      }
      for (auto &v : adj[u]) {
          if (!visited[v]) {
              dfs(v, dist + 1, visited, adj, maxDist, farthestNode);
          }
      }
  }
  int diameter(int V, vector<vector<int>>& edges) {
      unordered_map<int, vector<int>> adj;

      // Build adjacency list
      for (auto &it : edges) {
          int u = it[0];
          int v = it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }

      // 1️⃣ First DFS — find farthest node from 0
      vector<bool> visited(V, false);
      int maxDist = -1;
      int farthestNode = -1;
      dfs(0, 0, visited, adj, maxDist, farthestNode);

      // 2️⃣ Second DFS — from farthestNode, find maximum distance
      fill(visited.begin(), visited.end(), false);
      maxDist = -1;
      dfs(farthestNode, 0, visited, adj, maxDist, farthestNode);

      // 3️⃣ maxDist is the diameter
      return maxDist;
  }
};

// 🌳 Logic Recap (Two DFS Method for Tree Diameter)

// First DFS:
// Start from any node (say 0).
// → Find the farthest node from it — call it farthestNode.

// Second DFS:
// Start from farthestNode.
// → The farthest distance found in this DFS = tree diameter.

class Solution {
  public:
  // DFS returns farthest node and its distance
  void dfs(int u,int dist,vector<bool>&visited,unordered_map<int,vector<int>>&adj,int &maxDist,int &farthestNode){
      visited[u]=true;
      if(dist>maxDist){
          maxDist=dist;
          farthestNode=u;
      }
      for(auto &v:adj[u]){
          if(!visited[v]){
              dfs(v,dist+1,visited,adj,maxDist,farthestNode);
          }
      }
  }
  int diameter(int V, vector<vector<int>>& edges) {
      unordered_map<int, vector<int>> adj;
      // Build adjacency list
      for (auto &it : edges) {
          int u = it[0];
          int v = it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
        //Logic Recap (Two DFS Method for Tree Diameter)
        // First DFS:
        // Start from any node (say 0).
        // → Find the farthest node from it — call it farthestNode.
        // Second DFS:
        // Start from farthestNode.
        // → The farthest distance found in this DFS = tree diameter.
    // 1️⃣ First DFS — find farthest node from 0
      vector<bool> visited(V, false);
      int maxDist=-1;
      int farthestNode=-1;
      // here you can start from anywhere 0 to V-1 
      dfs(V-1,0,visited,adj,maxDist,farthestNode);

      // 2️⃣ Second DFS — from farthestNode, find maximum distance
      maxDist=-1;
      fill(visited.begin(),visited.end(),false);
      dfs(farthestNode,0,visited,adj,maxDist,farthestNode);
      // 3️⃣ maxDist is the diameter
      return maxDist;
  }
};

class Solution {
  public:
  int dfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& adj, int &diameter) {
      visited[u] = true;
      int maxDepth1 = 0; // longest depth from this node
      int maxDepth2 = 0; // second longest depth
      for (auto &v : adj[u]) {
          if (!visited[v]) {
              int childDepth = dfs(v, visited, adj, diameter);
              // Track two largest child depths
              if (childDepth > maxDepth1) {
                  maxDepth2 = maxDepth1;
                  maxDepth1 = childDepth;
              } 
              else if (childDepth > maxDepth2) {
                  maxDepth2 = childDepth;
              }
          }
      }
      // Update diameter using two deepest subtrees
      diameter = max(diameter, maxDepth1 + maxDepth2);
      return maxDepth1 + 1;
  }
  int diameter(int V, vector<vector<int>>& edges) {
      unordered_map<int, vector<int>> adj;
      for (auto &it : edges) {
          int u = it[0];
          int v = it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      vector<bool> visited(V, false);
      int maxDiameter = 0;
      dfs(0, visited, adj, maxDiameter); // start DFS from any node
      return maxDiameter;
  }
};
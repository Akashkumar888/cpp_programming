
bool dfs(int u, unordered_map<int,vector<int>>& adj, vector<bool>& visited, vector<bool>& inRec) {
  visited[u] = true;
  inRec[u] = true;
  for (auto &ngbr : adj[u]) {
      if (inRec[ngbr] == true) return true;
      if (!visited[ngbr]) {
          if (dfs(ngbr, adj, visited, inRec)) return true;
      }
  }
  inRec[u] = false;
  return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
  unordered_map<int,vector<int>> adj;
  for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
  }
  vector<bool> visited(V, false), inRec(V, false);
  for (int i = 0; i < V; i++) {
      if (!visited[i]) {
          if (dfs(i, adj, visited, inRec)) return true;
      }
  }
  return false;
}

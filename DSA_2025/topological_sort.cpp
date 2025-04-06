
vector<int> topoSort(int V, vector<vector<int>>& edges) {
  unordered_map<int, vector<int>> adj;
  vector<int> indegree(V, 0), ans;

  for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      indegree[v]++;
  }

  queue<int> q;
  for (int i = 0; i < V; i++) {
      if (indegree[i] == 0)
          q.push(i);
  }

  while (!q.empty()) {
      int curr = q.front(); q.pop();
      ans.push_back(curr);
      for (auto &ngbr : adj[curr]) {
          indegree[ngbr]--;
          if (indegree[ngbr] == 0)
              q.push(ngbr);
      }
  }

  return ans;
}


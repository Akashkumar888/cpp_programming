
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
  vector<int> distance(V, 1e8);
  distance[src] = 0;

  // Step 1: Relax edges V-1 times
  for (int i = 0; i < V - 1; i++) {
      for (auto &edge : edges) {
          int u = edge[0], v = edge[1], wt = edge[2];
          if (distance[u] != 1e8 && distance[u] + wt < distance[v]) {
              distance[v] = distance[u] + wt;
          }
      }
  }

  // Step 2: Check for negative weight cycle
  for (auto &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      if (distance[u] != 1e8 && distance[u] + wt < distance[v]) {
          return {-1}; // Negative cycle found
      }
  }

  return distance;
}

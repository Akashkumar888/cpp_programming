
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
  typedef pair<int,int> P;
  unordered_map<int,vector<P>> adj;
  for(auto &edge : edges){
      int u = edge[0], v = edge[1], wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
  }

  vector<int> distance(V, INT_MAX);
  priority_queue<P, vector<P>, greater<P>> pq;
  distance[src] = 0;
  pq.push({0, src});

  while(!pq.empty()) {
      int wt = pq.top().first;
      int u = pq.top().second;
      pq.pop();

      for(auto &vec : adj[u]) {
          int adjNode = vec.first;
          int cost = vec.second;
          if(wt + cost < distance[adjNode]) {
              distance[adjNode] = wt + cost;
              pq.push({wt + cost, adjNode});
          }
      }
  }

  return distance;
}

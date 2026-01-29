
typedef pair<int,int> P;

int dijkstra(int V, unordered_map<int,vector<P>>& adj, int src, int dest) {
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, src});
    dist[src] = 0;
    
    while (!pq.empty()) {
        int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        for (auto &vec : adj[u]) {
            int adjNode = vec.first;
            int d = vec.second;
            // Skip the original edge we are considering
            if ((u == src && adjNode == dest) || (u == dest && adjNode == src))
                continue;
            if (d + wt < dist[adjNode]) {
                dist[adjNode] = d + wt;
                pq.push({d + wt, adjNode});
            }
        }
    }
    return dist[dest];
}

int findMinCycle(int V, vector<vector<int>>& edges) {
    unordered_map<int,vector<P>> adj;
    for (auto &it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    int minWeight = INT_MAX;
    
    for (auto &it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        int distance = dijkstra(V, adj, u, v);
        if (distance != INT_MAX) 
            minWeight = min(minWeight, distance + wt);
    }
    
    if (minWeight == INT_MAX) return -1;
    return minWeight;
}

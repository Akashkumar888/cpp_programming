
bool hasCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // Build graph
    for(auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    int removedNodes = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();
        removedNodes++;

        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    return removedNodes != V; // TRUE → cycle exists
}

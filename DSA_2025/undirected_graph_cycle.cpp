
#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int parent, vector<bool> &visited, unordered_map<int, vector<int>> &mp) {
    visited[u] = true;
    for (auto &v : mp[u]) {
        if (v == parent) continue;  // Ignore the edge leading to the parent
        if (visited[v]) return true;  // Cycle detected
        if (dfs(v, u, visited, mp)) return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> mp;
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1];
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, mp)) return true;
        }
    }
    return false;
}

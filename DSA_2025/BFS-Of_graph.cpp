
#include <bits/stdc++.h>
using namespace std;

void bfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        
        for (auto& ngbr : adj[curr]) {
            if (!visited[ngbr]) {
                q.push(ngbr);
                visited[ngbr] = true;
            }
        }
    }
}

// Function to return Breadth First Traversal of given graph.
vector<int> bfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> ans;
    vector<bool> visited(n, false);
    bfs(0, adj, visited, ans);
    return ans;
}

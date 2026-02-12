
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;   // undirected
    }

    return 0;
}

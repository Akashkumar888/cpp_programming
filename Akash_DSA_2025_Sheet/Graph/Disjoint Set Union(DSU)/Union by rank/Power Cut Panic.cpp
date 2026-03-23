
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int ngbr : adj[node]) {
        if (!visited[ngbr]) {
            dfs(ngbr, adj, visited);
        }
    }
}

int count_regions(int n, const vector<pair<int, int>>& connections) {

    vector<vector<int>> adj(n + 1);

    // Build graph
    for (auto &edge : connections) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int regions = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            regions++;
        }
    }

    return regions;
}

int main() {
    int n, m;
    cin >> n >> m;  // Read number of power stations and cables

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;  // Read each cable connection
        connections[i] = make_pair(u, v);
    }

    // Call user logic function and print the output
    int result = count_regions(n, connections);
    cout << result << endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); 
        q.pop();

        for (int ngbr : adj[node]) {
            if (!visited[ngbr]) {
                visited[ngbr] = true;
                q.push(ngbr);
            }
        }
    }
}

int count_regions(int n, const vector<pair<int, int>>& connections) {

    vector<vector<int>> adj(n + 1);

    // Build graph
    for (auto &edge : connections) {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int regions = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(i, adj, visited);
            regions++;
        }
    }

    return regions;
}

int main() {
    int n, m;
    cin >> n >> m;  // Read number of power stations and cables

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;  // Read each cable connection
        connections[i] = make_pair(u, v);
    }

    // Call user logic function and print the output
    int result = count_regions(n, connections);
    cout << result << endl;

    return 0;
}




#include <iostream>
#include <vector>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DSU(int n) { // contructor in used for data members initiallization not declaration 
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    // -------- UNION BY SIZE --------
    void unionsetBySize(int x, int y) { // union ek keyword hai isliye unionset likho 
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent == y_parent) return;

        if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        } 
        else {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
    // -------- UNION BY RANK --------
    void unionsetByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;// y ko x ka parent 
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;// x ko y ka parent
        }
        else {
            parent[y_parent] = x_parent; // x ko y ka parent
            rank[x_parent]++;   // jiska rank badao usko parent bana do dusre ka
        }
    }
};

int count_regions(int n, const vector<pair<int, int>>& connections) {

    DSU dsu(n);

    for (auto &edge : connections) {
        dsu.unionsetBySize(edge.first, edge.second);
    }

    int regions = 0;

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i)
            regions++;
    }

    return regions;
}

int main() {
    int n, m;
    cin >> n >> m;  // Read number of power stations and cables

    vector<pair<int, int>> connections(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;  // Read each cable connection
        connections[i] = make_pair(u, v);
    }

    // Call user logic function and print the output
    int result = count_regions(n, connections);
    cout << result << endl;

    return 0;
}


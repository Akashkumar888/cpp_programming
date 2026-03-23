
// ✅ 1️⃣ BFS + Adjacency List (BEST & EASY)
// 👉 Most reliable method

class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for (auto &edge : edges) {
          int u=edge[0];
          int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxLen = -1;

        for (int i = 0; i < V; i++) {

            vector<int> dist(V, -1);
            vector<int> parent(V, -1);

            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {

                int node = q.front(); 
                q.pop();

                for (auto &ngbr : adj[node]) {

                    if (dist[ngbr] == -1) {
                        dist[ngbr] = dist[node] + 1;
                        parent[ngbr] = node;
                        q.push(ngbr);
                    }
                    else if (parent[node] != ngbr) {
                        int cycleLen = dist[node] + dist[ngbr] + 1;
                        maxLen = max(maxLen, cycleLen);
                    }
                }
            }
        }

        return maxLen;
    }
};


class Solution {
public:
    int findShortestCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];

        for (auto &edge : edges) {
          int u=edge[0];
          int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int minLen = INT_MAX;

        for (int i = 0; i < V; i++) {

            vector<int> dist(V, -1);
            vector<int> parent(V, -1);

            queue<int> q;
            q.push(i);
            dist[i] = 0;

            while (!q.empty()) {

                int node = q.front(); 
                q.pop();

                for (auto &ngbr : adj[node]) {

                    if (dist[ngbr] == -1) {
                        dist[ngbr] = dist[node] + 1;
                        parent[ngbr] = node;
                        q.push(ngbr);
                    }
                    else if (parent[node] != ngbr) {
                        int cycleLen = dist[node] + dist[ngbr] + 1;
                        minLen = min(minLen, cycleLen);
                    }
                }
            }
        }
        return minLen==INT_MAX?-1:minLen;
    }
};

// 🧠 Why Formula Works
// cycleLen = dist[u] + dist[v] + 1
// Because:
// u ----> root ----> v
// You found two paths meeting → cycle

// ✅ 2️⃣ DFS + Adjacency List
class Solution {
public:

    int maxLen = -1;

    void dfs(int u, int parent,
             vector<int>& depth,
             vector<bool>& visited,
             vector<int> adj[]) {

        visited[u] = true;

        for (auto &v : adj[u]) {

            if (v == parent) continue;

            if (!visited[v]) {
                depth[v] = depth[u] + 1;
                dfs(v, u, depth, visited, adj);
            }
            else {
                int cycleLen = abs(depth[u] - depth[v]) + 1;
                maxLen = max(maxLen, cycleLen);
            }
        }
    }

    int longestCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        for (auto &edge : edges) {
          int u=edge[0];
          int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<int> depth(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, depth, visited, adj);
            }
        }

        return maxLen;
    }
};

// ✅ 3️⃣ BFS + unordered_map (Your Style)
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
          int u=edge[0];
          int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxLen = -1;

        for (int i = 0; i < V; i++) {

            unordered_map<int,int> dist;
            unordered_map<int,int> parent;

            queue<int> q;
            q.push(i);
            dist[i] = 0;
            parent[i] = -1;

            while (!q.empty()) {

                int node = q.front(); q.pop();

                for (auto &v : adj[node]) {

                    if (!dist.count(v)) {
                        dist[v] = dist[node] + 1;
                        parent[v] = node;
                        q.push(v);
                    }
                    else if (parent[node] != v) {
                        int len = dist[node] + dist[v] + 1;
                        maxLen = max(maxLen, len);
                    }
                }
            }
        }

        return maxLen;
    }
};

// ✅ 4️⃣ DFS + unordered_map
class Solution {
public:

    int maxLen = -1;

    void dfs(int u, int parent,
             unordered_map<int, vector<int>>& adj,
             unordered_map<int, int>& depth,
             unordered_map<int, bool>& visited) {

        visited[u] = true;

        for (auto &v : adj[u]) {

            if (v == parent) continue;

            if (!visited[v]) {
                depth[v] = depth[u] + 1;
                dfs(v, u, adj, depth, visited);
            }
            else {
                int len = abs(depth[u] - depth[v]) + 1;
                maxLen = max(maxLen, len);
            }
        }
    }

    int longestCycle(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
          int u=edge[0];
          int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,bool> visited;
        unordered_map<int,int> depth;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                depth[i] = 0;
                dfs(i, -1, adj, depth, visited);
            }
        }

        return maxLen;
    }
};
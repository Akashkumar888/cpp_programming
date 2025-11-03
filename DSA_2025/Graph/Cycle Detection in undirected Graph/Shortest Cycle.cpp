
class Solution {
public:
    bool dfs(int u, int target, unordered_map<int, vector<int>> &adj,
             vector<bool> &visited, int len, int &minLen) {

        if(u == target) { 
            minLen = min(minLen, len);
            return true;
        }

        visited[u] = true;

        for(auto &v : adj[u]) {
            if(!visited[v]) {
                dfs(v, target, adj, visited, len + 1, minLen);
            }
        }

        return false;
    }

    int shortCycle(int V, vector<vector<int>>& e) {
        unordered_map<int, vector<int>> adj;

        // build graph
        for(auto &x : e) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        int ans = 1e9;

        for(auto &x : e) {
            int u = x[0], v = x[1];

            // remove edge u - v
            auto &a = adj[u];
            a.erase(remove(a.begin(), a.end(), v), a.end());

            auto &b = adj[v];
            b.erase(remove(b.begin(), b.end(), u), b.end());

            // DFS to find shortest path from u to v
            vector<bool> visited(V, false);
            int minLen = 1e9;
            dfs(u, v, adj, visited, 0, minLen); 

            if(minLen != 1e9) ans = min(ans, minLen + 1); // cycle = path + removed edge

            // add the edge back
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return ans == 1e9 ? -1 : ans;
    }
};

// BFS use to minSteps , shortest path, shortest cycle it is use finding minThings in grpah and tree 
// shortest path bfs heap dijikstra for + positive weight
// shortest path but - negative weight then we should use bell-man ford alogorithm 
// Use BFS to find the shortest cycle in an undirected graph.
// DFS is fine to detect a cycle, not to find shortest cycle length.


class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &e : edges) {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MAX;

        for(int start = 0; start < V; start++) {
         // BFS for each node 
            vector<int> dist(V, -1);
            queue<pair<int,int>> q; // {node, parent}

            q.push({start, -1});
            dist[start] = 0;

            while(!q.empty()) {
                auto [u, parent] = q.front();
                q.pop();

                for(int &ngbr : adj[u]) {

                    // not visited
                    if(dist[ngbr] == -1) {
                        dist[ngbr] = dist[u] + 1;
                        q.push({ngbr, u});
                    }
                    // visited & not coming back to parent => found cycle
                    else if(ngbr != parent) {
                        ans = min(ans, dist[ngbr] + dist[u] + 1);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};

class Solution {
public:
    int bfs(int u,unordered_map<int,vector<int>>&adj) {
        unordered_map<int,int> distance;
        queue<pair<int,int>> q;           // {current_node, parent_node}
        q.push({u,-1});
        distance[u]=0;
        int minlen=INT_MAX;
        while (!q.empty()) {
            int v = q.front().first;
            int parent=q.front().second;
            q.pop();
            for (int ngbr:adj[v]) {
                if (distance.find(ngbr) == distance.end()) { // First visit to neighbor
                    distance[ngbr]=distance[v]+1;
                    q.push({ngbr,v});
                } 
                else if (ngbr!=parent) { // Cycle detected
                    minlen = min(minlen,distance[v]+distance[ngbr]+1);
                }
            }
        }
        return minlen;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int minlen = INT_MAX;
        for (int i=0;i< n;i++) {
            int len = bfs(i, adj);
            if (len != INT_MAX) {
                minlen = min(minlen, len);
            }
        }
        return (minlen == INT_MAX) ? -1 : minlen;
    }
};

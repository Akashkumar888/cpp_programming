
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
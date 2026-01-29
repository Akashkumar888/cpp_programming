
class Solution {
public:
    int shortCycle(int V, vector<vector<int>>& edges) {

        unordered_map<int, vector<int>> adj;
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for(int start = 0; start < V; start++) {

            vector<int> dist(V, -1);
            queue<pair<int,int>> q; // {node, parent}

            q.push({start, -1});
            dist[start] = 0;

            while(!q.empty()) {

                auto [node, parent] = q.front();
                q.pop();

                for(int nbr : adj[node]) {

                    // not visited
                    if(dist[nbr] == -1) {
                        dist[nbr] = dist[node] + 1;
                        q.push({nbr, node});
                    }
                    // visited & not coming back to parent => found cycle
                    else if(nbr != parent) {
                        ans = min(ans, dist[nbr] + dist[node] + 1);
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

class Solution {
public:
    typedef pair<int,int> P;
    void dijkstra(int src, vector<int>& dist, unordered_map<int,vector<P>>& adj) {
        priority_queue<P, vector<P>, greater<P>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &ngbr : adj[node]) {
                int adjNode = ngbr.first;
                int wt      = ngbr.second;

                if (cost + wt < dist[adjNode]) {
                    dist[adjNode] = cost + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
    }
    int shortestPath(int V, int a, int b, vector<vector<int>>& edges) {

        unordered_map<int, vector<P>> adj;

        // Build graph with ONLY straight edges
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w1 = edge[2];
            adj[u].push_back({v, w1});
            adj[v].push_back({u, w1});
        }

        // Run Dijkstra from A
        vector<int> distA(V, INT_MAX);
        dijkstra(a, distA, adj);

        // Run Dijkstra from B
        vector<int> distB(V, INT_MAX);
        dijkstra(b, distB, adj);

        // normal shortest path (no curve)
        int ans = distA[b];

        for(auto &edge : edges) {

            int u  = edge[0];     // starting point of curved edge
            int v  = edge[1];     // ending point of curved edge
            int w2 = edge[3];     // curved edge weight

            // -----------------------------------------------------
            // PART 1:
            // Path = a → u  +  curved(u → v)  +  v → b
            //
            // Earlier you did:
            //   fromA = dijkstra(a, u)
            //   fromV = dijkstra(v, b)
            //   useCurve = fromA + w2 + fromV
            //
            // Now using:
            //   distA[u] = shortest path a → u
            //   distB[v] = shortest path v → b
            // -----------------------------------------------------

            if(distA[u] != INT_MAX && distB[v] != INT_MAX) {
                int useCurve = distA[u] + w2 + distB[v];
                ans = min(ans, useCurve);
            }

            // -----------------------------------------------------
            // PART 2:
            // Path = a → v  +  curved(v → u)  +  u → b
            //
            // Earlier you did:
            //   fromA2 = dijkstra(a, v)
            //   fromU2 = dijkstra(u, b)
            //   useCurve2 = fromA2 + w2 + fromU2
            //
            // Now using:
            //   distA[v] = shortest path a → v
            //   distB[u] = shortest path u → b
            // -----------------------------------------------------

            if(distA[v] != INT_MAX && distB[u] != INT_MAX) {
                int useCurve2 = distA[v] + w2 + distB[u];
                ans = min(ans, useCurve2);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back({v, 0}); // original direction
            adj[v].push_back({u, 1}); // reverse direction
        }

        const int INF = 1e9;

        vector<int> dist(n + 1, INF);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {

            int u = q.front();
            q.pop();

            for (auto &[v, cost] : adj[u]) {

                if (dist[u] + cost < dist[v]) {

                    dist[v] = dist[u] + cost;
                    q.push(v);
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};



class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {

        // adj[u] = {v, cost}
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Original direction: no reversal needed
            adj[u].push_back({v, 0});

            // Reverse direction: 1 reversal needed
            adj[v].push_back({u, 1});
        }

        const int INF = 1e9;

        vector<int> dist(n + 1, INF);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {

            int u = dq.front();
            dq.pop_front();

            for (auto &[v, cost] : adj[u]) {

                if (dist[u] + cost < dist[v]) {

                    dist[v] = dist[u] + cost;

                    if (cost == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};

// But what's the difference?

// With 0-1 BFS:

// if (cost == 0)
//     dq.push_front(v);
// else
//     dq.push_back(v);

// So nodes reachable with cost 0 are processed immediately.


// With a normal queue:

// q.push(v);

// everything goes to the back.

// Therefore, the normal queue does not guarantee shortest-path order.

// However, because we keep doing:

// if (dist[u] + cost < dist[v])

// a node can be processed again when we discover a better distance. This is the basic idea behind SPFA.
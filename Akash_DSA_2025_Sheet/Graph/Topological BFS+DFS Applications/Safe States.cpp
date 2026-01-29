
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
// A vertex with no outgoing edges is called a terminal node.
// A vertex is considered safe if every path starting from it eventually reaches a terminal node.
// Return an array containing all the safe vertices of the graph in ascending order.
// Terminal node Node with no outgoing edges
//Safe node	Node that can only go to terminal nodes or other safe nodes, never into a cycle
// Safe nodes = nodes that cannot reach any cycle and eventually reach a terminal node.
        vector<vector<int>> adjRev(V);
        //         For competitive programming (like this problem)
        // ✅ vector<vector<int>> adj is best and fastest when:
        // Nodes are labeled 0 to V-1
        // You know V beforehand
        // Best performance & safest → Use this
        // O(1) access time (faster than unordered_map)
        // Memory is continuous (cache-friendly)
        // No hashing overhead

        // vector<int>adjRev[V];
        //Create an array of V vectors, where each element of the array is a vector<int>.
        // So:
        // adjRev = name of the array
        // [V] = array has V elements
        // each element is vector<int>

        // unordered_map<int,vector<int>>adjRev;
        vector<int> outDegree(V, 0);

        // Build reverse graph & outdegree count
        // Reverse Graph + Kahn’s Algorithm (Topological BFS)
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adjRev[v].push_back(u);
            outDegree[u]++;
        }
        queue<int> q;
        vector<int> safe;
        // terminal nodes = outdegree 0
        for (int i = 0; i < V; i++) {
            if (outDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            safe.push_back(u);

            for (auto &v : adjRev[u]) {
                outDegree[v]--;
                if (outDegree[v] == 0)
                    q.push(v);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};
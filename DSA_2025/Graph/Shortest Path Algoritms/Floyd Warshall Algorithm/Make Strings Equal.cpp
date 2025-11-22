
// this is wrong solution 
class Solution {
  public:
//   Your Dijkstra is correct but you must run it only ONCE per character, not per position.
// ❗ Since characters are only from 26 lowercase letters, run Floyd–Warshall on 26 nodes.
// ❗ Your mistake: running Dijkstra repeatedly with wrong initial dist and reused graph causes incorrect minimal costs.
  typedef pair<int,char>P;
  int dijkstra(char start, char end,unordered_map<char, vector<P>> &adj) {

    vector<int> dist(128, INT_MAX); // ASCII table size
    priority_queue<P,vector<P>,greater<P>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int cost=pq.top().first;
        char node=pq.top().second;
        pq.pop();

        if(node == end) return cost;

        for(auto &it : adj[node]){
            char adjNode = it.first;
            int wt = it.second;

            if(cost + wt < dist[adjNode]){
                dist[adjNode] = cost + wt;
                pq.push({cost+wt, adjNode});
            }
        }
    }
    return dist[end];
}
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        if(s.size() != t.size()) return -1;

        unordered_map<char,vector<P>>adj;
        int n=cost.size();
        for(int i=0;i<n;i++){
            char u=transform[i][0];
            char v=transform[i][1];
            int wt=cost[i];
            adj[u].push_back({v,wt});
        }
            int total = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != t[i]){
                    int ct = dijkstra(s[i],t[i],adj);
                    if(ct == INT_MAX) return -1; // no path
                    total += ct;
                }
            }
    return total;
    }
};

// ✔ Correct facts about Floyd–Warshall
// 1️⃣ It works for ALL kinds of weights, including:
// positive weights
// zero weights
// negative weights
// (as long as there is no negative cycle)

// 2️⃣ It is used for ALL-PAIRS shortest paths
// Whenever you want:
// min cost from every character to every character
// Floyd–Warshall is the BEST choice.
// ⭐ Why Floyd–Warshall is needed in THIS problem?
// You ask:
// Why can’t I use Dijkstra for each position?
// Because:

// ✔ Dijkstra gives shortest path from ONE start to ALL nodes
// ✔ Floyd–Warshall gives shortest paths from ALL nodes to ALL nodes
// And here:
// Characters are only 26 letters → small graph
// Transformations combine across all characters → you need all pairs shortest paths
// You need cost[x][y] for every possible pair (x,y)
// Using Dijkstra 26 times also works but is more code.
// Floyd–Warshall is simpler:
// 26×26 matrix
// Triple loop
// Very fast (because 26³ = tiny)
// ⭐ Why your Dijkstra approach gives WRONG ANSWER?
// Because you run Dijkstra separately for each position, but:
// ✘ Dijkstra per position does NOT use all intermediate characters
// (except those reachable from s[i] directly through BFS)
// ✔ Floyd–Warshall tries EVERY character as an intermediate
// So it finds MANY more cheap paths that your Dijkstra misses.
// That’s why your answer is 23, but correct is 17.
// ⭐ BIG REASON:
// The graph contains cycles that allow cheaper paths only when using multiple intermediates (like e → c → d → e → c etc.)
// Dijkstra per position = misses these cycles
// Floyd–Warshall = captures ALL intermediate optimizations
// ⭐ Final Answer
// Floyd–Warshall is required — not because of negative weights,
// but because we need ALL-PAIRS shortest paths.



// floyd warshall
// multi source path algorithm
// find shortest distances between every pair of vertices in a given edge-weighted directed graph.

class Solution {
  public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        // code here
        if(s.size()!=t.size())return -1;
        // 26x26 matrix for storing minimum cost from char a->b
        vector<vector<int>> minCost(26, vector<int>(26, INT_MAX));

        // Fill direct transformation cost
        for (int i = 0; i < cost.size(); i++) {
            char u = transform[i][0];
            char v = transform[i][1];
            int wt = cost[i];

            int x = u - 'a';
            int y = v - 'a';

            // Keep the smallest cost
            minCost[x][y] = min(minCost[x][y], wt);
        }
        // src to src cost is always 0
        // cost from a char to itself = 0
        for(int i=0;i<26;i++){
            minCost[i][i]=0;
        }
        
        // Floyd–Warshall: all-pairs shortest path on letters
        for (int via = 0; via < 26; via++) { // n or 26 times relaxations each node
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (minCost[i][via] != INT_MAX && minCost[via][j] != INT_MAX) {
                        minCost[i][j] = min(minCost[i][j], 
                                            minCost[i][via] + minCost[via][j]);
                    }
                }
            }
        }

        int total = 0;
        // Process each position
        for (int idx = 0; idx < s.size(); idx++) {
            int a = s[idx] - 'a';   // character from s
            int b = t[idx] - 'a';   // character from t
            // If both chars are already same → no cost
            if (a == b) continue;
            int best = INT_MAX;
            // Try making both characters equal to some k ('a' to 'z')
            for (int k = 0; k < 26; k++) {
                if (minCost[a][k] != INT_MAX && minCost[b][k] != INT_MAX) {
                    best = min(best, minCost[a][k] + minCost[b][k]);
                }
            }
            // No possible transformation
            if (best == INT_MAX) return -1;
            total += best;
        }
        return total;
    }
};

// ⭐ Does unordered_map Version Work Same As Matrix?
// ✔ YES
// Algorithm remains same.
// Time complexity same: 26³.
// ✔ More readable
// Because you can see relationships as minCost['a']['c'].
// ✔ But slightly slower
// Matrix access is O(1) always.
// unordered_map has hashing overhead.

class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {

        if (s.size() != t.size()) return -1;

        // Step 1: Build adjacency list
        unordered_map<char, vector<pair<char,int>>> adj;

        for (int i = 0; i < cost.size(); i++) {
            char u = transform[i][0];
            char v = transform[i][1];
            int wt = cost[i];
            adj[u].push_back({v, wt});
        }

        // Step 2: Create 26x26 matrix for Floyd–Warshall
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));

        // Self-cost = 0
        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        // Step 3: Fill from adjacency list
        for (char u = 'a'; u <= 'z'; u++) {
            for (auto &p : adj[u]) {
                char v = p.first;
                int wt = p.second;
                dist[u-'a'][v-'a'] = min(dist[u-'a'][v-'a'], wt);
            }
        }

        // Step 4: Floyd–Warshall
        for (int via = 0; via < 26; via++) {
            for (int i = 0; i < 26; i++) {
                if(dist[i][via] == INT_MAX) continue;

                for (int j = 0; j < 26; j++) {
                    if(dist[via][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        // Step 5: Compute total cost
        int total = 0;

        for (int idx = 0; idx < s.size(); idx++) {
            char a = s[idx];
            char b = t[idx];

            if (a == b) continue;

            int best = INT_MAX;

            // convert s[idx] → k and t[idx] → k
            for (int k = 0; k < 26; k++) {
                if (dist[a-'a'][k] != INT_MAX && dist[b-'a'][k] != INT_MAX) {
                    best = min(best, dist[a-'a'][k] + dist[b-'a'][k]);
                }
            }

            if (best == INT_MAX) return -1;

            total += best;
        }

        return total;
    }
};

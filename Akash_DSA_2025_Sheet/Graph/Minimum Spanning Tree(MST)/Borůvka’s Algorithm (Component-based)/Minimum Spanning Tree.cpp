
// ✅ WHAT IS MST? (Minimum Spanning Tree)
// For a connected, undirected, weighted graph:
// 👉 Spanning Tree = A tree that contains all nodes with exactly V−1 edges.
// 👉 Minimum Spanning Tree (MST) = Spanning tree whose total edge weight is minimum.
// MST always has V − 1 edges.
//
// --------------------------------------------------------------
// 3️⃣ BORŮVKA’S ALGORITHM (Component-based MST Algorithm)
// --------------------------------------------------------------
// ✔ Start with each vertex as its own component
// ✔ In every iteration, find the *cheapest edge* for each component
// ✔ Add all cheapest edges to MST simultaneously
// ✔ Components keep merging using DSU
// ✔ Loop continues until we have exactly 1 component
//
// 🔥 Good for: parallel processing, when graph edges are huge
// ⚠️ Not common in competitive programming, but important conceptually
// --------------------------------------------------------------


class DSU{
public:
vector<int>parent;
vector<int>rank;
    DSU(int n){// contructor in used for initiallization not declaration 
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int i){
        if(i==parent[i])return i;
        return parent[i]=find(parent[i]);
    }
    void unionset(int x,int y){ // union ek keyword hai isliye unionset likho 
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent)return;
        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent; // y ko x ka parent 
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent; // x ko y ka parent
        }
        else{
            rank[x_parent]++; // jiska rank badao usko parent bana do dusre ka
            parent[y_parent]=x_parent; // x ko y ka parent
        }
    }
};
// User function Template for C++
class Solution {
  public:
  // ----------------------------------------------------------
    // BORŮVKA MST IMPLEMENTATION
    // ----------------------------------------------------------
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
         DSU dsu(V);
        int components = V;       // initially each vertex is its own component
        int mstSum = 0;           // total weight of MST

        // cheapest[i] will store index of cheapest edge for component i
        vector<int> cheapest(V, -1);

        // Continue until only 1 component is left
        while (components > 1) {

            // Reset cheapest array
            for (int i = 0; i < V; i++) cheapest[i] = -1;

            int m = edges.size();

            // --------------------------------------------------
            // STEP 1: Find cheapest outgoing edge for each component
            // --------------------------------------------------
            for (int i = 0; i < m; i++) {

                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                int set_u = dsu.find(u);
                int set_v = dsu.find(v);

                if (set_u == set_v) continue; // same component → skip

                // cheapest edge for component of u
                if (cheapest[set_u] == -1 ||
                    edges[cheapest[set_u]][2] > w) {
                    cheapest[set_u] = i;
                }

                // cheapest edge for component of v
                if (cheapest[set_v] == -1 ||
                    edges[cheapest[set_v]][2] > w) {
                    cheapest[set_v] = i;
                }
            }

            // --------------------------------------------------
            // STEP 2: Add all cheapest edges to MST simultaneously
            // --------------------------------------------------
            for (int i = 0; i < V; i++) {

                if (cheapest[i] != -1) {

                    int idx = cheapest[i];
                    int u = edges[idx][0];
                    int v = edges[idx][1];
                    int w = edges[idx][2];

                    int set_u = dsu.find(u);
                    int set_v = dsu.find(v);

                    if (set_u == set_v) continue;

                    dsu.unionset(set_u, set_v); // merge components
                    mstSum += w;
                    components--;               // one merge happened
                }
            }
        }

        return mstSum;
    }
};

// ✅ WHAT IS MST? (Minimum Spanning Tree)
// For a connected, undirected, weighted graph:
// 👉 Spanning Tree = A tree that contains all nodes with exactly V−1 edges.
// 👉 Minimum Spanning Tree (MST) = Spanning tree whose total edge weight is minimum.

// MST always has V−1 edges.
// ✅ TYPES OF MST ALGORITHMS
// There are 3 famous MST algorithms:
// 2️⃣ Prim's Algorithm (Node-based method)
// Works on nodes
// Always selects the minimum weight edge from the current MST set
// Uses a min-heap (priority_queue)
// Similar to Dijkstra but chooses edges, not distance
// ➤ When Prim is best?
// ✔ Graph is dense
// ✔ Graph is represented by adjacency list
// ✔ Priority queue makes it very fast
// ✔ Your Prim's code is exactly this:

class Solution {
  public:
  typedef pair<int,int>P;
   // P = {weight, node} OR {adjNode, wt} based on usage
 // PRIM'S ALGORITHM (also called Jarnik's Algorithm)
    // Find MST using a Min-Heap (Priority Queue)
  int prims(int V,unordered_map<int,vector<P>>&adj){
      int sum=0;
      vector<bool>inMst(V,false);
      priority_queue<P,vector<P>,greater<P>>pq;
      // Start with node 0 → weight = 0
      pq.push({0,0});// wt and start node
      while(!pq.empty()){
          int d=pq.top().first;
          int node=pq.top().second;
          pq.pop();
          if(inMst[node])continue;
          inMst[node]=true;
          sum+=d;
          for(auto &it:adj[node]){
              int adjNode=it.first; // graph kaise bana hai vaha se access krte hai
              int wt=it.second;
              if(!inMst[adjNode]){
                  pq.push({wt,adjNode});
              }
          }
      }
      return sum;
  }
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        // Adjacency list → for every u store {v, weight}
        unordered_map<int,vector<P>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // Call Prim's MST Function
        return prims(V,adj);
    }
};

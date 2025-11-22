
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        typedef pair<int,int>P;
        unordered_map<int,vector<P>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int t=edge[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        vector<int>dist(V,INT_MAX);
        priority_queue<P,vector<P>,greater<P>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ngbr:adj[node]){
                int adjNode=ngbr.first; // when graph(adj) make {node,wt} not show pq pair 
                int wt=ngbr.second;
                if(time+wt<dist[adjNode]){
                    dist[adjNode]=time+wt;
                    pq.push({time+wt,adjNode});
                }
            }
        }
        return dist;
    }
};

// ✅ 1. “Is this for 1D matrix?”
// Yes — this is the standard 1D Dijkstra used on:
// Nodes: 0 to V-1
// Edges: edges[i] = {u, v, w}
// So this is graph Dijkstra, not grid/2D.
// ✅ 2. “Can I solve Dijkstra without making a graph?”
// ✔ YES, if the input is already an adjacency list or adjacency matrix
// You do not need to convert edges into a graph again.
// But in your case:
// ❌ The input is edge list, so you MUST build the adjacency list.

class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {

        // dist[i] = shortest distance to vertex i
        // Initialize all vertices with 0 because
        // negative cycle can exist in any component
        vector<long long> dist(V, 0);

        // Relax all edges V-1 times
        for(int i = 1; i < V; i++){
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                // Relax the edge
                if(dist[u] + wt < dist[v]){

                    dist[v] = dist[u] + wt;
                }
            }
        }
        // If we can still relax an edge,
        // then negative weight cycle exists
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u] + wt < dist[v]){
                return true;
            }
        }
        return false;
    }
};

class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
        typedef pair<int,int>P;
        unordered_map<int,vector<P>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ngbr:adj[node]){
                int adjNode=ngbr.first;
                int wt=ngbr.second;
                if(cost+wt < dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    pq.push({cost+wt,adjNode});
                }
            }
        }
        return dist[dest]==INT_MAX ? -1 : dist[dest];
    }
};

class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        // code here
        typedef pair<int,int>P;
        unordered_map<int,vector<P>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<P>pq;
        vector<int>dist(V,INT_MIN);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
           int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ngbr:adj[node]){
                int adjNode=ngbr.first;
                int wt=ngbr.second;
                if(cost+wt > dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    pq.push({cost+wt,adjNode});
                }
            } 
        }
        return dist;
    }
}d
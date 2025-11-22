
class Solution {
  public:
  // 2D array edges[][], where edges[i] = [ui, vi, timei] means that there is an undirected edge between nodes ui and vi that takes timei minutes to reach.
// Your task is to return in how many ways you can travel from node 0 to node V - 1 in the shortest amount of time.
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
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
        vector<int>ways(V,0);
        int src=0,dest=V-1;
        priority_queue<P,vector<P>,greater<P>>pq;
        dist[src]=0;// here src 0
        ways[src]=1;// 0 src and 0 time
        pq.push({0,src});
        while(!pq.empty()){
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &ngbr:adj[node]){
                int adjNode=ngbr.first;
                int wt=ngbr.second;
                if(time+wt<dist[adjNode]){
                    dist[adjNode]=time+wt;
                    pq.push({time+wt,adjNode});
                    ways[adjNode]=ways[node];
                }// dijikstra algorithm slight change
                else if(time + wt==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node]);
                }
            }
        }
        return ways[dest];
    }
};

// ✅ Key Idea: Dijkstra + Ways Array
// For each node:
// dist[node] = shortest distance from source
// ways[node] = number of shortest paths to that node
// When relaxing an edge (u → v) with weight wt:
// ✔ Normal Dijkstra finds shortest distances
// BUT we add a second array:
// ✔ ways[] counts all shortest paths
// Every time we find:
// a new better shortest path → ways[v] = ways[u]
// an equally good shortest path → ways[v] += ways[u]
// This is the ONLY difference from standard Dijkstra.


// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        typedef pair<int,int>P;
int mod=(int)1000000007;
        unordered_map<int,vector<P>>adj;
        for(auto &vec:roads){
            int st=vec[0];
            int ed=vec[1];
            int time=vec[2];
            adj[st].push_back({ed,time});
            adj[ed].push_back({st,time});
        }
        vector<int>dist(n,INT_MAX),ways(n,0);
        int src=0,dest=n-1;
        priority_queue<P,vector<P>,greater<P>>pq;
        dist[src]=0;
        ways[src]=1;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
           if (d > dist[u]) continue;
            for(auto &v:adj[u]){
                int adjnode=v.first;
                int edw=v.second;
                if(d+edw  <  dist[adjnode]){
                    dist[adjnode]=d+edw;
                    pq.push({d+edw,adjnode});
                    ways[adjnode]=ways[u];
                }
                else if(edw + d==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[u])%mod;
                }
            }
        }
        return ways[dest]%mod;
    }
};

class Solution {
public:
typedef pair<int,int>P;
void dfs(int src,int dest,int cost,int &minCost,vector<bool>&visited,unordered_map<int,vector<P>>&adj){
    if(cost>=minCost)return;
    if(src==dest){
       minCost=min(minCost,cost);
       return;
    }
    visited[src]=true;
    for(auto &ngbr:adj[src]){
        if(!visited[ngbr.first] ){
            int wt=ngbr.second;
            dfs(ngbr.first,dest,cost+wt,minCost,visited,adj);
        }
    }
    visited[src]=false;// backtrack explore all paths
}
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>>adj;
        vector<bool>visited(n,false);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        int minCost=INT_MAX;
        dfs(0,n-1,0,minCost,visited,adj);
        return minCost==INT_MAX ? -1: minCost;
    }
};


class Solution {
public:
typedef pair<int,int>P;
int dijikshtra(int src,int n,unordered_map<int,vector<P>>&adj){
    vector<int>dist(n,INT_MAX);
    priority_queue<P,vector<P>,greater<P>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int node=pq.top().second;
        int wt=pq.top().first;
        pq.pop();

        for(auto &ngbr:adj[node]){
            int adjNode=ngbr.first;
            int d=ngbr.second;
            if(d+wt<dist[adjNode]){
                dist[adjNode]=d+wt;
                pq.push({d+wt,adjNode});
            }
        }
    }
    return dist[n-1];// dest=n-1 
}
    int minCost(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<P>>adj;
        vector<bool>visited(n,false);
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,2*wt});
        }
        int minCost=dijikshtra(0,n,adj);;
        return minCost==INT_MAX ? -1 : minCost;
    }
};
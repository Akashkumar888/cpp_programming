
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(vector<int>&edg:edges){
            int u=edg[0];
            int v=edg[1];
            // bidirectional graph 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination) return  true;
            for(auto &v:adj[node]){
                if(!visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
       return false;
    }
};



class Solution {
public:
bool dfs(int u,int dest,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    if(u==dest)return true;
    visited[u]=true;
    for (auto &ngbr : adj[u]) {
        if (!visited[ngbr]) {
            if (dfs(ngbr, dest, visited, adj))return true;   // ✅ only return if path found
        }
    }
    return false;  // ❌ all paths tried, none worked
}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(source,destination,visited,adj);
    }
};
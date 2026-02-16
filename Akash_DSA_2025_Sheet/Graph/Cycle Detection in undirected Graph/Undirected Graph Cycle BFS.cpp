
class Solution {
  public:
  bool checkcycleBFS(int u,vector<bool>&visited,vector<int>adj[]){
      queue<pair<int,int>>q;
      q.push({u,-1});
      visited[u]=true;
      while(!q.empty()){
          int node=q.front().first;
          int parent=q.front().second;
          q.pop();
          for(int&ngbr:adj[node]){
              if(!visited[ngbr]){
                  q.push({ngbr,node});
                  visited[ngbr]=true;
              }
              else if(ngbr!=parent){
                  return true;
              }
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool>visited(V,false);
        vector<int>adj[V];// adjacency list
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<V;i++){
            if(!visited[i] && checkcycleBFS(i,visited,adj))return true;
        }
        return false;
    }
};


class Solution {
  public:
  bool checkcycle(vector<int> adj[],int u,vector<bool>&visited){
      queue<pair<int,int>>q;
      q.push({u,-1});
      visited[u]=true;
      while(!q.empty()){
          int source=q.front().first;
          int p=q.front().second;
          q.pop();
          for(int&v:adj[source]){
              if(visited[v]==false){
                  visited[v]=true;
                  q.push({v,source});
              }
              else if(v!=p){
                  return true;
              }
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && checkcycle(adj,i,visited))return true;
        }
        return false;
    }
};

class Solution {
  public:
    bool checkcycleDFS(int u,int parent,vector<bool>&visited,vector<int>adj[]){
      if(visited[u]==true)return true;
      visited[u]=true;
      for(auto &ngbr: adj[u]){
          if(ngbr==parent)continue;
          if(visited[ngbr]==true)return true;
          else if(checkcycleDFS(ngbr,u,visited,adj))return true;
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
            if(!visited[i] && checkcycleDFS(i,-1,visited,adj))return true;
        }
        return false;
    }
};



class Solution {
  public:
  bool dfs(int u,int parent,vector<bool>&visited,unordered_map<int,vector<int>>&mp){
      visited[u]=true;
      for(auto &v:mp[u]){
          if(v==parent)continue;
          if(visited[v]==true)return true;
          else if(dfs(v,u,visited,mp))return true;
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>mp;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,-1,visited,mp))return true;
            }
        }
        return false;
    }
};
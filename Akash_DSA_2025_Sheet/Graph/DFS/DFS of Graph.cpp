
class Solution {
  public:
  void dfs(int u,vector<int>&visited,vector<vector<int>>&adj,vector<int>&result){
      if(visited[u])return;
      visited[u]=true;
      result.push_back(u);
      for(auto &ngbr:adj[u]){
          if(!visited[ngbr])dfs(ngbr,visited,adj,result);
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V=adj.size();//Given a connected undirected graph containing V vertices represented
        vector<int>visited(V,false);
        vector<int>result;
        dfs(0,visited,adj,result);//Perform a Depth First Search (DFS) traversal starting from vertex 0
        return result;
    }
};
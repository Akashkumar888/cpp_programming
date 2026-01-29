
void dfs(int u,vector<vector<int>>& adj,vector<bool>&visited,vector<int>&ans){
  visited[u]=true;
  ans.push_back(u);
  for(auto &ngbr:adj[u]){
      if(!visited[ngbr]){
          dfs(ngbr,adj,visited,ans);
      }
  }
}
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int n=adj.size();
    vector<bool>visited(n,false);
    vector<int>ans;
    dfs(0,adj,visited,ans);
    return ans;
}


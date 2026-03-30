
class Solution {
  public:
  int timer=1;
    void dfs(int u,int parent,vector<bool>&visited,vector<int>&tin,vector<int>&low,vector<int>&mark,vector<int>adj[]) {
        visited[u]=true;
        tin[u]=low[u]=timer++;
        int child=0;
        for(auto &v:adj[u]){
            if(v==parent)continue;  
            if(!visited[v]){
                dfs(v,u,visited,tin,low,mark,adj);
                low[u]=min(low[v],low[u]);
                if(low[v]>=tin[u]&&parent!=-1){  
                    mark[u]=1;
                }
                child++;
            } 
            else{
                low[u]=min(low[u],tin[v]);
            }
        }
        if(child>1&&parent==-1){
            mark[u]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>mark(V,0);
        vector<bool>visited(V,false);
        vector<int>tin(V);
        vector<int>low(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,-1,visited,tin,low,mark,adj);
            }
        }
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1){
                ans.push_back(i);
            }
        }
        if(ans.empty())return {-1};
        return ans;
    }
};
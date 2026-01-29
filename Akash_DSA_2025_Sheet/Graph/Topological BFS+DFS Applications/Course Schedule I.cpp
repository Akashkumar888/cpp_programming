
class Solution {
  public:
  // cycleDetection in directed graph dfs
  bool dfs(int u,vector<bool>&inRec,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
      visited[u]=true;
      inRec[u]=true;
      for(auto &v:adj[u]){
          if(!visited[v] && dfs(v,inRec,visited,adj))return true;
          else if(inRec[v])return true;
      }
      inRec[u]=false;
      return false;
  }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        unordered_map<int,vector<int>>adj;
    // prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.
    // Find the ordering of courses we should take to complete all the courses.
        for(auto &edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        vector<bool>inRec(n,false);
        for(int i=0;i<n;i++){
        if(!visited[i] && dfs(i,inRec,visited,adj)) return false;
            // cylce hai
        }
        return true;
    }
};


class Solution {
  public:
      // cycleDetection in directed graph bfs
    void topoBFS(int n,unordered_map<int,vector<int>>&graph,vector<int>&ans){
        vector<int>indegree(n,0);
        queue<int>q;
        for(int u=0;u<n;u++){
           for(int &v:graph[u]){
            indegree[v]++;
           }
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }  
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int &v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
 }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        unordered_map<int,vector<int>>adj;
    // prerequisites[][] where prerequisites[i] = [x, y] indicates that we need to take course  y first if we want to take course x.
    // Find the ordering of courses we should take to complete all the courses.
        for(auto &edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
        }
        vector<int>ans;
        topoBFS(n,adj,ans);
        if(ans.size()!=n) return false;
        return true;
    }
};
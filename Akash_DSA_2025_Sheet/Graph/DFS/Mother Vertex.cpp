
class Solution {
  public:
  void dfs(int &count,int u,vector<bool>&visited,vector<int>adj[]){
      if(visited[u])return ;
      visited[u]=true;
      count++;
      for(auto &ngbr:adj[u]){
          if(!visited[ngbr]){
              dfs(count,ngbr,visited,adj);
          }
      }
  }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        for(int v=0;v<V;v++){
        vector<bool>visited(V,false);
            int start=0;
            dfs(start,v,visited,adj);
            if(start==V)return v;
        }
        return -1;
    }
};


class Solution {
  public:
  void bfs(int &count,int u,vector<bool>&visited,vector<int>adj[]){
      queue<int>q;
      q.push(u);//Perform a Breadth First Search (BFS) traversal starting from vertex 0
        visited[u]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto &ngbr:adj[node]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
        }
  }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        for(int v=0;v<V;v++){
        vector<bool>visited(V,false);
            int start=0;
            bfs(start,v,visited,adj);
            if(start==V)return v;
        }
        return -1;
    }
};

// Key Idea

// If a mother vertex exists,
// then the last finished vertex in DFS is always a mother vertex candidate.

// Steps
// Run DFS for all vertices
// Store last finished vertex
// Run DFS again from that vertex
// If all nodes visited → answer
// Else → no mother vertex

class Solution {
  public:
  void dfs(int &count,int u,vector<bool>&visited,vector<int>adj[]){
      if(visited[u])return ;
      visited[u]=true;
      count++;
      for(auto &ngbr:adj[u]){
          if(!visited[ngbr]){
              dfs(count,ngbr,visited,adj);
          }
      }
  }
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        vector<bool>visited(V,false);
        int lastFinishedVertex=0;
        for(int v=0;v<V;v++){
            if(!visited[v]) {
                int count = 0;
                dfs(count,v,visited,adj);

                // last started DFS vertex
                lastFinishedVertex = v;
            }
        }
        fill(visited.begin(),visited.end(),false);

        int count = 0;
        dfs(count,lastFinishedVertex,visited,adj);

        if(count == V) return lastFinishedVertex;
        
        return -1;
    }
};
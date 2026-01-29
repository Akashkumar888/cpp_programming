
class DSU {
  public:
      vector<int> parent, rank;
  
      DSU(int n) {
          parent.resize(n);
          rank.resize(n, 0);
          for (int i = 0; i < n; i++) parent[i] = i;
      }
  
      int find(int i) {
          if (i == parent[i]) return i;
          return parent[i] = find(parent[i]); // Path compression
      }
  
      void unionset(int x, int y) {
          int x_parent = find(x);
          int y_parent = find(y);
          if (x_parent == y_parent) return;
  
          // Union by rank
          if (rank[x_parent] > rank[y_parent]) {
              parent[y_parent] = x_parent;
          } else if (rank[x_parent] < rank[y_parent]) {
              parent[x_parent] = y_parent;
          } else {
              parent[x_parent] = y_parent;
              rank[y_parent]++;
          }
      }
  };
  class Solution {
    public:
        bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
            DSU dsu(V);
    
            // Create DSU ignoring the edge (c, d)
            for (auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                if ((u == c && v == d) || (u == d && v == c)) continue; // remove c-d edge
                dsu.unionset(u, v); // union the rest
            }
    
            int c_parent = dsu.find(c);
            int d_parent = dsu.find(d);
    
            // If c and d are in different components now, it was a bridge
            return c_parent == d_parent ? false : true;
        }
    };
      




    //Approach -ii 

    void dfs(int u,unordered_map<int,vector<int>>&adj,vector<bool>&visited,int c,int d){
        visited[u]=true;
        for(auto &ngbr:adj[u]){
            if(!visited[ngbr] && !(u==c && ngbr==d)){
                dfs(ngbr,adj,visited,c,d);
            }
        }
    }
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          unordered_map<int,vector<int>>adj;
          for(auto &edge:edges){
             int u=edge[0];
             int v=edge[1];
             adj[u].push_back(v);
             adj[v].push_back(u);
          }
          vector<bool>visited(V,false);
          dfs(c,adj,visited,c,d);
          if(visited[d]==true)return false;
          return true;
      }

      
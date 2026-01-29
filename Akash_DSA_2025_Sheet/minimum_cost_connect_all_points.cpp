
class DSU {
  public:
      vector<int> parent, rank;
      DSU(int n) {
          parent.resize(n);
          rank.resize(n, 0);
          for (int i = 0; i < n; ++i) parent[i] = i;
      }
  
      int find(int i) {
          if (i == parent[i]) return i;
          return parent[i] = find(parent[i]);
      }
  
      void unionset(int x, int y) {
          int x_parent = find(x), y_parent = find(y);
          if (x_parent == y_parent) return;
          if (rank[x_parent] > rank[y_parent])
              parent[y_parent] = x_parent;
          else if (rank[x_parent] < rank[y_parent])
              parent[x_parent] = y_parent;
          else {
              parent[x_parent] = y_parent;
              rank[y_parent]++;
          }
      }
  };
  
  class Solution {
  public:
      int kruskal(int V, vector<vector<int>>& edges) {
          DSU dsu(V);
          int cost = 0;
          for (auto& edge : edges) {
              int u = edge[0], v = edge[1], w = edge[2];
              if (dsu.find(u) != dsu.find(v)) {
                  dsu.unionset(u, v);
                  cost += w;
              }
          }
          return cost;
      }
  
      int minCost(vector<vector<int>>& houses) {
          int V = houses.size();
          vector<vector<int>> edges;
          for (int i = 0; i < V; ++i) {
              for (int j = i + 1; j < V; ++j) {
                  int dist = abs(houses[i][0] - houses[j][0]) + abs(houses[i][1] - houses[j][1]);
                  edges.push_back({i, j, dist});
              }
          }
  
          sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
              return a[2] < b[2];
          });
  
          return kruskal(V, edges);
      }
  };
  
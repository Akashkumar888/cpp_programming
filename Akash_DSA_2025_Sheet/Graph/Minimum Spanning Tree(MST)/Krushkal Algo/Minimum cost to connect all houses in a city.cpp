
// connect krna hai to dsu use krte hai 
class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DSU(int n) { // contructor in used for data members initiallization not declaration 
        parent.resize(n);
        size.resize(n, 1);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    // -------- UNION BY SIZE --------
    void unionsetBySize(int x, int y) { // union ek keyword hai isliye unionset likho 
        int x_parent=find(x);
        int y_parent=find(y);
        if (x_parent == y_parent) return;

        if (size[x_parent] < size[y_parent]) {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        } 
        else {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
    }
    // -------- UNION BY RANK --------
    void unionsetByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent) return;
        if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;// y ko x ka parent 
        }
        else if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;// x ko y ka parent
        }
        else {
            parent[y_parent] = x_parent; // x ko y ka parent
            rank[x_parent]++;   // jiska rank badao usko parent bana do dusre ka
        }
    }
};
class Solution {
  public:
  int kruskal(int V,vector<vector<int>>&adj){
      DSU dsu(V);
      int minCost=0;
      for(auto &vec:adj){
          int u=vec[0];
          int v=vec[1];
          int wt=vec[2];
          int u_parent=dsu.find(u);
          int v_parent=dsu.find(v);
          if(u_parent==v_parent)continue;
          dsu.unionsetByRank(u,v);
          minCost+=wt;
      }
      return minCost;
  }
    int minCost(vector<vector<int>>& houses) {
        // code here
        int V=houses.size();
        vector<vector<int>>adj;
        for(int i=0;i<V;i++){
            int x1=houses[i][0];
            int y1=houses[i][1];
            for(int j=i+1;j<V;j++){
                int x2=houses[j][0];
                int y2=houses[j][1];
                int dist=abs(x1-x2) + abs(y1-y2);
                adj.push_back({i,j,dist});
                adj.push_back({j,i,dist});
            }
        }
        auto lambda=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2];
        };
        sort(adj.begin(),adj.end(),lambda);
        return kruskal(V,adj);
    }
};


//Prims Algorithm

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int V=houses.size();
        typedef pair<int,int>P;
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<bool>visited(V,false);
        int minCost=0;
        pq.push({0,0});
        while(!pq.empty()){
            int wt=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(visited[u])continue;
            visited[u]=true;
            minCost+=wt;
            for(int v=0;v<V;v++){
                if(!visited[v]){
                    int dist=abs(houses[u][0]-houses[v][0]) + abs(houses[u][1]-houses[v][1]);
                    pq.push({dist,v});
                }
            }
        }
        return minCost;
    }
};
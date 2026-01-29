class DSU{
public:
vector<int>parent;
vector<int>rank;
    DSU(int n){// contructor in used for initiallization not declaration 
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int find(int i){
        if(i==parent[i])return i;
        return parent[i]=find(parent[i]);
    }
    void unionset(int x,int y){ // union ek keyword hai isliye unionset likho 
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent==y_parent)return;
        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent; // y ko x ka parent 
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent; // x ko y ka parent
        }
        else{
            rank[x_parent]++; // jiska rank badao usko parent bana do dusre ka
            parent[y_parent]=x_parent; // x ko y ka parent
        }
    }
};
// User function Template for C++
class Solution {
  public:
  int kruskal(int V,vector<vector<int>> &edges){
      DSU dsu(V);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
      int sum=0;
      int used=0;
      for(auto &temp:edges){
          int u=temp[0];
          int v=temp[1];
          int wt=temp[2];
          int u_parent=dsu.find(u);
          int v_parent=dsu.find(v);
          if(u_parent!=v_parent){
              dsu.unionset(u,v);
              sum+=wt;
              used++;
          }
      }
      // If MST does not contain V - 1 edges → graph disconnected
      if (used != V - 1) return -1;
      return sum;
  }
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        auto cmp=[&](vector<int>&v1,vector<int>&v2){
            return v1[2]<v2[2]; // sort by weight
        };
        sort(edges.begin(),edges.end(),cmp);
        return kruskal(V,edges);
    }
};


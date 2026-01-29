
class DSU {
public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DSU(int n) { // contructor in used for initiallization not declaration 
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
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(V);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        for(int u=0;u<V;u++){
            for(auto &v:adj[u]){
                if(u<v){
                    int u_parent=dsu.find(u);
                    int v_parent=dsu.find(v);
                    if(u_parent==v_parent)return true;
                    dsu.unionsetByRank(u,v);
                }
            }
        }
        return false;
    }
};
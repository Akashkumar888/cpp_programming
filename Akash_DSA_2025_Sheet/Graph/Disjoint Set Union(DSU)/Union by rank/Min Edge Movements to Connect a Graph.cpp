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
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(n);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        int extraEdges=0;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)==dsu.find(v)){
                extraEdges++;
            }
            else dsu.unionsetBySize(u,v);
        }
        int countComp=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i)countComp++;
        }
        int ans=countComp-1;
        if(extraEdges>=ans)return ans;
        return -1;
    }
};



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
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        // code here
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(n);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        int extraEdges=0;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)==dsu.find(v)){
                extraEdges++;
            }
            else dsu.unionsetByRank(u,v);
        }
        int countComp=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i)countComp++;
        }
        int ans=countComp-1;
        if(extraEdges>=ans)return ans;
        return -1;
    }
};
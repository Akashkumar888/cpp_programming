
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
// In one operation, you are allowed to remove any existing link and reconnect it between two hospitals that are currently not directly or indirectly connected.
// Your task is to determine the minimum number of operations required to make sure that all hospitals become connected, either directly or indirectly, using the given links.
class Solution {
  public:
    int minConnect(int V, vector<vector<int>>& edges) {
        // Code here
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(V);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        int extraEdges=0;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)==dsu.find(v)){
                extraEdges++;
            }
            else dsu.unionset(u,v);
        }
        int countComp=0;
        for(int i=0;i<V;i++){
            if(dsu.parent[i]==i)countComp++;
        }
        int ans=countComp-1;
        if(extraEdges>=ans)return ans;
        return -1;
    }
};

// Connecting the graph - gfg 
// Number of Operations to Make Network Connected - leetcode
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
// In one operation, you are allowed to remove any existing link and reconnect it between two hospitals that are currently not directly or indirectly connected.
// Your task is to determine the minimum number of operations required to make sure that all hospitals become connected, either directly or indirectly, using the given links.
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Code here
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(n);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        int extraEdges=0;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];
            if(dsu.find(u)==dsu.find(v)){
                extraEdges++;
            }
            else dsu.unionset(u,v);
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
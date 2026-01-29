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
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        // Code here
        int n=stones.size();
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(n);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        // No two stones are at same position.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                // If they share same row or same column
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) 
                {
                    dsu.unionset(i, j);   // ✔ union stone indices, not coordinates
                }
            }
        }
        int group=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i) group++;
        }
        return n-group;
    }
};


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
// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // Code here
        int n=stones.size();
        //jb bhi dynamic connection required or Components ki baat ho to dsu ko use karo
        DSU dsu(n);// when object creates contrutor is called and here contructor need one parameter it is parameterised contructor
        // No two stones are at same position.
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    dsu.unionset(i,j);
                }
            }
        }
        int group=0;
        for(int i=0;i<n;i++){
            if(dsu.parent[i]==i) group++;
        }
        return n-group;
    }
};
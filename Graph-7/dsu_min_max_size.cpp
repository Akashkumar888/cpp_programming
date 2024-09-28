

#include<iostream>
#include<vector>
using namespace std;
int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i],parent);
}
void unionset(int x,int y,vector<int>&rank,vector<int>&parent,vector<int>&sz,vector<int>&maximal,vector<int>&minimal){
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);
    if(x_parent==y_parent)return ;
    if(rank[x_parent]<rank[y_parent]){
        rank[x_parent]=y_parent;
        sz[y]+=sz[x];
        maximal[y]=max(maximal[x],maximal[y]);
        minimal[y]=min(minimal[x],minimal[y]);
    }
    else if(rank[x_parent]>rank[y_parent]){
        rank[y_parent]=x_parent;
        sz[x]+=sz[y];
        maximal[x]=max(maximal[x],maximal[y]);
        minimal[x]=min(minimal[x],minimal[y]);
    }
    else{
        rank[x_parent]=y_parent;
        rank[y_parent]++;

        sz[x]+=sz[y];
        maximal[x]=max(maximal[x],maximal[y]);
        minimal[x]=min(minimal[x],minimal[y]);
    }
    // else{
    //     rank[y_parent]=x_parent;
    //     rank[x_parent]++;
    // }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    vector<int>sz(n+1,1);
    vector<int>minimal(n+1);
    vector<int>maximal(n+1);

    for(int i=0;i<=n;i++){
        parent[i]=maximal[i]=minimal[i]=i;
    }

    while(m--){
        string str;
        cin>>str;
        if(str=="unionset"){
            int x,y;
            cin>>x>>y;
            unionset(x,y,rank,parent,sz,maximal,minimal);
        }
        else{
            int x;
            cin>>x;
            x=find(x,parent);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<sz[x]<<endl;
        }
    }
return 0;
}

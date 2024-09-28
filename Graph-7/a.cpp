
#include<iostream>
#include<vector>
using namespace std;
int find(int i,vector<int>&parent){
    if(i==parent[i]) return i;
    return parent[i]=find(parent[i],parent);
}
void unionset(int x,int y,vector<int>&rank,vector<int>&parent){
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);
    if(x_parent==y_parent)return ;
    if(rank[x_parent]<rank[y_parent]){
        rank[x_parent]=y_parent;
    }
    else if(rank[x_parent]>rank[y_parent]){
        rank[y_parent]=x_parent;
    }
    else{
        rank[x_parent]=y_parent;
        rank[y_parent]++;
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
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="unionset"){
            int x,y;
            cin>>x>>y;
            unionset(x,y,rank,parent);
        }
        else{
            int x;
            cin>>x;
            cout<<find(x,parent)<<endl;
        }
    }
return 0;
}
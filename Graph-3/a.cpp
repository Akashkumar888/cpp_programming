
#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>>graph;
int v;
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void dfs(int u,vector<bool>&visited){
    if(visited[u]==true)return;
    visited[u]=true;
    for(auto &v:graph[u]){
        if(!visited[v]){
            dfs(v,visited);
        }
    }
}
int connected_components(){
    vector<bool>visited(v,false);
    int count=0;
    for(int i=0;i<v;i++){
        if(!visited[i]){
        count++;
        dfs(i,visited);
        }
    }
    return count;
}
int main()
{
cin>>v;
graph.resize(v,list<int>());
int e;
cin>>e;
while(e--){
    int s,d;
    cin>>s>>d;
    add_edge(s,d);
}
cout<<connected_components()<<endl;
return 0;
}
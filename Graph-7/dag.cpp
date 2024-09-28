#include<bits/stdc++.h>
using namespace std;

vector<list<int>>graph;
int v;
void add_edge(int a,int b,bool bidir=true){
    graph[a].push_back(b);
    if(bidir){
        graph[b].push_back(a);
    }
}
void topoBFS(vector<int>&ans){
vector<int>indegree(v,0);
    queue<int>q;
    for(int u=0;u<v;u++){
       for(int &l:graph[u]){
        indegree[l]++;
       }
    }

for(int i=0;i<v;i++){
    if(indegree[i]==0) q.push(i);
}  
while(!q.empty()){
    int u=q.front();
    q.pop();
    ans.push_back(u);
    for(int &l:graph[u]){
        indegree[l]--;
        if(indegree[l]==0){
            q.push(l);
        }
    }
}
}
int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v,list<int>());
    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    vector<int>ans;
    topoBFS(ans);
    for(int i=0;i<v;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

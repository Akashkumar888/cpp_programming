


#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
int v;
vector<vector<int>>result;
void add_edge(int src,int dest,bool bi_dir=true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto &el:graph[i]){
           cout<<el<<" , ";
        }
        cout<<endl;
    }
}
void BFS(int src,int dest,vector<int>&dist){
queue<int>q;
visited.clear();
dist.resize(v,INT_MAX);
dist[src]=0;
visited.insert(src);
q.push(src);
while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    for(auto &neighbour:graph[curr]){
        if(!visited.count(neighbour)){
        q.push(neighbour);
        visited.insert(neighbour);
        dist[neighbour]=dist[curr]+1;
        }
    }
}
cout<<endl;
}
int main()
{
cin>>v;
graph.resize(v,list<int>());
int e;
cin>>e;
visited.clear();
while(e--){
    int s,d;
    cin>>s>>d;
    add_edge(s,d);
}
// display();
vector<int>dist;
int x,y;
cin>>x>>y;
BFS(x,y,dist);
for(int i=0;i<dist.size();i++){
    cout<<dist[i]<<" ";
}
return 0;
}

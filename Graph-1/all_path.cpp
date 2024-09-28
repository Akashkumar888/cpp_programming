

#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
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
void dfs(int curr,int end,vector<int>&path){
    if(curr==end){
    path.push_back(curr);
    result.push_back(path);
    path.pop_back();
    return ;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(auto &neighbour:graph[curr]){
        if(!visited.count(neighbour)){
            dfs(neighbour,end,path);
        
        }
    }
    visited.erase(curr);
    path.pop_back();
    return ;
}
void all_path(int src,int dest){
    vector<int>v;
     dfs(src,dest,v);
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
display();
int x,y;
cin>>x>>y;
all_path(x,y);
for(auto &path:result){
   for(int &el:path){
    cout<<el<<" ";
   }
   cout<<endl;
}
return 0;
}

// User function Template for C++

class Solution {
  public:
  void dfs(int u,vector<int>&visited,vector<int>graph[]){
      if(visited[u])return;
      visited[u]=true;
      for(auto &ngbr :graph[u]){
        if(!visited[ngbr]) dfs(ngbr,visited,graph);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        int m=adj.size();
        int n=adj[0].size();
        vector<int>visited(V,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,graph);
                count++;
            }
        }
        return count;
    }
};


// User function Template for C++

class Solution {
  public:
  void bfs(int u,vector<int>&visited,vector<int>graph[]){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto &ngbr:graph[node]){
            if(!visited[ngbr]){
                q.push(ngbr);
                visited[ngbr]=true;
            }
        }
    }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>graph[V];
        int m=adj.size();
        int n=adj[0].size();
        vector<int>visited(V,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,visited,graph);
                count++;
            }
        }
        return count;
    }
};

// User function Template for C++

class Solution {
  public:
  void dfs(int V,int u,vector<int>&visited,vector<vector<int>>&adj){
    if(visited[u])return;
      visited[u]=true;
      for(int ngbr=0;ngbr<V;ngbr++){
         if(!visited[ngbr] && adj[u][ngbr]==1 )dfs(V,ngbr,visited,adj);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(V,i,visited,adj);
                count++;
            }
        }
        return count;
    }
};


// User function Template for C++

class Solution {
  public:
  void bfs(int V,int u,vector<int>&visited,vector<vector<int>>&adj){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int ngbr=0;ngbr<V;ngbr++){
            if(!visited[ngbr] && adj[node][ngbr]==1){
                q.push(ngbr);
                visited[ngbr]=true;
            }
        }
    }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>visited(V,false);
        int count=0;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(V,i,visited,adj);
                count++;
            }
        }
        return count;
    }
};


class Solution {
public:
void dfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    if(visited[u])return;
    visited[u]=true;
    for(auto &v:adj[u]){
        if(!visited[v]){
            dfs(v,visited,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};


class Solution {
public:
int n;
void dfs(int u,vector<bool>&visited,vector<vector<int>>& isConnected){
    if(visited[u])return;
    visited[u]=true;
    for(int v=0;v<n;v++){
        if(!visited[v] && isConnected[u][v]==1){//isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected
            dfs(v,visited,isConnected);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};




class Solution {
public:
void bfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(auto &ngbr:adj[v]){
            if(!visited[ngbr]){
                q.push(ngbr);
                visited[ngbr]=true;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,adj);
                count++;
            }
        }
        return count;
    }
};

class Solution {
public:
int n;
void bfs(int u,vector<bool>&visited,vector<vector<int>>& isConnected){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int ngbr=0;ngbr<n;ngbr++){
            if(!visited[ngbr] && isConnected[v][ngbr]){
                q.push(ngbr);
                visited[ngbr]=true;
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};
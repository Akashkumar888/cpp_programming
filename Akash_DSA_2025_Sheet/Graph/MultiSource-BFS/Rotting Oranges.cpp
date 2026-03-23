
// bfs ke two template 
// 🔥 BFS Templates — When to Use Which?

// There are mainly 3 practical BFS patterns used in industry + DSA:

// ✅ 1️⃣ Normal BFS (Single Loop Template)
// while(!q.empty()){
//     auto node = q.front();
//     q.pop();
// }

// 📌 When to use?
// When you don’t care about levels
// When you just need:
// Traversal
// Reachability
// Visited marking
// 🔹 Example Problems:
// Graph traversal
// Connected components
// Checking cycle in undirected graph
// Flood fill (without time tracking)

// ✅ 2️⃣ Level Order BFS (Two Loop Template)
// while(!q.empty()){
//     int sz = q.size();
//     for(int i=0;i<sz;i++){
//         auto node = q.front();
//         q.pop();
//     }
// }
// 📌 When to use?
// When level matters.
// 👉 Each loop = 1 level = 1 minute / 1 distance step
// 🔥 Use this when:
// You need minimum distance
// You need time taken
// You need multi-source BFS
// Binary tree level order traversal
// 🔹 Example Problems:
// Rotting Oranges 🍊
// Word Ladder
// Shortest Path in Unweighted Graph
// Binary Tree Level Order

// ✅ 3️⃣ BFS with Time Stored in Queue
// queue<pair<pair<int,int>,int>> q; 
// // {{i,j}, time}
// 📌 When to use?
// When:
// Time per node can differ
// You don’t want level loop
// Cleaner implementation
// This avoids:
// int sz = q.size();
// Instead you push:
// q.push({{ni,nj}, t+1});
// 🔥 Used in:
// Grid problems
// Spread problems
// Shortest path with equal weight edges





class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        
        // multiSourceBfs me two loops like binary tree every level traversal 
        // Step 2: BFS level by level
        while(!q.empty() && fresh > 0){
        
            int sz = q.size();  // current level size

            for(int s=0; s<sz; s++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];

                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        fresh--;
                    }
                }
            }
            minutes++;  // increase AFTER processing one level
        }
        if(fresh > 0) return -1;
        return minutes;
    }
};




class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        // Step 1: Push all rotten oranges
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        
        // multiSourceBfs me two loops like binary tree every level traversal 
        // Step 2: BFS level by level
        while(!q.empty() && fresh > 0){
        
            int sz = q.size();  // current level size

            for(int s=0; s<sz; s++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                for(int k=0;k<4;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];

                    if(ni>=0 && ni<m && nj>=0 && nj<n && !visited[ni][nj] && grid[ni][nj]==1){
                        q.push({ni,nj});
                        visited[ni][nj]=true;
                        fresh--;
                    }
                }
            }
            minutes++;  // increase AFTER processing one level
        }
        if(fresh > 0) return -1;
        return minutes;
    }
};


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
       //int vis[m][n];
       vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
                // else{
                //     vis[i][j]=true;
                // }
            }
        }
        int tm=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];

            if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==1 && !vis[new_i][new_j]){
            q.push({{new_i,new_j},t+1});
            vis[new_i][new_j]=true;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( !vis[i][j] && grid[i][j]==1)return -1;
            }
        }
        return tm;  
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
       int vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(auto &dir:directions){
                int new_i=i+dir[0];
                int new_j=j+dir[1];
                if(new_i>=0 && new_i<m&&new_j>=0&&new_j<n&& vis[new_i][new_j]!=2 && grid[new_i][new_j]==1 && grid[new_i][new_j]!=0){
            q.push({{new_i,new_j},t+1});
            vis[new_i][new_j]=2;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)return -1;
            }
        }
        return tm;  
    }
};


class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1},{0,-1},{-1,0}};
typedef pair<int,pair<int,int>>P;
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<P,vector<P>,greater<P>>pq;//queue aur  min heap se bhi ho jayega 

        // multisource bfs here use ok 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    pq.push({0,{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        int time=0;
    while(!pq.empty()){
        int tm=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        time=max(tm,time);
        pq.pop();
        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j]==1 && !visited[new_i][new_j]){
        pq.push({tm+1,{new_i,new_j}});
        visited[new_i][new_j]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && visited[i][j]==false)return -1;
        }
    }
    return time;
    }
};



class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1},{0,-1},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<pair<int,int>>visited;
        queue<pair<pair<int,int>,int>>q;
        // multisource bfs here use ok 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited.insert({i,j});
                }
            }
        }
        int time=0;
    while(!q.empty()){
        int i=q.front().first.first;
        int j=q.front().first.second;
        int tm=q.front().second;
        time=max(tm,time);
        q.pop();
        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i>=0 && new_i<m&&new_j>=0&&new_j<n&&grid[new_i][new_j]==1 && visited.find({new_i,new_j})==visited.end()){
        q.push({{new_i,new_j},tm+1});
        visited.insert({new_i,new_j});
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && visited.find({i,j})==visited.end())return -1;
        }
    }
    return time;
    }
};

class Solution {
  public:
  int dx[4]={1,0,-1,0};
  int dy[4]={0,1,0,-1};
  typedef pair<int,pair<int,int>>P;
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int count=0;
        int m=mat.size();
        int n=mat[0].size();
        queue<P>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==2){
                    q.push({0,{i,j}});// muti-souce bfs
                    visited[i][j]=true;
                }
            }
        }
        // muti-souce bfs
        int maxTime=0;
        while(!q.empty()){
            int tm=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            maxTime=max(maxTime,tm);
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] && mat[nx][ny]!=0){
                    q.push({tm+1,{nx,ny}});
                    visited[nx][ny]=true;
                    count++;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && mat[i][j]==1)return -1;
            }
        }
        return maxTime;
    }
};
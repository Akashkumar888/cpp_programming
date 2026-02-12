
class Solution {
public:
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
  void dfs(int i,int j,int m,int n,vector<vector<bool>>&visited,vector<vector<char>>& grid){
      if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')return;
      if(visited[i][j])return;
      visited[i][j]=true;
      for(int k=0;k<4;k++){
          int nx=i+dx[k];
          int ny=j+dy[k];
          dfs(nx,ny,m,n,visited,grid);
      }
  }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j] ){
                    dfs(i,j,m,n,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};



class Solution {
  public:
  //connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
  int dx[8]={1,0,-1,0,-1,-1,1,1};
  int dy[8]={0,1,0,-1,-1,1,1,-1};
  void dfs(int i,int j,int n,int m,vector<vector<bool>>&visited,vector<vector<char>>& grid){
      if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='W')return;
      if(visited[i][j])return;
      visited[i][j]=true;
      for(int k=0;k<8;k++){
          int nx=i+dx[k];
          int ny=j+dy[k];
          dfs(nx,ny,n,m,visited,grid);
      }
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !visited[i][j] ){
                    dfs(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};


class Solution {
public:
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
  void bfs(int i,int j,int m,int n,vector<vector<bool>>&visited,vector<vector<char>>& grid){
      queue<pair<int,int>>q;
      q.push({i,j});
      visited[i][j]=true;
      while(!q.empty()){
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int k=0;k<4;k++){
              int nx=x+dx[k];
              int ny=y+dy[k];
                // ✅ Boundary check added
            if(nx >= 0 && ny >= 0 && nx < m && ny < n) {
              if(!visited[nx][ny] && grid[nx][ny]=='1'){
                  q.push({nx,ny});
                  visited[nx][ny]=true;
              }
          }
         }
      }
  }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j] ){
                    bfs(i,j,m,n,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};





class Solution {
  public:
  //connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.
  int dx[8]={1,0,-1,0,-1,-1,1,1};
  int dy[8]={0,1,0,-1,-1,1,1,-1};
  void bfs(int i,int j,int n,int m,vector<vector<bool>>&visited,vector<vector<char>>& grid){
      queue<pair<int,int>>q;
      q.push({i,j});
      visited[i][j]=true;
      while(!q.empty()){
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          for(int k=0;k<8;k++){
              int nx=x+dx[k];
              int ny=y+dy[k];
                // ✅ Boundary check added
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
              if(!visited[nx][ny] && grid[nx][ny]=='L'){
                  q.push({nx,ny});
                  visited[nx][ny]=true;
              }
          }
         }
      }
  }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='L' && !visited[i][j] ){
                    bfs(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
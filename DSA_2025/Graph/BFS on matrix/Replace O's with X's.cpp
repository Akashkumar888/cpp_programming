
class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
      // 4 directions (UP, RIGHT, DOWN, LEFT)
      int dx[4]={1,0,-1,0};
      int dy[4]={0,-1,0,1};
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        //You have to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
        // surrounded by 'X'. that's why we start from i=1 and j=1 
        // jisme graph nh banana pade unordered_map se vo bfs dfs on matrix me rahega 
        // jisme banana pade vo bfs dfs rahega with graph 
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        // 1️⃣ Push all boundary 'O' into queue
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') { q.push({i,0}); visited[i][0] = true; }
            if (grid[i][m-1] == 'O') { q.push({i,m-1}); visited[i][m-1] = true; }
        }

        for (int j = 0; j < m; j++) {   // ✅ fixed: j < m
            if (grid[0][j] == 'O') { q.push({0,j}); visited[0][j] = true; }
            if (grid[n-1][j] == 'O') { q.push({n-1,j}); visited[n-1][j] = true; }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]=='O'){
                    q.push({nx,ny});
                    visited[nx][ny]=true;
                }
            }
        }
        // 3️⃣ Convert unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'O' && !visited[i][j]) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
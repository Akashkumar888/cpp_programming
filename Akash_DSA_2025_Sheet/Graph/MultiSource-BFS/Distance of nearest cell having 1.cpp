
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
// bfs use minimum distance from grid[i][j] to the nearest cell having value 1.
// distance between two cells (i1, j1)  and (i2, j2) is calculated as |i1 - i2| + |j1 - j2|.
        typedef pair<int,pair<int,int>>P;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1}; 
        queue<P>q;
        // Push all 1-cells as BFS sources
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        // BFS traversal
        while(!q.empty()){
            int d=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            result[x][y]=d;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny]){
                    q.push({d+1,{nx,ny}});
                    visited[nx][ny]=true;
                }
            }
        }
        return result;
    }
};
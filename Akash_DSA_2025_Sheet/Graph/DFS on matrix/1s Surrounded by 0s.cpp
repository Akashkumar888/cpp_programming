
class Solution {
  public:
  vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};
    void dfs(int i,int j,int m,int n,vector<vector<int>>&grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            dfs(new_i,new_j,m,n,grid);
        }
    }
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){// first column and all rows
            if(grid[i][0]==1) {
                dfs(i,0,m,n,grid);
            }
            if(grid[i][n-1]==1) { // last column and all rows
                dfs(i,n-1,m,n,grid);
            }
        }
        for(int j=1;j<n-1;j++){// all column and first rows
            if(grid[0][j]==1) {
                dfs(0,j,m,n,grid);
            }
            if(grid[m-1][j]==1) {// all column and last rows
                dfs(m-1,j,m,n,grid);
            }
        }
        int ones=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)ones++;
            }
        }
        return ones;

    }
};

class Solution {
  public:

    vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};

    void bfs(int i,int j,int m,int n,
             vector<vector<int>>&grid){

        queue<pair<int,int>>q;

        q.push({i,j});

        grid[i][j]=0;

        while(!q.empty()){

            int row=q.front().first;
            int col=q.front().second;

            q.pop();

            for(auto &dir:directions){

                int new_i=row+dir[0];
                int new_j=col+dir[1];

                if(new_i>=0 &&
                   new_i<m &&
                   new_j>=0 &&
                   new_j<n &&
                   grid[new_i][new_j]==1){

                    grid[new_i][new_j]=0;

                    q.push({new_i,new_j});
                }
            }
        }
    }

    int cntOnes(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){

            if(grid[i][0]==1){
                bfs(i,0,m,n,grid);
            }

            if(grid[i][n-1]==1){
                bfs(i,n-1,m,n,grid);
            }
        }

        for(int j=1;j<n-1;j++){

            if(grid[0][j]==1){
                bfs(0,j,m,n,grid);
            }

            if(grid[m-1][j]==1){
                bfs(m-1,j,m,n,grid);
            }
        }

        int ones=0;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    ones++;
                }
            }
        }

        return ones;
    }
};


class Solution {
  public:

    vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};

    void dfs(int i,int j,int m,int n,
             vector<vector<int>>&grid){

        stack<pair<int,int>>st;

        st.push({i,j});

        grid[i][j]=0;

        while(!st.empty()){

            int row=st.top().first;
            int col=st.top().second;

            st.pop();

            for(auto &dir:directions){

                int new_i=row+dir[0];
                int new_j=col+dir[1];

                if(new_i>=0 &&
                   new_i<m &&
                   new_j>=0 &&
                   new_j<n &&
                   grid[new_i][new_j]==1){

                    grid[new_i][new_j]=0;

                    st.push({new_i,new_j});
                }
            }
        }
    }

    int cntOnes(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){

            if(grid[i][0]==1){
                dfs(i,0,m,n,grid);
            }

            if(grid[i][n-1]==1){
                dfs(i,n-1,m,n,grid);
            }
        }

        for(int j=1;j<n-1;j++){

            if(grid[0][j]==1){
                dfs(0,j,m,n,grid);
            }

            if(grid[m-1][j]==1){
                dfs(m-1,j,m,n,grid);
            }
        }

        int ones=0;

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    ones++;
                }
            }
        }

        return ones;
    }
};


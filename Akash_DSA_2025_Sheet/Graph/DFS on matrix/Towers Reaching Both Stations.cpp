
class Solution {
  public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<bool>>&vis){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && mat[ni][nj]>=mat[i][j]){
                dfs(ni,nj,n,m,mat,vis);
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> P(n,vector<bool>(m,false));
        vector<vector<bool>> Q(n,vector<bool>(m,false));
        // Top boundary
        for(int j=0;j<m;j++){
            if(!P[0][j])
                dfs(0,j,n,m,mat,P);
        }
        // Left boundary
        for(int i=0;i<n;i++){
            if(!P[i][0])
                dfs(i,0,n,m,mat,P);
        }
        // Bottom boundary
        for(int j=0;j<m;j++){
            if(!Q[n-1][j])
                dfs(n-1,j,n,m,mat,Q);
        }
        // Right boundary
        for(int i=0;i<n;i++){
            if(!Q[i][m-1])
                dfs(i,m-1,n,m,mat,Q);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(P[i][j] && Q[i][j]) ans++;
            }
        }
        return ans;
    }
};



class Solution {
  public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void dfs(int i,int j,int n,int m,vector<vector<int>>&mat,vector<vector<int>>&vis){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] &&
               mat[ni][nj]>=mat[i][j]){
                dfs(ni,nj,n,m,mat,vis);
            }
        }
    }
    int countCoordinates(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> P(n,vector<int>(m,0));
        vector<vector<int>> Q(n,vector<int>(m,0));
        // Top boundary
        for(int j=0;j<m;j++){
            if(!P[0][j])
                dfs(0,j,n,m,mat,P);
        }
        // Left boundary
        for(int i=0;i<n;i++){
            if(!P[i][0])
                dfs(i,0,n,m,mat,P);
        }
        // Bottom boundary
        for(int j=0;j<m;j++){
            if(!Q[n-1][j])
                dfs(n-1,j,n,m,mat,Q);
        }
        // Right boundary
        for(int i=0;i<n;i++){
            if(!Q[i][m-1])
                dfs(i,m-1,n,m,mat,Q);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(P[i][j] && Q[i][j]) ans++;
            }
        }
        return ans;
    }
};



// Why reverse DFS works?

// Original signal movement:

// Current -> Next
// if(next <= current)

// Example:
// 5 -> 4 -> 2

// Instead of checking every tower individually, start from the stations and move in reverse.
// Reverse condition:
// mat[ni][nj] >= mat[i][j]

// Example:
// 2 <- 4 <- 5
// If reverse DFS can reach a cell, then that cell can send its signal to the station.




// First understand what DFS does

// Suppose we are at cell

// (2,2)

// We want to visit all 4 neighbors.

//       Up
//        |
// Left --X-- Right
//        |
//      Down

// So we write

// for(int k=0;k<4;k++){

//     int ni=i+dx[k];
//     int nj=j+dy[k];

//     dfs(ni,nj);
// }

// Now let's see what happens.

// Example

// Suppose matrix is

// 1 2 3
// 4 5 6
// 7 8 9

// Current cell

// (i,j)=(0,0)

// Neighbors become

// Down  -> (1,0)
// Right -> (0,1)
// Up    -> (-1,0)
// Left  -> (0,-1)

// Notice

// (-1,0)
// (0,-1)

// do not exist.

// Still our loop calls

// dfs(-1,0);
// dfs(0,-1);

// These are invalid.

// So DFS must immediately reject them.

// Hence

// void dfs(int i,int j){

//     if(i<0 || i>=n || j<0 || j>=m)
//         return;

//     ...
// }

// This is why Rule 1 exists.

// Rule 1 (Base Case)
// We call DFS on every neighbor.
// dfs(1,0)
// dfs(0,1)
// dfs(-1,0)
// dfs(0,-1)

// Some are invalid.

// Therefore DFS must check

// Am I valid?

// like this

// if(i<0 || i>=n || j<0 || j>=m)
//     return;

// This is called a guard.

// It protects the function.

// Flow
// dfs(0,0)

// ↓

// dfs(1,0) ✔

// ↓

// works

// -------------------

// dfs(-1,0)

// ↓

// i<0

// ↓

// return immediately

// Nothing crashes.

// Rule 2

// Instead of calling DFS on every neighbor, suppose we first check whether the neighbor is valid.

// Current

//       X

// Instead of

// dfs(up)
// dfs(left)
// dfs(right)
// dfs(down)

// we do

// if(valid)
//     dfs(...)

// Example

// for(int k=0;k<4;k++){

//     int ni=i+dx[k];
//     int nj=j+dy[k];

//     if(ni>=0 && ni<n &&
//        nj>=0 && nj<m){

//         dfs(ni,nj);
//     }
// }

// Now

// dfs(-1,0)

// is never called.

// Only

// dfs(1,0)
// dfs(0,1)

// are called.
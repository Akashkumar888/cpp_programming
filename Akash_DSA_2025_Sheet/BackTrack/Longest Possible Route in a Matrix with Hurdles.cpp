
class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dfs(int i,int j,int n,int m,int endRow,int endCol,vector<vector<int>>& mat,vector<vector<bool>>& visited){
        // Invalid cell
        if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==0 || visited[i][j]) return -1;

        // Destination reached
        if(i==endRow && j==endCol) return 0;

        visited[i][j]=true;
        int ans=-1;

        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            int value=dfs(ni,nj,n,m,endRow,endCol,mat,visited);

            if(value!=-1){
                ans=max(ans,1+value);
            }
        }
        visited[i][j]=false;
        return ans;
    }

    int longestPath(vector<vector<int>>& mat,int xs,int ys,int xd,int yd) {

        int n=mat.size();
        int m=mat[0].size();

        if(mat[xs][ys]==0 || mat[xd][yd]==0) return -1;

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        return dfs(xs,ys,n,m,xd,yd,mat,visited);
    }
};


First understand what DFS does

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
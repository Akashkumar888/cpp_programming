
class Solution {
public:
vector<vector<int>>directions{{1,0},{0,1},{0,-1},{-1,0}};
void dfs(int i,int j,int n,int m,vector<vector<char>>&board){
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='Z' || board[i][j]=='X'){
        return;
    }
    board[i][j]='Z';
    for(auto &dir:directions){
        int new_i=i+dir[0];
        int new_j=j+dir[1];
        dfs(new_i,new_j,n,m,board);
    }
}
    void solve(vector<vector<char>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
         for(int i=0;i<n;i++){
           if(mat[i][0]=='O'){
               dfs(i,0,n,m,mat);
           }
           if(mat[i][m-1]=='O'){
               dfs(i,m-1,n,m,mat);
           }
        }
        for(int j=1;j<m-1;j++){
            if(mat[0][j]=='O'){
                dfs(0,j,n,m,mat);
            }
            if(mat[n-1][j]=='O'){
                dfs(n-1,j,n,m,mat);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='Z'){
                    mat[i][j]='O';
                }
                else if(mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return ;
    }
};
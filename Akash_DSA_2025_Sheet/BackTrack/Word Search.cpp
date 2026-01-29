
class Solution {
  public:
  int dx[4]={1,0,0,-1};
  int dy[4]={0,1,-1,0};
  bool dfs(int i,int j,int idx,int n,int m,vector<vector<char>> &mat,string &word){
      if(idx == word.size()) return true;  // word fully matched
      if(i<0 || j<0 || i>=n || j>=m ||mat[i][j]=='$')return false;
      if(mat[i][j]!=word[idx])return false;
      char temp=mat[i][j];
      mat[i][j]='$';
      for(int k=0;k<4;k++){
          int ni=i+dx[k];
          int nj=j+dy[k];
          if(dfs(ni,nj,idx+1,n,m,mat,word))return true;
      }
      mat[i][j]=temp;
      
      return false;
  }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0] && dfs(i,j,0,n,m,mat,word))return true;
            }
        }
        return false;
    }
};

// Let:
// R = number of rows
// C = number of columns
// L = length of the word

// ⏱️ Time Complexity
// In the worst case, from every cell we may explore 4 directions for each character of the word.
// So the upper bound is:

// O(R×C×4^L)
// Explanation:
// We try to start from every cell → R * C
// For each start, DFS explores up to 4 choices at each step → 4^L
// Word length controls recursion depth
// In practice it’s a bit less because:
// We mark visited cells
// Branching reduces after the first move
// But worst-case remains O(R * C * 4^L).

// 🧠 Space Complexity
// Extra space comes from recursion stack: O(L)


class Solution {
public:
vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};
// backtrack 
bool dfs(int i,int j,int m,int n,vector<vector<char>>& board,int k,string &word){
if(k==word.size())return true;
if(i<0 || j<0 || i>=m || j>=n || board[i][j]=='#') return false;
if(board[i][j]!=word[k])return false;
char temp=board[i][j];
board[i][j]='#';
for(auto &dir:directions){
    int new_i=i+dir[0];
    int new_j=j+dir[1];
    if( dfs(new_i,new_j,m,n,board,k+1,word) ) return true;
}
board[i][j]=temp;

return false;
}
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==word[0] && dfs(i,j,m,n,board,0,word)){
             return true;
            }
        }
    }
    return false;
    }
};
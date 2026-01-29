
class Solution {
public:
bool magic(int r,int c,vector<vector<int>>& grid){
    // 1 to 9
    unordered_set<int>st;
    for(int i=r;i<r+3;i++){
        for(int j=c;j<c+3;j++){
            int num=grid[i][j];
            if(num<1 || num>9 || st.find(num)!=st.end()){
                return false;
            }
            else{
                st.insert(num);
            }
        }
    }
        // rowsum
        int rowsum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int i=r;i<r+3;i++){
            if(grid[i][c] + grid[i][c+1] +grid[i][c+2] != rowsum){
                return false;
            }
        }
       // colsum
       for(int j=c;j<c+3;j++){
        if(grid[r][j] + grid[r+1][j] + grid[r+2][j]!=rowsum){
            return false;
        }
       }
      // diagonal
      if(grid[r][c] + grid[r+1][c+1] +grid[r+2][c+2]!=rowsum) return false;

    // antidiagonal
      if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c]!=rowsum) return false;

      return true;

}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
              if(magic(i,j,grid)){
                count++;
              }
            }
        }
        return count;
    }
};
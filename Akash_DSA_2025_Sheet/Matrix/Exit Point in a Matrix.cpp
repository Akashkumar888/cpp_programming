
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        int dir=1;
        int i=0,j=0;
        while(i>=0&&j>=0&&i<n&&j<m){
            if(matrix[i][j]==1){
                matrix[i][j]=0;
                dir=(dir%4)+1;
            }
            if(dir==1) j++;
            else if(dir==2) i++;
            else if(dir==3) j--;
            else i--;
        }
           if(dir==1) j--;
            else if(dir==2) i--;
            else if(dir==3) j++;
            else i++;
            
            return  {i,j};
    }
};



class Solution {
  public:
    vector<int> exitPoint(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int row = 0;
        int col = 0;
        int dir = 0; // 0=Right,1=Down,2=Left,3=Up

        while(row >= 0 && row < n && col >= 0 && col < m){
            if(mat[row][col] == 1){
                dir = (dir + 1) % 4; // direction to the right (clockwise turn)
                mat[row][col] = 0;
            }
            if(dir == 0){
                col++;
            }
            else if(dir == 1){
                row++;
            }
            else if(dir == 2){
                col--;
            }
            else{
                row--;
            }
        }
        
        if(row < 0) row++;
        else if(row == n) row--;
        else if(col < 0) col++;
        else if(col == m) col--;

        return {row, col};
    }
};


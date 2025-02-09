
class Solution {
  public:
      // Sort Anti-diagonal in descending order
      void f1(int i,int j,int &n,vector<vector<int>>&grid){
        vector<int>ans;
        int x=i,y=j;
        while(x<n&&y<n){
            ans.push_back(grid[x][y]);
            x++;y++;
        }
        sort(ans.rbegin(),ans.rend());
        int idx=0;
        x=i,y=j;
        while(x<n && y<n){
        grid[x][y]=ans[idx++];
            x++,y++;
        }
    }
    void f2(int i,int j,int &n,vector<vector<int>>&grid){
        vector<int>ans;
        int x=i,y=j;
        while(x<n&&y<n){
            ans.push_back(grid[x][y]);
            x++;y++;
        }
        sort(ans.begin(),ans.end());
        int idx=0;
        x=i,y=j;
        while(x<n && y<n){
        grid[x][y]=ans[idx++];
            x++,y++;
        }
    }
      void f3(int i, int j, int &n, vector<vector<int>>& grid) {
          vector<int> ans;
          int x = i, y = j;
          while (x < n && y >= 0) {
              ans.push_back(grid[x][y]);
              x++, y--;
          }
          sort(ans.rbegin(), ans.rend());
          int idx = 0;
          x = i, y = j;
          while (x < n && y >= 0) {
              grid[x][y] = ans[idx++];
              x++, y--;
          }
      }
  
      // Sort Anti-diagonal in ascending order
      void f4(int i, int j, int &n, vector<vector<int>>& grid) {
          vector<int> ans;
          int x = i, y = j;
          while (x < n && y >= 0) {
              ans.push_back(grid[x][y]);
              x++, y--;
          }
          sort(ans.begin(), ans.end());
          int idx = 0;
          x = i, y = j;
          while (x < n && y >= 0) {
              grid[x][y] = ans[idx++];
              x++, y--;
          }
      }
  
      vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
          int n = grid.size();
  
          // Sorting main diagonals
          for (int i = 0; i < n; i++) f1(i, 0, n, grid);  // Descending
          for (int j = 1; j < n; j++) f2(0, j, n, grid);  // Ascending
  
          // Sorting anti-diagonals
          for (int i = 0; i < n; i++) f3(i, n - 1, n, grid); // Descending
          for (int j = n - 2; j >= 0; j--) f4(0, j, n, grid); // Ascending
  
          return grid;
      }
  };
  

class Solution {
  public:
  void solve(int i,int j,int n,vector<vector<int>>&mat,string &str,vector<string>&result){
      if(i<0 || j<0 || i>=n || j>=n || mat[i][j]==0)return;
      if(i==n-1 && j==n-1){
          result.push_back(str);
          return;
      }
      // backtrack and for avoid cycle 
      int cellVal=mat[i][j];
      mat[i][j]=0;
      
      //'D'(down)
      str.push_back('D');
      solve(i+1,j,n,mat,str,result);
      str.pop_back();
      
      //'L'(left),
      str.push_back('L');
      solve(i,j-1,n,mat,str,result);
      str.pop_back();
      
      //'R'(right)
      str.push_back('R');
      solve(i,j+1,n,mat,str,result);
      str.pop_back();
      
      //'U'(up),
      str.push_back('U'); //only push char 
      solve(i-1,j,n,mat,str,result);
      str.pop_back();
      
      mat[i][j]=cellVal;
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        // Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. 
        //The rat's goal is to reach the destination at position (n-1, n-1). 
        //The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).
        // 0: A blocked cell through which the rat cannot travel.
       // 1: A free cell that the rat can pass through.
    //   lexicographically smallest order. then 'D' 'L' 'R' 'U'
        int n=maze.size();
        vector<string>result;
        string str="";
        solve(0,0,n,maze,str,result);
        return result;
    }
};


// Time Complexity
// In the worst case:
// All cells are free (1), so at each cell you try 4 directions.
// Maximum depth = n*n (all cells visited at most once per path).
// So the worst-case time complexity is exponential: O(4n2)
// ⚠️ This is expected for backtracking in a maze with all open cells.
// Practically, the complexity is much smaller because blocked cells and visited cells prune the search.

// Space Complexity
// Recursion stack:
// Maximum recursion depth = n*n (in case the path visits all cells)
// Space = O(n^2)
// Temporary path string str:
// Max length = 2n-1 (for a path from (0,0) to (n-1,n-1))
// So space per recursion = O(n) (negligible compared to recursion stack)
// Result storage:
// If there are k paths, each of max length 2n-1
// Space = O(k*n)
// ✅ Overall space complexity = O(n^2 + k*n)

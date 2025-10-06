
class Solution {
  public:
  // vector<vector<int>>directions{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
  // one horizontal , two vertical and one vertical , two horizontal moves
//   A knight moves in 8 possible L-shapes:
// (±2, ±1), (±1, ±2)
// i.e., two steps in one direction, one step perpendicular.
  int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
  int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
  void solve(int i,int j,int step,int n,vector<vector<int>>&visited,vector<vector<int>>&result,bool &found){
    if(found) return; // stop if already found solution
    // do 
    visited[i][j] = 1;
    result[i][j] = step;

    if(step == n*n) { 
        found = true;
        return;
    }
      for(int k=0;k<8;k++){
         int new_i=i+dx[k]; 
         int new_j=j+dy[k];
         // visite check kr rahe hai pahle index to dekh lo valid hai ki nhi then no need to above base case 
         //   if(i<0 || j<0 || i>=n ||j>=n||visited[i][j])return;
         if(new_i>=0 && new_j>=0 && new_i<n && new_j<n && !visited[new_i][new_j]){ 
             solve(new_i,new_j,step+1,n,visited,result,found); // explore
         }
      }
      // undo 
      if(!found) { // backtrack if path failed
        visited[i][j] = 0;
        result[i][j] = -1;
    }
  }
    vector<vector<int>> knightTour(int n) {
        // code here

        // 4. Common Chessboard Problems on LeetCode / GFG
        // Knight’s Tour (Backtracking)
        // N-Queens Problem (place queens so no two attack each other).
        // Rat in a Maze (pathfinding).
        // Word Search on Grid (DFS backtracking).
        // Knight’s Minimum Steps to Reach Target (BFS shortest path).
        // Unique Paths / DP Grid Problems.
        // Minimum Knight Moves (LeetCode 1197) → BFS shortest path from source to target.
        // Knight’s Minimum Steps (BFS problem) → shortest path, not tour.
        // Knight Probability (DP) → probability knight stays on board after k moves.
        // Knight’s Tour (Backtracking + Warnsdorff) → Hamiltonian path problem.

        vector<vector<int>> visited(n, vector<int>(n,0));
        vector<vector<int>> result(n, vector<int>(n,-1));
        bool found = false;
        solve(0,0,1,n,visited,result,found);
        if(!found) return {{-1}};
        return result;
    }
};

// So your code is not logically wrong, but without Warnsdorff’s Rule, it fails for n=5.
// same code with heuristic fix
// Warnsdorff’s heuristic (rule) is a greedy strategy used to solve the Knight’s Tour problem efficiently.

// When a knight is at some position on the chessboard:
// The knight has up to 8 possible moves.
// Some moves lead to dead ends quickly (no way to visit all squares).
// To avoid dead ends, we always move to the square that has the fewest onward moves (minimum degree of freedom).
// This ensures that we leave the squares with many options for later, reducing the chance of getting stuck.
// 🛠️ How It Works Step-by-Step
// From the current square (i, j), generate all possible knight moves.
// For each move (ni, nj), count how many further moves are possible from (ni, nj).
// That’s countMoves(ni, nj).
// Sort all moves by their degree (onward moves).
// Pick the move with the smallest degree first.
// Continue recursively until:
// Either all squares are visited ✅
// Or we get stuck ❌ → backtrack.

class Solution {
public:
    // Knight moves (clockwise order)
    int dx[8] = {2,1,-1,-2,-2,-1,1,2};
    int dy[8] = {1,2,2,1,-1,-2,-2,-1};
    // Count available onward moves (degree) from (i,j)
    int countMoves(int i, int j, int n, vector<vector<int>>& visited) {
        int cnt = 0;
        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj]){
                cnt++;
            }
        }
        return cnt;
    }
    // Recursive backtracking + Warnsdorff heuristic
    void solve(int i, int j, int step, int n,vector<vector<int>>& visited,vector<vector<int>>& result,bool &found) {
        if (found) return;               // stop if already found
        visited[i][j] = 1;                   // mark visited
        result[i][j] = step;                // store step (0-based)

        if (step == n * n - 1) {         // all cells visited
            found = true;
            return;
        }

        // Collect valid next moves with their degree
        vector<pair<int,int>> moves; // {degree, moveIndex}
        for (int k = 0; k < 8; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < n && !visited[ni][nj]) {
                int deg = countMoves(ni, nj, n, visited);
                // moves.emplace_back(deg, k);
                // moves.push_back(std::make_pair(deg, k));
                moves.push_back({deg,k});
            }
        }

        // Warnsdorff: sort by smallest degree first
        sort(moves.begin(), moves.end()); // heuristic: fewest onward moves first

        // Explore in sorted order
        for (auto &p : moves) {
            int k = p.second;
            int ni = i + dx[k];
            int nj = j + dy[k];
            solve(ni, nj, step + 1, n, visited, result, found);
            if (found) return; // bubble up success immediately
        }

        // backtrack if this path failed
        if (!found) {
            visited[i][j] = 0;
            result[i][j] = -1;
        }
    }

    vector<vector<int>> knightTour(int n) {
        if (n <= 0) return {{-1}};
        // Trivial case n == 1
        if (n == 1) return {{0}};
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<vector<int>> result(n, vector<int>(n, -1));
        bool found = false;

        // start from (0,0) with step = 0 (0-based)
        solve(0, 0, 0, n, visited, result, found);
        if (!found) return {{-1}};
        return result;
    }
};






// dp problem on knight 8 moves 
class Solution {
public:
// vector<vector<int>>directions{{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
//   A knight moves in 8 possible L-shapes:
// one horizontal , two vertical and one vertical , two horizontal moves
// (±2, ±1), (±1, ±2)
// i.e., two steps in one direction, one step perpendicular.
  int dx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
  int dy[8] = {1, -1, 1, -1, 2, 2, -2, -2};
double solve(int n,int i,int j,int k,vector<vector<vector<double>>>&dp){
      if(i<0||j<0||i>=n||j>=n)return 0.0;
      if (k == 0) return 1.0;
      if (dp[i][j][k] != -1.0) return dp[i][j][k];
      double ans=0.0;
      for(int m=0;m<8;m++){
        int new_i=i+dx[m];
        int new_j=j+dy[m];
        ans += solve(n,new_i,new_j,k-1,dp)*(0.125);
      }
return dp[i][j][k]=ans;
}
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1.0)));
        return solve(n,row,column,k,dp);
    }
};
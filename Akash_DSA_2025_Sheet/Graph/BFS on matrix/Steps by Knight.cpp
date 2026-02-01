
class Solution {
  public:
  //A knight moves in 8 possible directions. Since each move costs the same, we use BFS to find the minimum steps.
// Board size: n x n
// Positions are 1-based → convert to 0-based
// Use:
// queue<pair<int,int>>
// visited[][]
// dist[][]
// BFS until we reach target
typedef pair<int,int> P;
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        // knight moves
        int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

        // convert to 0-based indexing
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, -1));// when element push in queue then use dist 

        queue<P> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        dist[sx][sy] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == tx && y == ty) return dist[x][y];

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return -1;
    }
};



class Solution {
  public:
  //A knight moves in 8 possible directions. Since each move costs the same, we use BFS to find the minimum steps.
// Board size: n x n
// Positions are 1-based → convert to 0-based
// Use:
// queue<pair<int,int>>
// visited[][]
// dist[][]
// BFS until we reach target
typedef pair<int,int> P;
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        // knight moves
        int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

        // convert to 0-based indexing
        int sx = knightPos[0] - 1;
        int sy = knightPos[1] - 1;
        int tx = targetPos[0] - 1;
        int ty = targetPos[1] - 1;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<vector<int>> dist(n, vector<int>(n, -1));// when element push in queue then use dist 
        queue<P> q;
        q.push({sx, sy});
        visited[sx][sy] = true;
        dist[sx][sy] = 0;
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
        
                if (x == tx && y == ty)return step;
        
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
        
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
            step++;   // increment ONCE per level
        }
        return -1;
    }
};


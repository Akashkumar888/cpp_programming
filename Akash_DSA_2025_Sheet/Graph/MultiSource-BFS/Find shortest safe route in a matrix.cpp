
class Solution {
  public:
    typedef pair<int,int> P;

    int findShortestPath(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};

        // Step 1: mark unsafe cells
        vector<vector<bool>> blocked(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            if (mat[i][j] == 0) {
              blocked[i][j] = true;
              for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < r && nj >= 0 && nj < c)
                        blocked[ni][nj] = true;
                      }
                    }
                  }
                }
                
                // Because you start BFS from multiple source nodes at the same time:
                // Every safe cell in the first column is a source
                // All are pushed into the queue before BFS starts
                // BFS expands from all of them simultaneously

// ➡️ This exactly matches the definition of multi-source BFS.
        // Step 2: BFS
        queue<P> q;
        vector<vector<int>> dist(r, vector<int>(c, -1));

        // push all safe cells in first column
        for (int i = 0; i < r; i++) {
            if (!blocked[i][0]) {
                q.push({i, 0});// multiple starting points
                dist[i][0] = 1;   // path length starts from 1
            }
        }

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (y == c - 1)return dist[x][y];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
                    !blocked[nx][ny] && dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};


class Solution {
public:

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int shortestPath(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        // safe[i][j] = true if cell can be used
        vector<vector<bool>> safe(
            n, vector<bool>(m, true)
        );

        // --------------------------------
        // STEP 1: Mark unsafe cells
        // --------------------------------

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (mat[i][j] == 0) {

                    // Landmine itself
                    safe[i][j] = false;

                    // Four neighbours
                    for (int k = 0; k < 4; k++) {

                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if (ni >= 0 && ni < n &&
                            nj >= 0 && nj < m) {

                            safe[ni][nj] = false;
                        }
                    }
                }
            }
        }

        // --------------------------------
        // STEP 2: Multi-source BFS
        // --------------------------------

        queue<pair<int, int>> q;

        // IMPORTANT:
        // Distance means number of cells in route,
        // so starting cell has distance = 1.
        vector<vector<int>> dist(
            n, vector<int>(m, -1)
        );

        // All safe cells in first column
        for (int i = 0; i < n; i++) {

            if (safe[i][0]) {

                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        // --------------------------------
        // STEP 3: BFS
        // --------------------------------

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            // Reached last column
            if (y == m - 1) {
                return dist[x][y];
            }

            for (int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    safe[nx][ny] &&
                    dist[nx][ny] == -1) {

                    dist[nx][ny] = dist[x][y] + 1;

                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};
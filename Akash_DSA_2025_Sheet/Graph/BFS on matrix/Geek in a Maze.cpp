
class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Starting cell is obstacle
        if (mat[r][c] == '#') return 0;

        // dist[i][j] = minimum upward moves
        // required to reach cell (i,j)
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        deque<pair<int,int>> dq;

        dist[r][c] = 0;
        dq.push_front({r, c});

        // Directions
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};


        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                // Outside matrix
                if (nx < 0 || nx >= n ||
                    ny < 0 || ny >= m) {
                    continue;
                }

                // Obstacle
                if (mat[nx][ny] == '#') {
                    continue;
                }

                // Moving UP costs 1
                // All other directions cost 0
                int cost = 0;
                if (nx < x) {
                    cost = 1;
                }

                if (dist[x][y] + cost < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + cost;
                    if (cost == 0) {
                        dq.push_front({nx, ny});
                    }
                    else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '#') {
                    continue;
                }

                if (dist[i][j] == INT_MAX) {
                    continue;
                }
                int upMoves = dist[i][j];
                // down - up = currentRow - startingRow
                int downMoves = upMoves + (i - r);


                if (upMoves <= u && downMoves <= d) {
                    count++;
                }
            }
        }
        return count;
    }
};
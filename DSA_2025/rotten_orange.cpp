
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
typedef pair<int, pair<int, int>> P; // {time, {row, col}}

int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // Fixed bool vector
    queue<P> q;

    // Push all initially rotten oranges into queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int time = 0;
    
    // BFS traversal
    while (!q.empty()) {
        auto [tm, cell] = q.front();
        q.pop();
        int i = cell.first, j = cell.second;
        time = max(time, tm);

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                !visited[new_i][new_j] && mat[new_i][new_j] == 1) {
                q.push({tm + 1, {new_i, new_j}});
                visited[new_i][new_j] = true;
                mat[new_i][new_j] = 2; // Mark as rotten
            }
        }
    }

    // Check if any fresh orange remains
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) return -1; // If fresh orange remains
        }
    }

    return time;
}

int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Minimum time to rot all oranges: " << orangesRotting(grid) << endl;
    return 0;
}

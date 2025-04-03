#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> directions = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
typedef pair<int, pair<int, int>> P;

int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<P> q;

    // Enqueue all initially rotten oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                q.push({0, {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int time = 0;
    while (!q.empty()) {
        int tm = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        time = max(tm, time);

        for (auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && 
                !visited[new_i][new_j] && mat[new_i][new_j] == 1) {
                q.push({tm + 1, {new_i, new_j}});
                visited[new_i][new_j] = true;
            }
        }
    }

    // Check if any fresh orange is left
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1 && !visited[i][j]) return -1;
        }
    }
    return time;
}
